// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMap.h"
#include "Pinko.h"
#include "GameFramework/PlayerController.h"
#include "PinkoController.generated.h"

/**
 * 
 */
UCLASS()
class DROPPER_API APinkoController : public APlayerController
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, Category = "Input")
	APinko* Pinko;
	
	UPROPERTY(EditAnywhere, Category= "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* DropAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category= "Input", meta = (AllowPrivateAccess = "true"))
	UInputAction* ScrollInventoryAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", meta = (AllowPrivateAccess = "true"))
	UInputMap* InputMap;
	
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
	void Move(const FInputActionValue& Value);

	UFUNCTION()
	void Look(const FInputActionValue& Value);

	UFUNCTION()
	void Jump(const FInputActionValue& Value);

	UFUNCTION()
	void StartSprint(const FInputActionValue& Value);
	
	UFUNCTION()
	void EndSprint(const FInputActionValue& Value);
	
	UFUNCTION()
	void ScrollInventory(const FInputActionValue& Value);
	
	UFUNCTION()
	void DropItem(const FInputActionValue& Value);

	UFUNCTION()
	void Interact(const FInputActionValue& Value);
};
