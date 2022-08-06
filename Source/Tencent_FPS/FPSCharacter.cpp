// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "XRMotionControllerBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/InputSettings.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
	
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//������һ�˳���������
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	check(FPSCameraComponent != nullptr);
	//��������ӵ����������
	FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
	// ������������Ը����۾��Ϸ���λ�á�
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// ����Pawn�����������ת��
	FPSCameraComponent->bUsePawnControlRotation = true;

	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	check(FPSMesh != nullptr);
	FPSMesh->SetOnlyOwnerSee(true);
	FPSMesh->SetupAttachment(FPSCameraComponent);
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	VR_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("VR_Gun"));
	VR_Gun->SetOnlyOwnerSee(false);
	VR_Gun->bCastDynamicShadow=false;
	VR_Gun->CastShadow = false;
	VR_Gun->SetupAttachment(RootComponent);
	//VR_Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("VR_MuzzleLocation"));
	MuzzleLocation->SetupAttachment(VR_Gun);
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	VR_Gun->AttachToComponent(FPSMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	check(GEngine != nullptr);
	// ��ʾ������Ϣ���롣 
	// -1"��"ֵ�������Է�ֹ���»�ˢ����Ϣ��
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using FPSCharacter."));

}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//�ƶ�
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
	//�ӽ�
	#if !PLATFORM_ANDROID
	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
	#endif
	//��Ծ
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AFPSCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);
	//��ǹ
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);
}

void AFPSCharacter::MoveForward(float value)
{
	//ǰ��
	if (value != 0.0f)
		AddMovementInput(GetActorForwardVector(), value);
}

void AFPSCharacter::MoveRight(float value)
{
	//����
	if (value != 0.0f)
		AddMovementInput(GetActorRightVector(), value);
}

void AFPSCharacter::StartJump()
{
	bPressedJump = true;
}
void AFPSCharacter::StopJump()
{
	bPressedJump = false;
}

void AFPSCharacter::Fire()
{
	if (ProjectileClass)
	{
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		const FRotator SpawnRotation = MuzzleLocation->GetComponentRotation();
		const FVector SpawnLocation = MuzzleLocation->GetComponentLocation();

		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
			if (Projectile)
			{
				// ���÷�����ĳ�ʼ�켣��
				FVector LaunchDirection = SpawnRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, MuzzleLocation->GetComponentLocation());
	}
	if (FireAnimation != nullptr)
	{
		UAnimInstance* AnimInstance = FPSMesh->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}
