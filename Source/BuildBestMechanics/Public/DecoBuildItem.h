// 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "BuildItem.h"
#include "DecoBuildItem.generated.h"

UCLASS()
class BUILDBESTMECHANICS_API ADecoBuildItem : public ABuildItem
{
	GENERATED_BODY()

public:
	ADecoBuildItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};