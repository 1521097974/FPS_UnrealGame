// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "FPS_AIController.generated.h"



UCLASS()
class TENCENT_FPS_API AFPS_AIController : public AAIController
{
	GENERATED_BODY()

		virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = AI)
		UBehaviorTree* BehaviorTree;
};
