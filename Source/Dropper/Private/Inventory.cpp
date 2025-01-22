#include "Inventory.h"

#include "InventoryItemActor.h"


UInventory::UInventory()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventory::AddItem(AInventoryItemActor* Item, int Amount)
{
	AddItem(Item->ItemData, Amount);
	Item->Destroy();
}

void UInventory::AddItem(UInventoryItemData* Item, int Amount)
{
	if (FInventorySlot* Slot = GetSlotByData(Item))
	{
		Slot->Amount += Amount;
	}
	else
	{
		Items.Add({Amount, Item});
	}
}

void UInventory::DropItem(int index, int Amount, FVector DropLocation)
{
	int RealDropAmount = FMath::Min(Items[index].Amount, Amount);
	if (RealDropAmount <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("No %s available!"), *Items[index].ItemData->PrettyName));
		return;
	}
	DropItem(Items[index].ItemData, RealDropAmount, DropLocation);
	Items[index].Amount -= RealDropAmount;

	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Dropped %s %d times, %d remaining"), *Items[index].ItemData->PrettyName, RealDropAmount, Items[index].Amount));
}

void UInventory::DropItem(UInventoryItemData* Item, int Amount, FVector DropLocation)
{
	for (int i = 0; i < Amount; i++)
	{
		GetWorld()->SpawnActor<AInventoryItemActor>(Item->Item, DropLocation, FRotator::ZeroRotator);
	}
}

FInventorySlot* UInventory::GetSlotByData(UInventoryItemData* Item)
{
	for (FInventorySlot& Slot : Items)
	{
		if (Slot.ItemData == Item)
		{
			return &Slot;
		}
	}

	return nullptr;
}

FString UInventory::SetNextSlot()
{
	CurrentItemIndex = (CurrentItemIndex + 1) % Items.Num();
	return Items[CurrentItemIndex].ItemData->PrettyName; 
}

void UInventory::DropCurrentItem(int Amount, FVector DropLocation)
{
	DropItem(CurrentItemIndex, Amount, DropLocation);
}


void UInventory::BeginPlay()
{
	Super::BeginPlay();
}


void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
