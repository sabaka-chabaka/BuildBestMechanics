// 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "BuildItem.h"
#include "PassiveBuildItem.generated.h"

UCLASS()
class BUILDBESTMECHANICS_API APassiveBuildItem : public ABuildItem
{
	GENERATED_BODY()

public:
	APassiveBuildItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};