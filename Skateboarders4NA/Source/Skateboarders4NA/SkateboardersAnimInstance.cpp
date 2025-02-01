// Fill out your copyright notice in the Description page of Project Settings.


#include "SkateboardersAnimInstance.h"

USkateboardersAnimInstance::USkateboardersAnimInstance()
{
    OwningCharacter = nullptr;
    MovementComponent = nullptr;
    CurrentVelocity = 0.0f;
    bIsFalling = false;
}

void USkateboardersAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    // Check if owner is valid
    if (!OwningCharacter)
    {
        // Try to get pawn owner
        OwningCharacter = Cast<ACharacter>(TryGetPawnOwner());

        // Try to get MovementComponent
        if (OwningCharacter)
        {
            MovementComponent = OwningCharacter->GetCharacterMovement();
        }
    }

    // If the character and movement component is valid get the values
    if (OwningCharacter && MovementComponent)
    {
        // Current speed
        CurrentVelocity = OwningCharacter->GetVelocity().Size();

        // Is jumping
        bIsFalling = MovementComponent->IsFalling();
    }
}
