#pragma once

#include "CoreMinimal.h"
#include "InventoryItemData.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"

USTRUCT()
struct FInventorySlot
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category=Item)
	int Amount;

	UPROPERTY(EditAnywhere, Category=Item)
	UInventoryItemData* ItemData;
};

UCLASS( ClassGroup=(InventorySystem), meta=(BlueprintSpawnableComponent) )
class DROPPER_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventory();
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void AddItem(AInventoryItemActor* Item, int Amount);
	
	void AddItem(UInventoryItemData* Item, int Amount);
	
	UFUNCTION(BlueprintCallable, Category="Inventory")
	void DropItem(int index, int Amount, FVector DropLocation);
	
	void DropItem(UInventoryItemData* Item, int Amount, FVector DropLocation);
	
	FInventorySlot* GetSlotByData(UInventoryItemData* Item);
	
	UPROPERTY(EditAnywhere, Category="Inventory")
	int CurrentItemIndex = 0;
	
	FString SetNextSlot();
	
	void DropCurrentItem(int Amount, FVector DropLocation);
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category=Inventory)
	TArray<FInventorySlot> Items;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
};
