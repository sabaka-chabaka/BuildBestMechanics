// 2026 sabaka-chabaka

#include "BuildItem.h"

ABuildItem::ABuildItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABuildItem::BeginPlay()
{
	Super::BeginPlay();
}

void ABuildItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}