// Fill out your copyright notice in the Description page of Project Settings.


#include "Pinko.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APinko::APinko()
{
	PrimaryActorTick.bCanEverTick = true;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("CameraSpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.f;
	SpringArm->bUsePawnControlRotation = true;
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
}

void APinko::BeginPlay()
{
	Super::BeginPlay();
}

void APinko::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APinko::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APinko::SetMovementInput(const FVector2D& MovementVector)
{
	AddMovementInput(GetActorForwardVector(), MovementVector.Y);
	AddMovementInput(GetActorRightVector(), MovementVector.X);
}

void APinko::SetLookInput(const FVector2D& LookVector)
{
	AddControllerYawInput(LookVector.X);
	AddControllerPitchInput(LookVector.Y);
}

void APinko::StartSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed = 3000.f;
}

void APinko::StopSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed = 200.f;
}