// 2026 sabaka-chabaka

#include "FunctionalBuildItem.h"

AFunctionalBuildItem::AFunctionalBuildItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFunctionalBuildItem::BeginPlay()
{
	Super::BeginPlay();
}

void AFunctionalBuildItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}