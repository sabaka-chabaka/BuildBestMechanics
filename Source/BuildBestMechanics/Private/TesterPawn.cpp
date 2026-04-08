// 2026 sabaka-chabaka

#include "TesterPawn.h"

#include "Camera/CameraComponent.h"

ATesterPawn::ATesterPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
}

void ATesterPawn::BeginPlay()
{
	Super::BeginPlay();
}

void ATesterPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATesterPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis("MoveForward", this, &ATesterPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATesterPawn::MoveRight);
	
	PlayerInputComponent->BindAxis("Turn", this, &ATesterPawn::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ATesterPawn::LookUp);
}

void ATesterPawn::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void ATesterPawn::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void ATesterPawn::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ATesterPawn::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}