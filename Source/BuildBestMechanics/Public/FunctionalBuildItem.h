// 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "BuildItem.h"
#include "FunctionalBuildItem.generated.h"

UCLASS()
class BUILDBESTMECHANICS_API AFunctionalBuildItem : public ABuildItem
{
	GENERATED_BODY()

public:
	AFunctionalBuildItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};