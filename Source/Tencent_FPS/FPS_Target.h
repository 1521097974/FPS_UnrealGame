// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPS_Target.generated.h"

class USphereComponent;

UCLASS()
class TENCENT_FPS_API AFPS_Target : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPS_Target();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly)
		UStaticMeshComponent* TargetMeshComponent;
	//Åö×²Ìå
	UPROPERTY(VisibleDefaultsOnly)
		USphereComponent* CollisionComponent;

	

};
