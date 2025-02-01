// Fill out your copyright notice in the Description page of Project Settings.


#include "MainHUD.h"
#include "Components/TextBlock.h"


void UMainHUD::UpdateScoreText(int32 NewScore)
{
    if (ScoreText)
    {
        ScoreText->SetText(FText::AsNumber(NewScore));
    }
}

