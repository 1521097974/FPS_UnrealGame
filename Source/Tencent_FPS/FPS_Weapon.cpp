// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Weapon.h"
#include "FPSCharacter.h"
#include <Components/SphereComponent.h>
#include "Kismet/GameplayStatics.h"
#include "FPSProjectile.h"

AFPS_Weapon::AFPS_Weapon()
{
	Gun = CreateDefaultSubobject<USkeletalMeshComponent>("Gun");
	Gun->SetupAttachment(RootComponent);
	Gun->CastShadow = false;
	Gun->bCastDynamicShadow = false;
	Gun->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));

	MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("VR_MuzzleLocation"));
	MuzzleLocation->SetupAttachment(Gun);

	SphereCollision = CreateDefaultSubobject<USphereComponent>("Collision");
	SphereCollision->SetupAttachment(Gun);
	//SphereCollision->OnComponentBeginOverlap.AddDynamic(this,&AFPS_Weapon::OnOverlayBegin);

	
}
//检测碰撞
/*
void AFPS_Weapon::OnOverlayBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AFPSCharacter* player = Cast<AFPSCharacter>(OtherActor);
	//如果角色手里没有武器
	if (player && !player->HandWeapon)
	{
		player->EquipWeapon(this);
	}
}
*/
/*
void AFPS_Weapon::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	AFPSCharacter* player = Cast<AFPSCharacter>(OtherActor);
	//如果角色手里没有武器
	if (player&&!player->HandWeapon)
	{
		player->EquipWeapon(this);
	}
}
*/
void AFPS_Weapon::Fire()
{
		AActor* MyOwner = GetOwner();
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
					Projectile->SetOwner(MyOwner);
					// 设置发射物的初始轨迹。
					FVector LaunchDirection = SpawnRotation.Vector();
					Projectile->FireInDirection(LaunchDirection);
				}
			}

		}
		Mut_FireSound();
		Mut_FireAnimation();
}

void AFPS_Weapon::Grenade_Fire()
{
	AActor* MyOwner = GetOwner();
	if (Grenade_ProjectileClass)
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

			AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(Grenade_ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
			if (Projectile)
			{
				Projectile->SetOwner(MyOwner);
				// 设置发射物的初始轨迹。
				FVector LaunchDirection = SpawnRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}

	}
	Mut_FireSound();
	Mut_FireAnimation();
}

void AFPS_Weapon::Mut_FireSound_Implementation()
{
	if (FireSound != nullptr)//声音
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, MuzzleLocation->GetComponentLocation());
	}
}

void AFPS_Weapon::Mut_FireAnimation_Implementation()
{
	AActor* MyOwner = GetOwner();
	if (FireAnimation != nullptr)//动画
	{

		AFPSCharacter* m = Cast<AFPSCharacter>(MyOwner);
		if (m)
		{

			UAnimInstance* AnimInstance = m->FPSMesh->GetAnimInstance();
			if (AnimInstance != nullptr)
			{
				AnimInstance->Montage_Play(FireAnimation, 1.f);
			}
		}
	}
}