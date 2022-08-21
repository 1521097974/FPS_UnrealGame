// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_ItemBase.h"
#include "FPS_Weapon.h"


// Sets default values
AFPS_ItemBase::AFPS_ItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
	static ConstructorHelpers::FClassFinder<AFPS_Weapon> BWeapon_0(TEXT("/Game/Blueprints/Weapons/BP_FPS_Weapon.BP_FPS_Weapon"));
	static ConstructorHelpers::FClassFinder<AFPS_Weapon> BWeapon_1(TEXT("/Game/Blueprints/Weapons/BP_FPS_Weapon_Blue.BP_FPS_Weapon_Blue"));
	if (BWeapon_0.Class)
	{
		WeaponClass[0] = BWeapon_0.Class;
	}
	if (BWeapon_1.Class)
	{
		WeaponClass[1] = BWeapon_1.Class;
	}
	*/
	//WeaponClass[0] = LoadClass<AFPS_Weapon>(NULL, TEXT("Blueprint'/Game/Blueprints/Weapons/BP_FPS_Weapon.BP_FPS_Weapon_C'"));
	//WeaponClass[1] = LoadClass<AFPS_Weapon>(NULL, TEXT("Blueprint'/Game/Blueprints/Weapons/BP_FPS_Weapon_Blue.BP_FPS_Weapon_Blue_C'"));
	
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
