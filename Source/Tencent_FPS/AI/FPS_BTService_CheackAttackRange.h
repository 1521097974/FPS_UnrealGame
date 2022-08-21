// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "FPS_BTService_CheackAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class TENCENT_FPS_API UFPS_BTService_CheackAttackRange : public UBTService
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(Editanywhere,category = "AI")
	FBlackboardKeySelector AttackRangeKey;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
