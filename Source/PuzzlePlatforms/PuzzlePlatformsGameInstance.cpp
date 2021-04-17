// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"
#include "Engine/Engine.h"
// -------
// Gets called even in editor
// -------
UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
}

// -----------
// Init only gets called when we play the game
// ---------
void UPuzzlePlatformsGameInstance::Init()
{
	Super::Init();
}

void UPuzzlePlatformsGameInstance::Host()
{
	UEngine* engine = this->GetEngine();
	if (engine == nullptr)
	{
		return;
	}
	engine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("HOSTING"));
	// server travel through world
	UWorld* world = this->GetWorld();
	if (world == nullptr)
	{
		return;
	}
	world->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{
	UEngine* engine = this->GetEngine();
	if (engine == nullptr)
	{
		return;
	}
	engine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("JOINING %s"), *Address));
	// client travel through server controller
	APlayerController* controller = this->GetFirstLocalPlayerController();
	if (controller == nullptr)
	{
		return;
	}	
	controller->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}