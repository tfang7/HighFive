// Fill out your copyright notice in the Description page of Project Settings.

#include "HighFives.h"
#include "MechPlayerController.h"


AMechPlayerController::AMechPlayerController()
{
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
}

bool AMechPlayerController::IsHandbrakeForced() const
{
	return bHandbrakeOverride;
}
void AMechPlayerController::SetHandbrakeForced(bool bNewForced)
{
	bHandbrakeOverride = bNewForced;
}

