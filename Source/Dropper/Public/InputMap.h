// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/DataAsset.h"
#include "InputMap.generated.h"

/**
 * 
 */

UCLASS(Blueprintable)
class DROPPER_API UInputMap : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* MappingContext;

	UPROPERTY(EditAnywhere, Category = Input)
	TMap<FString, UInputAction*> Actions;
};
