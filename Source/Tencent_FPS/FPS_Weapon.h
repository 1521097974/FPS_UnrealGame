// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPS_ItemBase.h"
#include "FPS_Weapon.generated.h"

class USphereComponent;
class USoundBase;
class USceneComponent;
class UCameraComponent;

UCLASS()
class TENCENT_FPS_API AFPS_Weapon : public AFPS_ItemBase
{
	GENERATED_BODY()

public:
	AFPS_Weapon();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
		USkeletalMeshComponent* Gun;
	// Ҫ���ɵķ������ࡣ
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> Grenade_ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		UAnimMontage* FireAnimation;

public:
	//virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	//UFUNCTION(Client, Reliable)
	//void Fire();
	//void Fire_Implementation();

	
	UFUNCTION(BlueprintCallable, Category = "FPS_BlueprintFunc")
		void Fire();
	UFUNCTION(BlueprintCallable, Category = "FPS_BlueprintFunc")
		void Grenade_Fire();
	//�ಥ����ͬ��
	UFUNCTION(NetMulticast,Reliable)
		void Mut_FireSound();
	UFUNCTION(NetMulticast,Reliable)
		void Mut_FireAnimation();

	//ǹ��λ��
	UPROPERTY(VisibleDefaultsOnly, Category = Position)
		USceneComponent* MuzzleLocation;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Gameplay)
		int WeaponKind;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Gameplay)
		float FireRate = 0.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Gameplay)
		bool Automation = true;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Gameplay)
		bool Superheating = true;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Gameplay)
		float SuperheatingAmmo = 0.f;
	//UFUNCTION()
		//virtual void OnOverlayBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
