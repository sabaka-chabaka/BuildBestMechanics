// 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TesterPawn.generated.h"

UCLASS()
class BUILDBESTMECHANICS_API ATesterPawn : public ACharacter
{
	GENERATED_BODY()

public:
	ATesterPawn();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
protected:
	UPROPERTY(EditAnywhere, Category="Camera")
	class UCameraComponent* Camera;
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	
	void Turn(float Value);
	void LookUp(float Value);
};