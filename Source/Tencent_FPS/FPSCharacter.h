// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

class USkeletalMeshComponent;
class UCameraComponent;
class USceneComponent;
class USoundBase;
class UAnimMontage;
class AFPS_Weapon;
class UFPS_AttributeComponent;

UCLASS()
class TENCENT_FPS_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, Category = Mesh)
	USkeletalMeshComponent* VR_Gun;
public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Ҫ���ɵķ������ࡣ
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float value);
	UFUNCTION()
		void MoveRight(float value);
	UFUNCTION()
		void StartJump();
	UFUNCTION()
		void StopJump();
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "FPS_BlueprintFunc")
		void Fire();
	UFUNCTION(Server, Reliable, BlueprintCallable, Category = "FPS_BlueprintFunc")
		void Grenade_Fire();
	UFUNCTION(BlueprintCallable, Category = "FPS_BlueprintFunc")
		void EquipWeapon(AFPS_ItemBase *Weapon);
	UFUNCTION(BlueprintCallable, Category = "FPS_BlueprintFunc")
		void Damage(float damage);
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCameraComponent* FPSCameraComponent;
	// ��һ�˳������壨�ֱۣ�
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		AFPS_Weapon* CurrentWeapon;
	//��׼
	UFUNCTION(BlueprintCallable, Category = "FPS_BlueprintFunc")
		void Zoom() { bWantsToZoom = bWantsToZoom ? false : true; if (bWantsToZoom) { TakeAim = true; } else { TakeAim = false; } }
	
	//��׼����
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = player)
		float ZoomedFOV;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = player, meta = (ClampMin = 0.0, ClampMax = 100))
		float ZoomInterSpeed;
	//Ѫ��������
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Attribute);
	float Health = 1.0f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Attribute);
	float Armor = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = player)
	bool HandWeapon = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = player)
	bool bWantsToZoom =false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = player)
	bool TakeAim = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UFPS_AttributeComponent* AttributeComponent;
};
