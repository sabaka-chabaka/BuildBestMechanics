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
	
private:
	UPROPERTY(EditAnywhere, Category="Camera")
	class UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	class UFloatingPawnMovement* Movement;
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveUp(float Value);
	
	void Turn(float Value);
	void LookUp(float Value);
};