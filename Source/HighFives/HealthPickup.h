// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pickup.h"
#include "HealthPickup.generated.h"

/**
 * 
 */
UCLASS()
class HIGHFIVES_API AHealthPickup : public APickup
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AHealthPickup();
	/** Override wasCollected function use implementation for blueprint native event */
	void WasCollected_Implementation() override;

	
	
	
};
