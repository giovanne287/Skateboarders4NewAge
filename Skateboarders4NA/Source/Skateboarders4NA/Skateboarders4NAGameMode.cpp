// Copyright Epic Games, Inc. All Rights Reserved.

#include "Skateboarders4NAGameMode.h"
#include "Skateboarders4NACharacter.h"
#include "UObject/ConstructorHelpers.h"

ASkateboarders4NAGameMode::ASkateboarders4NAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
