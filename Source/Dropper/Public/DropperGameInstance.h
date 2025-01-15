// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DropperGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DROPPER_API UDropperGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere, Category = "Score")
	float MaxDepth = 0;

	UPROPERTY(EditAnywhere, Category = "Level")
	FString CurrentLevelId = "Level01";

	UPROPERTY(EditAnywhere, Category = "Level")
	int Attempts = 0;

	UPROPERTY(EditAnywhere, Category = "Level")
	int CoinsCollected = 0;

public:
	UFUNCTION(BlueprintCallable)
	void OnLevelLoaded(FString LevelId);

	UFUNCTION(BlueprintCallable)
	void SetMaxDepth(float NewDepth);

	UFUNCTION(BlueprintCallable)
	void SetCoinCollected();
};
