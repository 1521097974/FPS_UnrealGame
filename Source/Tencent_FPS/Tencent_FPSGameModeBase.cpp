// Copyright Epic Games, Inc. All Rights Reserved.


#include "Tencent_FPSGameModeBase.h"

void ATencent_FPSGameModeBase::StartPlay()
{
	Super::StartPlay();

	//ChangeMenuWidget(StartingWidgetClass);
	
}
void ATencent_FPSGameModeBase::ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget)
		{
			CurrentWidget->AddToViewport();
		}
	}
}