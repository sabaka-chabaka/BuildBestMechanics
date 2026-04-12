// 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BuilderPawn.generated.h"

UCLASS()
class BUILDBESTMECHANICS_API ABuilderPawn : public APawn
{
	GENERATED_BODY()

public:
	ABuilderPawn();

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
public:
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(EditAnywhere, Category="Camera")
	class UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	class UFloatingPawnMovement* Movement;
	
	UPROPERTY(EditAnywhere, Category="Building")
	class UBuildSystem* BuildSystem;
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveUp(float Value);
	
	void Turn(float Value);
	void LookUp(float Value);
	
	UPROPERTY(EditAnywhere)
	float BaseSpeed = 1200.0f;
	
	UPROPERTY(EditAnywhere)
	float BoostMultiplier = 3.0f;
	
	UPROPERTY(VisibleAnywhere)
	float CurrentSpeed = 0.f;
	
	UPROPERTY(VisibleAnywhere)
	float TargetSpeed = 0.f;

	UPROPERTY(EditAnywhere)
	float Acceleration = 8.f;
	
	UPROPERTY(EditAnywhere)
	float Deceleration = 10.f;

	UPROPERTY(VisibleAnywhere)
	bool bIsBoosting = false;
	
	UPROPERTY(EditAnywhere)
	float MinPitch = -85.f;
	
	UPROPERTY(EditAnywhere)
	float MaxPitch = 85.f;
	
	void StartBoost();
	void StopBoost();
};