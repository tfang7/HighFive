// Fill out your copyright notice in the Description page of Project Settings.

#include "HighFives.h"
#include "MyPawn.h"
#include "VehicleMovementComponent4W.h"
#include "MechPlayerController.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create a spring arm component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm0"));
	SpringArm->TargetOffset = FVector(0.f, 0.f, 400.f);
	SpringArm->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
	SpringArm->AttachTo(RootComponent);
	SpringArm->TargetArmLength = 675.0f;
	SpringArm->bEnableCameraRotationLag = true;
	SpringArm->CameraRotationLagSpeed = 7.f;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;

	// Create camera component 
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera0"));
	Camera->AttachTo(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;
	Camera->FieldOfView = 90.f;
	VehicleMovement = CreateDefaultSubobject<UVehicleMovementComponent4W>(TEXT("VehicleMovement"));
	VehicleMovement->UpdatedComponent = RootComponent;


}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAxis("MoveForward", this, &AMyPawn::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyPawn::MoveRight);

	

}
bool AMyPawn::isHandbrakeActive() const
{
	return bHandbrakeActive;
}

void AMyPawn::MoveForward(float Val) {
	if (VehicleMovement == NULL) {
		return;
	}
	VehicleMovement->SetThrottleInput(Val);
}

void AMyPawn::MoveRight(float Val) {
	if (VehicleMovement == NULL) {
		return;
	}
	VehicleMovement->SetSteeringInput(Val);
}