// Fill out your copyright notice in the Description page of Project Settings.


#include "DropperGameInstance.h"

void UDropperGameInstance::OnLevelLoaded(FString LevelId)
{
	if (LevelId == CurrentLevelId)
	{
		//TODO: Reset some stuff
		return;
	}
	else
	{
		//TODO: Reset some other stuff
	}
}

void UDropperGameInstance::SetMaxDepth(float NewDepth)
{
	MaxDepth = NewDepth;
}

void UDropperGameInstance::SetCoinCollected()
{
	CoinsCollected = CoinsCollected + 1;
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Format(TEXT("Total coins: {0}"), {CoinsCollected}));
}
