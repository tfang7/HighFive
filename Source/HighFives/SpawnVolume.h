// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class HIGHFIVES_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	/**Returns spawn location */
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }
	/**Find a random point within box component*/
	UFUNCTION(BlueprintPure, Category = "Spawning")
	FVector GetRandomPointInVolume();
	
protected:
	/** The pickup to spawn*/
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<class APickup> WhatToSpawn;
	
	FTimerHandle SpawnTimer;

	/** Minimum Spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeLow;

	/** Maximum Spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnDelayRangeHigh;

private:
	/**Box Component to specify pickup spawn location */
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WhereToSpawn;
	/** Spawn pickup object*/
	void SpawnPickup();

	/** current delay time*/
	float SpawnDelay;
};
