// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_BTService_CheackAttackRange.h"
#include <BehaviorTree/BlackboardComponent.h>
#include <AIController.h>

void UFPS_BTService_CheackAttackRange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	//ȷ��AI��Ŀ��ľ���
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (ensure(BlackboardComp))
	{
		AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("TargetActor"));
		if (TargetActor)
		{
			AAIController* Controller = OwnerComp.GetAIOwner();
			if (ensure(Controller))
			{
				APawn* AIPawn = Controller->GetPawn();
				if (ensure(AIPawn))
				{
					float DistanceTo = FVector::Distance(TargetActor->GetActorLocation(), AIPawn->GetActorLocation());
					//����С��2000
					bool bInRange = DistanceTo < 2000.f;
					//�Ƿ���������
					bool bHasLos = false;
					if (bInRange)
					{
						bHasLos = Controller->LineOfSightTo(TargetActor);
					}

					BlackboardComp->SetValueAsBool(AttackRangeKey.SelectedKeyName, (bInRange && bHasLos));
				}
			}
		}
	}
}