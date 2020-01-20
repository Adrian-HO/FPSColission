// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "FPSCollisionsGameMode.h"
#include "FPSCollisionsHUD.h"
#include "FPSCollisionsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPSCollisionsGameMode::AFPSCollisionsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPSCollisionsHUD::StaticClass();
}
