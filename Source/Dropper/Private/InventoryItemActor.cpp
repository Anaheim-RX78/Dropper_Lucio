#include "InventoryItemActor.h"

AInventoryItemActor::AInventoryItemActor()
{
 	PrimaryActorTick.bCanEverTick = true;
}

void AInventoryItemActor::BeginPlay()
{
	Super::BeginPlay();
}

void AInventoryItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

