// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "Tencent_FPSGameModeBase.generated.h"
/**
 * 
 */
UCLASS()
class TENCENT_FPS_API ATencent_FPSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	//�˺�����������������StartPlay���Ա���Ϸ����ʱ����Ļ�ϴ�ӡ��־��Ϣ��
	virtual void StartPlay() override;
public:
	UFUNCTION(BlueprintCallable, Category = "UMG Game")
		void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
		TSubclassOf<UUserWidget> StartingWidgetClass;
	UPROPERTY()
		UUserWidget* CurrentWidget;
};
