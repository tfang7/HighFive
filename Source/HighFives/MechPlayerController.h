// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "MechPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class HIGHFIVES_API AMechPlayerController : public APlayerController
{
	GENERATED_BODY()
		AMechPlayerController();
	/** is handbrake forced? */
	bool IsHandbrakeForced() const;
	/** set handbrake forced */
	void SetHandbrakeForced(bool bNewForced);

protected:
	bool bHandbrakeOverride;
};

