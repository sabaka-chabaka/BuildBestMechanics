// 2026 sabaka-chabaka

#include "BuildSystem.h"
#include "Block.h"

UBuildSystem::UBuildSystem()
{
	PrimaryComponentTick.bCanEverTick = false;
	Mode = None;
}

void UBuildSystem::UpdateGhost(const FVector& LookLocation, const FVector& LookDirection)
{
	if (FHitResult Hit; TraceForBlock(Hit, LookLocation, LookDirection))
	{
		CurrentGridLocation = SnapToGrid(Hit.Location, Hit.Normal);
		GhostComponent->SetWorldLocation(CurrentGridLocation);
		GhostComponent->SetHiddenInGame(false);
		
		FCollisionShape Box = FCollisionShape::MakeBox(FVector(GridSize * 0.4f));
		bCanPlace = !GetWorld()->OverlapAnyTestByChannel(CurrentGridLocation, FQuat::Identity, ECC_Visibility, Box);

		if (GhostMaterialInst)
			GhostMaterialInst->SetVectorParameterValue("Color", bCanPlace ? FLinearColor::Green : FLinearColor::Red);
    
	}
	else
	{
		GhostComponent->SetHiddenInGame(true);
		bCanPlace = false;
	}
}

void UBuildSystem::PlaceBlock()
{
	if (bCanPlace && BlockClass)
	{
		FActorSpawnParameters SpawnParams;
		GetWorld()->SpawnActor<ABlock>(BlockClass, CurrentGridLocation, FRotator::ZeroRotator, SpawnParams);
	}
}

void UBuildSystem::RemoveBlock()
{
	//TODO
}

void UBuildSystem::BeginPlay()
{
	Super::BeginPlay();
	
	GhostComponent = NewObject<UStaticMeshComponent>(GetOwner());
	GhostComponent->SetStaticMesh(GhostMesh);
	GhostComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GhostComponent->RegisterComponent();

	if (GhostMaterialBase)
	{
		GhostMaterialInst = UMaterialInstanceDynamic::Create(GhostMaterialBase, this);
		GhostComponent->SetMaterial(0, GhostMaterialInst);
	}
}

FVector UBuildSystem::SnapToGrid(const FVector& Location, const FVector& Normal) const
{
	FVector Offset = Location + (Normal * (GridSize * 0.5f));
	return FVector(FMath::GridSnap(Offset.X, GridSize), FMath::GridSnap(Offset.Y, GridSize), FMath::GridSnap(Offset.Z, GridSize));
}

bool UBuildSystem::TraceForBlock(FHitResult& OutHit, FVector Start, FVector Dir) const
{
	const FVector End = Start + (Dir * BuildDistance);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());
	return GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, Params);
}

void UBuildSystem::SetMode(EBuildMode Mode)
{
	this->Mode = Mode;
}

void UBuildSystem::RouteInput()
{
	switch (Mode)
	{
	default: break;
	case Build:
		{
			PlaceBlock();
			break;
		}
	case Delete:
		{
			RemoveBlock();	
		}
	case Setup:
		{
			//TODO	
		}
	case Paint:
		{
			//TODO	
		}
	case MoveBlock:
		{
			//TODO	
		}
	}
}
