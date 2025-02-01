// Copyright Epic Games, Inc. All Rights Reserved.

#include "Skateboarders4NAGameMode.h"
#include "Skateboarders4NACharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.h"

ASkateboarders4NAGameMode::ASkateboarders4NAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	
    if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	CurrentScore = 0;
}

void ASkateboarders4NAGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Debug print
    //UE_LOG(LogTemp, Warning, TEXT("MainHUDClass: %s"), *GetNameSafe(MainHUDClass));

    // Create and add the widget to the viewport
    if (MainHUDClass)
    {
        // Debug print
        //UE_LOG(LogTemp, Warning, TEXT("Creating Widget AAAAAAAAAAAAAAAAAAAAAAAA..."));

        APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
        ScoreWidgetInstance = CreateWidget<UMainHUD>(PC, MainHUDClass);
        if (ScoreWidgetInstance)
        {
            ScoreWidgetInstance->AddToViewport();
            ScoreWidgetInstance->UpdateScoreText(CurrentScore);
        }
    }
}

void ASkateboarders4NAGameMode::AddScore(int32 ScoreToAdd)
{
    CurrentScore += ScoreToAdd;
    UpdateScoreWidget();
}

void ASkateboarders4NAGameMode::UpdateScoreWidget()
{
    if (ScoreWidgetInstance)
    {
        ScoreWidgetInstance->UpdateScoreText(CurrentScore);
    }   
}