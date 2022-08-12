// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Target.h"
#include <Components/SphereComponent.h>

// Sets default values
AFPS_Target::AFPS_Target()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	RootComponent = CollisionComponent;
	TargetMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMeshComponent"));
	TargetMeshComponent->SetupAttachment(RootComponent);
	TargetMeshComponent->SetRelativeScale3D(FVector(0.01f, 0.01f, 0.01f));
}

// Called when the game starts or when spawned
void AFPS_Target::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPS_Target::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


