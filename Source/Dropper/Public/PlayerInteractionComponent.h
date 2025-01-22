#pragma once

#include "CoreMinimal.h"
#include "InteractableComponent.h"
#include "Components/SceneComponent.h"
#include "PlayerInteractionComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DROPPER_API UPlayerInteractionComponent : public USceneComponent
{
	GENERATED_BODY()
	
public:
	UPlayerInteractionComponent();
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	float InteractionDistance = 1000.f;
	
	UPROPERTY(EditAnywhere)
	TEnumAsByte<ECollisionChannel> InteractionChannel;
	
	UPROPERTY(EditAnywhere)
	UInteractableComponent* CurrentInteractable = nullptr;
	
	void CheckInteractionRange();

	
public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	FString GetInteractableName();

	void Interact();
};
