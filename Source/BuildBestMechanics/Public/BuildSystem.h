// 2026 sabaka-chabaka

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BuildSystem.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BUILDBESTMECHANICS_API UBuildSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	UBuildSystem();
	
	void UpdateGhost(const FVector& LookLocation, const FVector& LookDirection);
	void PlaceBlock();
	void RemoveBlock();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Build")
	TSubclassOf<class ABlock> BlockClass;

	UPROPERTY(EditAnywhere, Category = "Build")
	UStaticMesh* GhostMesh;

	UPROPERTY(EditAnywhere, Category = "Build")
	UMaterialInterface* GhostMaterialBase;

	UPROPERTY(EditAnywhere, Category = "Build")
	float GridSize = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Build")
	float BuildDistance = 600.0f;

public:
	UPROPERTY()
	UStaticMeshComponent* GhostComponent;

	UPROPERTY()
	UMaterialInstanceDynamic* GhostMaterialInst;

	FVector CurrentGridLocation;
	bool bCanPlace = false;

	FVector SnapToGrid(const FVector& Location, const FVector& Normal) const;
	bool TraceForBlock(FHitResult& OutHit, FVector Start, FVector Dir) const;
};
