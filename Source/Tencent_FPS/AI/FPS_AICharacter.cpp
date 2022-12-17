// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_AICharacter.h"
//#include "Components/SceneComponent.h"

// Sets default values
AFPS_AICharacter::AFPS_AICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPS_AICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_AICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



