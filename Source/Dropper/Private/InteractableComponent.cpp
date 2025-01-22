#include "InteractableComponent.h"

#include "InventoryItemActor.h"
#include "Pinko.h"

UInteractableComponent::UInteractableComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInteractableComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UInteractableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UInteractableComponent::Interact(FInteractionPayload Payload)
{
	OnInteract.Broadcast(Payload);

	AInventoryItemActor* CurrentActor = Cast<AInventoryItemActor>(GetOwner());

	if (!CurrentActor) return;
	if(UInventory* ActorInventory = Payload.Interactor->GetComponentByClass<UInventory>())
	{
		ActorInventory->AddItem(CurrentActor, 1);
		GetOwner()->Destroy();
	}
	
}

FString UInteractableComponent::GetInteractionName()
{
	return InteractionName;
}

