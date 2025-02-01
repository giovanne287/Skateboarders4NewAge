// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Skateboarders4NAGameMode.generated.h"

class UMainHUD;

UCLASS(minimalapi)
class ASkateboarders4NAGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASkateboarders4NAGameMode();
    
    // Function to add points
    void AddScore(int32 ScoreToAdd);

    // Return the current Points
    UFUNCTION(BlueprintCallable, Category = "Score")
        int32 GetScore() const { return CurrentScore; }
        


protected:
    virtual void BeginPlay() override;
    
    // Current Score
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
        int32 CurrentScore;

    // Widget Class to shows the score
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
        TSubclassOf<UMainHUD> MainHUDClass;

    // Widget instance created on begin play
    UPROPERTY()
        UMainHUD* ScoreWidgetInstance;

    // Update widget text
    void UpdateScoreWidget();
};



