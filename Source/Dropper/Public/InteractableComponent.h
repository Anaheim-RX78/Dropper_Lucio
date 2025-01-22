#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractableComponent.generated.h"

USTRUCT(BlueprintType)
struct FInteractionPayload
{
	GENERATED_BODY()

	UPROPERTY()
	AActor* Interactor;

	UPROPERTY()
	FVector InteractorLocation;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInteractionHandler, FInteractionPayload, Payload);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DROPPER_API UInteractableComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractableComponent();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	FString InteractionName;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FInteractionHandler OnInteract;

	UFUNCTION()
	virtual void Interact(FInteractionPayload Payload);

	UFUNCTION()
	FString GetInteractionName();
	
};
