// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FPS_BTTask_RangedAttack.generated.h"

/**
 * 
 */
UCLASS()
class TENCENT_FPS_API UFPS_BTTask_RangedAttack : public UBTTaskNode
{
	GENERATED_BODY()

		virtual EBTNodeResult::Type	ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(Editanywhere, category = "AI")
		TSubclassOf<AActor> ProjectileClass;
};
