// Fill out your copyright notice in the Description page of Project Settings.


#include "PinkoController.h"



void APinkoController::SetupInputComponent()
{
	Super::SetupInputComponent();

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	Subsystem->ClearAllMappings();

	if (!InputMap)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("INPUT MAP MISSING IN CHARACTER CONTROLLER, OPEN THE CHARACTER CONTROLLER AND ASSIGN THE INPUT MAP!!!"));
		return;
	}

	Subsystem->AddMappingContext(InputMap->MappingContext, 0);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(InputMap->Actions["Move"], ETriggerEvent::Triggered, this, &APinkoController::Move);
	EnhancedInputComponent->BindAction(InputMap->Actions["Look"], ETriggerEvent::Triggered, this, &APinkoController::Look);
	EnhancedInputComponent->BindAction(InputMap->Actions["Jump"], ETriggerEvent::Started, this, &APinkoController::Jump);
	EnhancedInputComponent->BindAction(InputMap->Actions["Sprint"], ETriggerEvent::Started, this, &APinkoController::StartSprint);
	EnhancedInputComponent->BindAction(InputMap->Actions["Sprint"], ETriggerEvent::Completed, this, &APinkoController::EndSprint);
	EnhancedInputComponent->BindAction(InputMap->Actions["Scroll"], ETriggerEvent::Started, this, &APinkoController::ScrollInventory);
	EnhancedInputComponent->BindAction(InputMap->Actions["Drop"], ETriggerEvent::Started, this, &APinkoController::DropItem);
	EnhancedInputComponent->BindAction(InputMap->Actions["Interact"], ETriggerEvent::Started, this, &APinkoController::Interact);
}

void APinkoController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (APinko* PinkoPawn = Cast<APinko>(InPawn))
	{
		Pinko = PinkoPawn;
	}
}

void APinkoController::Move(const FInputActionValue& Value)
{
	Pinko->SetMovementInput(Value.Get<FVector2D>());
}

void APinkoController::Look(const FInputActionValue& Value)
{
	Pinko->SetLookInput(Value.Get<FVector2D>());
}

void APinkoController::Jump(const FInputActionValue& Value)
{
	Pinko->Jump();
}

void APinkoController::StartSprint(const FInputActionValue& Value)
{
	Pinko->StartSprinting();
}

void APinkoController::EndSprint(const FInputActionValue& Value)
{
	Pinko->StopSprinting();
}

void APinkoController::ScrollInventory(const FInputActionValue& Value)
{
	Pinko->ChangeItem();
}

void APinkoController::DropItem(const FInputActionValue& Value)
{
	Pinko->DropCurrentItem();
}

void APinkoController::Interact(const FInputActionValue& Value)
{
	Pinko->Interact();
}
