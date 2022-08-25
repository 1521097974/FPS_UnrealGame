// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "XRMotionControllerBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/InputSettings.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "FPSProjectile.h"
#include "Animation/AnimInstance.h"
#include "Sound/SoundBase.h"
#include "FPS_Weapon.h"
#include "FPS_ItemBase.h"
#include "FPS_AttributeComponent.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//创建第一人称摄像机组件
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	check(FPSCameraComponent != nullptr);
	//将组件附加到胶囊体组件
	FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));
	// 将摄像机置于略高于眼睛上方的位置。
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// 启用Pawn控制摄像机旋转。
	FPSCameraComponent->bUsePawnControlRotation = true;

	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	check(FPSMesh != nullptr);
	FPSMesh->SetupAttachment(FPSCameraComponent);
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	AttributeComponent = CreateDefaultSubobject<UFPS_AttributeComponent>("AttributeComponent");
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();

	ItemWeapon = GetWorld()->SpawnActor<AFPS_ItemBase>(ItemClass);
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetWeapon)
	{
		
		CurrentWeapon = GetWorld()->SpawnActor<AFPS_Weapon>(ItemWeapon->WeaponClass[WeaponKind]);
		if (CurrentWeapon)
		{
			CurrentWeapon->SetOwner(this);
			CurrentWeapon->AttachToComponent(FPSMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		}
		
		GetWeapon = false;
		HandWeapon = true;
	}
	if (HandWeapon)
	{
		float TargetFOV = bWantsToZoom ? ZoomedFOV : 90.0f;
		float CurrentFOV = FMath::FInterpTo(FPSCameraComponent->FieldOfView, TargetFOV, DeltaTime, ZoomInterSpeed);
		FPSCameraComponent->SetFieldOfView(CurrentFOV);
	}
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//移动
	PlayerInputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
	//视角
	#if !PLATFORM_ANDROID
	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
	#endif
	//跳跃
	PlayerInputComponent->BindAction("Jump",IE_Pressed, this, &AFPSCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::StopJump);
	//开枪
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);
}

void AFPSCharacter::MoveForward(float value)
{
	//前进
	if (value != 0.0f)
		AddMovementInput(GetActorForwardVector(), value);
}
void AFPSCharacter::MoveRight(float value)
{
	//向右
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

void AFPSCharacter::Fire_Implementation()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Fire();
	}
}
void AFPSCharacter::Grenade_Fire_Implementation()
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Grenade_Fire();
	}
}

void AFPSCharacter::EquipWeapon(AFPS_ItemBase* Weapon)
{

	Weapon->AttachToComponent(FPSMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
	WeaponKind = Weapon->GetWeaponKind();
	GetWeapon = true;
}

void AFPSCharacter::Zoom()
{
	bWantsToZoom=bWantsToZoom?false:true;
	
}
