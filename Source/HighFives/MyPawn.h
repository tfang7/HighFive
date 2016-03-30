// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "VehicleMovementComponent4W.h"

#include "MyPawn.generated.h"

UCLASS()
class HIGHFIVES_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	UFUNCTION(BlueprintCallable, Category = "Game|Vehicle")
		bool isHandbrakeActive() const;

	FVector CurrentVelocity;
	UPROPERTY(EditAnywhere)
		USceneComponent* OurVisibleComponent;
	UPROPERTY(EditAnywhere)
		float MechHealth;
	UPROPERTY(EditAnywhere)
		float MechSpeed;
	UParticleSystemComponent *OurParticleSystem;

	UPROPERTY(EditAnywhere)
	UVehicleMovementComponent4W *VehicleMovement;

	void MoveForward(float Val);
	void MoveRight(float Val);

protected:
	//Input Variables
	float ZoomFactor;
	bool bZoomingIn;



	void ZoomIn();
	void ZoomOut();

	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);


	void WeaponTrigger();
protected:
private:
	/** Spring arm that will offset the camera */
	UPROPERTY(Category = SpringArm, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArm;

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* Camera;


protected:
	/** is handbrake active? */
	uint32 bHandbrakeActive : 1;

	/** if key is being held to control the throttle, ignore other controllers */
	uint32 bKeyboardThrottle : 1;

	/** if key is being held to control the turning, ignore other controllers */
	uint32 bKeyboardTurn : 1;

	/** if turn left action key is pressed */
	uint32 bTurnLeftPressed : 1;

	/** if turn right action key is pressed */
	uint32 bTurnRightPressed : 1;

	/** if accelerate action key is pressed */
	uint32 bAcceleratePressed : 1;

	/** if break/reverse action key is pressed */
	uint32 bBreakReversePressed : 1;

protected:
	/** Returns SpringArm subobject **/
	FORCEINLINE USpringArmComponent* GetSpringArm() const { return SpringArm; }
	/** Returns Camera subobject **/
	FORCEINLINE UCameraComponent* GetCamera() const { return Camera; }
	FORCEINLINE UVehicleMovementComponent4W* GetVehicleMovement() const { return VehicleMovement; }



};
