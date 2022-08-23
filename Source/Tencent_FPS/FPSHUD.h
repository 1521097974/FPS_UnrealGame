// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <Engine/Canvas.h>
#include "FPSHUD.generated.h"

class AFPSCharacter;

UCLASS()
class TENCENT_FPS_API AFPSHUD : public AHUD
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly)
		UTexture2D* CrosshairTexture;

	AFPSCharacter* Character;
public:
	UPROPERTY(EditDefaultsOnly, Category = Character)
		TSubclassOf<class AFPSCharacter> FPSCharacterClass;

	UFUNCTION(BlueprintCallable)
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;

};
