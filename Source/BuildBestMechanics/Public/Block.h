// 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block.generated.h"

UCLASS()
class BUILDBESTMECHANICS_API ABlock : public AActor
{
	GENERATED_BODY()

public:
	ABlock();
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;
};