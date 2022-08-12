// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_ItemBase.h"


// Sets default values
AFPS_ItemBase::AFPS_ItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AFPS_ItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_ItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
int AFPS_ItemBase::GetWeaponKind()
{
	return 0;
}
