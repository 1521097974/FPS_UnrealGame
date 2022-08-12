// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_AttributeComponent.h"

// Sets default values for this component's properties
UFPS_AttributeComponent::UFPS_AttributeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Score = 0;
	// ...
}
void UFPS_AttributeComponent::AddScore()
{
	Score+=1;
}
int UFPS_AttributeComponent::ReturnScore()
{
	return Score;
}


