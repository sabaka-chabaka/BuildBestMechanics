// 2026 sabaka-chabaka

#include "PassiveBuildItem.h"

APassiveBuildItem::APassiveBuildItem()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APassiveBuildItem::BeginPlay()
{
	Super::BeginPlay();
}

void APassiveBuildItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}