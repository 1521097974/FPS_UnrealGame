// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_BTTask_RangedAttack.h"
#include <AIController.h>
#include <GameFramework/Character.h>
#include <BehaviorTree/BlackboardComponent.h>
#include "FPS_AICharacter.h"

EBTNodeResult::Type UFPS_BTTask_RangedAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* Controller = OwnerComp.GetAIOwner();
	if (ensure(Controller))
	{
		AFPS_AICharacter* AIPawn = Cast<AFPS_AICharacter>(Controller->GetPawn());
		if (AIPawn == nullptr)
		{
			return EBTNodeResult::Failed;
		}

		FVector MuzzleLocation = AIPawn->Muzzle->GetComponentLocation();

		AActor* TargetActor = Cast<AActor>(OwnerComp.GetBlackboardComponent()->GetValueAsObject("TargetActor"));
		if (TargetActor == nullptr)
		{
			return EBTNodeResult::Failed;
		}

		FVector ActorLocation = { TargetActor->GetActorLocation().X, TargetActor->GetActorLocation().Y, TargetActor->GetActorLocation().Z+70.f };
		FVector Direction = ActorLocation - MuzzleLocation;

		FRotator MuzzleRotation = Direction.Rotation();

		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		AActor* NewProject = GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzleLocation, MuzzleRotation,Params);

		return NewProject ? EBTNodeResult::Succeeded : EBTNodeResult::Failed;
	}

	return EBTNodeResult::Failed;
}