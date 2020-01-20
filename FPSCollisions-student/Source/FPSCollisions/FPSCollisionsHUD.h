// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FPSCollisionsHUD.generated.h"

UCLASS()
class AFPSCollisionsHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFPSCollisionsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

