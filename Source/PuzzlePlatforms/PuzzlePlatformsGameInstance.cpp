// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"

#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
// -------
// Gets called even in editor
// -------
UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	// create menu instance
	ConstructorHelpers::FClassFinder<UUserWidget> MenuWidgetBPClass(TEXT("/Game/Blueprints/Menu/WBP_MainMenu"));
	if (MenuWidgetBPClass.Class == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Class not found"));
		return;
	}
	// save menu class
	this->MenuClass = MenuWidgetBPClass.Class;
}

// -----------
// Init only gets called when we play the game
// ---------
void UPuzzlePlatformsGameInstance::Init()
{
	Super::Init();
}

void UPuzzlePlatformsGameInstance::LoadMenu()
{	
	if (this->MenuClass != NULL)
	{
		// display menu
		UUserWidget* mainMenu = CreateWidget<UUserWidget>(this, this->MenuClass);
		if (mainMenu != nullptr)
		{
			mainMenu->AddToViewport();
			// get hold of player controller
			APlayerController* controller = this->GetFirstLocalPlayerController();
			FInputModeUIOnly inputMode;
			inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			inputMode.SetWidgetToFocus(mainMenu->TakeWidget());
			controller->SetInputMode(inputMode);
			controller->bShowMouseCursor = true;
		}		
	}
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