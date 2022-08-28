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
	// 要生成的发射物类。
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AFPSProjectile> ProjectileClass;
	
	//瞄准
	UFUNCTION(BlueprintCallable, Category = "FPS_BlueprintFunc")
		void Zoom();

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
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* FPSCameraComponent;
	// 第一人称网格体（手臂），仅对所属玩家可见。
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		AFPS_Weapon* CurrentWeapon;

	//瞄准属性
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = player)
		float ZoomedFOV;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = player, meta = (ClampMin = 0.0, ClampMax = 100))
		float ZoomInterSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = player)
	bool HandWeapon = false;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = player)
	bool bWantsToZoom =false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UFPS_AttributeComponent* AttributeComponent;
};
