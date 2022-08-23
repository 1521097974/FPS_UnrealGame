// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSHUD.h"
#include "FPSCharacter.h"
#include <Kismet/GameplayStatics.h>


void AFPSHUD::BeginPlay()
{
	Super::BeginPlay();
	//Character = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	Character = GetWorld()->SpawnActor<AFPSCharacter>();
}
void AFPSHUD::DrawHUD()
{
	if (CrosshairTexture&&Character->HandWeapon)
	{
		FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

		FVector2D CrossHairDrawPosition(Center.X - (CrosshairTexture->GetSurfaceWidth() * 0.5f), Center.Y - (CrosshairTexture->GetSurfaceHeight() * 0.5f));

		FCanvasTileItem TitleItem(CrossHairDrawPosition, CrosshairTexture->Resource, FLinearColor::White);
		TitleItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TitleItem);
	}
}



