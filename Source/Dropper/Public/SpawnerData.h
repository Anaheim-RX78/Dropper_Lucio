// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SpawnerData.generated.h"

/**
 * 
 */
UCLASS()
class DROPPER_API USpawnerData : public UDataAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Input)
	TArray<AActor*> SpawnableItems;
};
