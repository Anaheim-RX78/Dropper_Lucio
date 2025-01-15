// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Pinko.generated.h"

UCLASS()
class DROPPER_API APinko : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APinko();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed = 100.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float JumpForce = 1000.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float SprintMultiplier = 3.f;

	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Movement")
	bool IsSprinting = false;


	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	void AddCoin();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	void SetMovementInput(const FVector2D& MovementVector);
	void SetLookInput(const FVector2D& LookVector);
	void StartSprinting();
	void StopSprinting();

};
