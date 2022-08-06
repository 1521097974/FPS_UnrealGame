// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <Components/CapsuleComponent.h>
#include "FPSProjectile.h"
#include <Animation/AnimInstance.h>
#include <Sound/SoundBase.h>
#include "FPSCharacter.generated.h"

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
	UFUNCTION(BlueprintCallable, Category = "FPS_BlueprintFunc")
		void Fire();
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* FPSCameraComponent;
	// ��һ�˳������壨�ֱۣ�������������ҿɼ���
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		USkeletalMeshComponent* FPSMesh;
	// ǹ������������λ�õ�ƫ�ơ�
	UPROPERTY(VisibleDefaultsOnly, Category = Position)
		USceneComponent* MuzzleLocation;
	//��������̫�涯��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		USoundBase* FireSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		UAnimMontage* FireAnimation;
	
};
