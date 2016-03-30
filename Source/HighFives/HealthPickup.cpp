// Fill out your copyright notice in the Description page of Project Settings.

#include "HighFives.h"
#include "HealthPickup.h"


AHealthPickup::AHealthPickup()
{
	GetMesh()->SetSimulatePhysics(true);
}

void AHealthPickup::WasCollected_Implementation()
{
	// Use base pickup behavior
	Super::WasCollected_Implementation();
	// Destroy the battery
	Destroy();
}