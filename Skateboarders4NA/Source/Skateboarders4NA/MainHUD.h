// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainHUD.generated.h"

class UTextBlock;

UCLASS()
class SKATEBOARDERS4NA_API UMainHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
    // Update score text on screen
    UFUNCTION(BlueprintCallable, Category = "Score")
        void UpdateScoreText(int32 NewScore);

protected:
    // This text block must be binded to the UMG element (with bind widget)
    UPROPERTY(meta = (BindWidget))
        UTextBlock* ScoreText;

};
