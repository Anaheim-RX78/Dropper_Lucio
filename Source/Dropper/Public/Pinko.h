#pragma once

#include "CoreMinimal.h"
#include "Inventory.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Pinko.generated.h"

UCLASS()
class DROPPER_API APinko : public ACharacter
{
	GENERATED_BODY()

public:
	APinko();

protected:
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

	UPROPERTY(EditAnywhere, Category = "Inventory")
	UInventory* Inventory;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int ItemIndex;
	
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
	void ChangeItem();
	void DropCurrentItem();
};
