// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPS_ItemBase.generated.h"

class AFPS_Weapon;

UCLASS()
class TENCENT_FPS_API AFPS_ItemBase : public AActor
{
	GENERATED_BODY()

	
public:
	// Sets default values for this actor's properties
	AFPS_ItemBase();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//枪械蓝图
	UPROPERTY(EditAnywhere, Category = Weapons)
		TSubclassOf<AFPS_Weapon> WeaponClass[2];
	//获取武器类型
	virtual int GetWeaponKind();
	
};