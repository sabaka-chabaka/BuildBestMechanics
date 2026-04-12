// 2026 sabaka-chabaka

#include "BuildBestMechanics/Public/BuilderPawn.h"

#include "BuildSystem.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

ABuilderPawn::ABuilderPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
	
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	Movement->MaxSpeed = 2000.0f;
}

void ABuilderPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ABuilderPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABuilderPawn::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &ABuilderPawn::MoveUp);
	
	PlayerInputComponent->BindAxis("Turn", this, &ABuilderPawn::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ABuilderPawn::LookUp);
	
	PlayerInputComponent->BindAction("Boost", IE_Pressed, this, &ABuilderPawn::StartBoost);
	PlayerInputComponent->BindAction("Boost", IE_Released, this, &ABuilderPawn::StopBoost);
}

void ABuilderPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	float DesiredSpeed = bIsBoosting ? BaseSpeed * BoostMultiplier : BaseSpeed;

	if (CurrentSpeed < DesiredSpeed)
	{
		CurrentSpeed = FMath::FInterpTo(CurrentSpeed, DesiredSpeed, DeltaTime, Acceleration);
	}
	else
	{
		CurrentSpeed = FMath::FInterpTo(CurrentSpeed, DesiredSpeed, DeltaTime, Deceleration);
	}
	
	Movement->MaxSpeed = CurrentSpeed;
	
	BuildSystem->UpdateGhost(GetActorLocation(), GetActorForwardVector());
}

void ABuilderPawn::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ABuilderPawn::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void ABuilderPawn::MoveUp(float Value)
{
	AddMovementInput(GetActorUpVector(), Value);
}

void ABuilderPawn::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ABuilderPawn::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ABuilderPawn::StartBoost()
{
	bIsBoosting = true;
}

void ABuilderPawn::StopBoost()
{
	bIsBoosting = false;
}