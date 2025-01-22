// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItemActor.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Coin.generated.h"

UCLASS()
class DROPPER_API ACoin : public AInventoryItemActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	               int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, Category="Components")
	UCapsuleComponent* CapsuleComponent;
	
	UPROPERTY(EditAnywhere, Category="Components")
	UStaticMeshComponent* MeshComponent;

};
