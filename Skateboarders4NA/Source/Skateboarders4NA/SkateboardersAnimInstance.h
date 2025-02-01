// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SkateboardersAnimInstance.generated.h"


UCLASS()
class SKATEBOARDERS4NA_API USkateboardersAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:

    USkateboardersAnimInstance();

    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
    
    // Get Owner Reference
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
        ACharacter* OwningCharacter;

    // Get Owner MovementComponent
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Character")
        UCharacterMovementComponent* MovementComponent;

    // Cache current velocity
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
        float CurrentVelocity;

    // Get if character is falling
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
        bool bIsFalling;

};
