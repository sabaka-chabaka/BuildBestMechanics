// 2026 sabaka-chabaka

#include "Block.h"

ABlock::ABlock()
{
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	
	Mesh->SetMobility(EComponentMobility::Static);
}