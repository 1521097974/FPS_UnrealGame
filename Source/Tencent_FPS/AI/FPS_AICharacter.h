// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPS_AICharacter.generated.h"

UCLASS()
class TENCENT_FPS_API AFPS_AICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPS_AICharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UPROPERTY(VisibleDefaultsOnly, Category = Position)
	USceneComponent* Muzzle;
	UPROPERTY(VisibleDefaultsOnly, Category = Position)
	USkeletalMeshComponent* Gun;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI_Attribute);
	float Health = 1.0f;
};
