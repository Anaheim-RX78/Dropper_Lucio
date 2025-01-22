#include "PlayerInteractionComponent.h"

UPlayerInteractionComponent::UPlayerInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UPlayerInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UPlayerInteractionComponent::CheckInteractionRange()
{

	FHitResult HitResult;

	GetWorld()->LineTraceSingleByChannel(HitResult, GetComponentLocation(), GetComponentLocation() + (GetForwardVector() * InteractionDistance), InteractionChannel);

	AActor* HitActor = HitResult.GetActor();

	if (HitActor == nullptr)
	{
		return;
	}

	UInteractableComponent* Component = HitActor->GetComponentByClass<UInteractableComponent>();
	if (CurrentInteractable == nullptr && Component)
	{
		CurrentInteractable = Component;
	}
	else if (CurrentInteractable && Component && Component != CurrentInteractable)
	{
		CurrentInteractable = Component;
	}

}

void UPlayerInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	CheckInteractionRange();
}

FString UPlayerInteractionComponent::GetInteractableName()
{
	if (CurrentInteractable == nullptr) return TEXT("");
	return CurrentInteractable->GetName();
}

void UPlayerInteractionComponent::Interact()
{
	if (CurrentInteractable == nullptr) return;

	CurrentInteractable->Interact(FInteractionPayload{GetOwner()});
}
