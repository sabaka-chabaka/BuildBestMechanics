// 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildItem.generated.h"

UCLASS()
class BUILDBESTMECHANICS_API ABuildItem : public AActor
{
	GENERATED_BODY()

public:
	ABuildItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};