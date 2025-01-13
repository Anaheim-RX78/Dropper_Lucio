// Fill out your copyright notice in the Description page of Project Settings.


#include "PinkoController.h"



void APinkoController::SetupInputComponent()
{
	Super::SetupInputComponent();

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(DefaultMappingContext, 0);

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APinkoController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &APinkoController::Look);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &APinkoController::Jump);
	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &APinkoController::StartSprint);
	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &APinkoController::EndSprint);
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

