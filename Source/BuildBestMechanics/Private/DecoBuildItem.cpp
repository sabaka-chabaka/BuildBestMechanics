// 2026 sabaka-chabaka

#include "DecoBuildItem.h"

ADecoBuildItem::ADecoBuildItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADecoBuildItem::BeginPlay()
{
	Super::BeginPlay();
}

void ADecoBuildItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}