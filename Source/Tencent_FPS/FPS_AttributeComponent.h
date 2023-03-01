// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FPS_AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TENCENT_FPS_API UFPS_AttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFPS_AttributeComponent();
protected:
	//·ÖÊý
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Attribute);
		int Score;
	
public:
	UFUNCTION(BlueprintCallable)
		void AddScore();
	UFUNCTION(BlueprintCallable)
		int ReturnScore();
		
};
