// 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BBSPlayerController.generated.h"

UCLASS()
class BUILDBESTMECHANICS_API ABBSPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ABBSPlayerController();
	
protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaSeconds) override;
};