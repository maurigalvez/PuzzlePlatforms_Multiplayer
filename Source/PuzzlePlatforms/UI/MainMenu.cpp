// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"

void UMainMenu::Setup()
{
	this->AddToViewport();
	// get world
	UWorld* World = this->GetWorld();
	if (World == nullptr) return;

	// get hold of player controller
	APlayerController* controller = World->GetFirstPlayerController();
	if (controller == nullptr) return;

	FInputModeUIOnly inputMode;
	inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	inputMode.SetWidgetToFocus(this->TakeWidget());
	controller->SetInputMode(inputMode);
	controller->bShowMouseCursor = true;
}

void UMainMenu::Remove()
{
	// remove from viewport
	this->RemoveFromViewport();
	// get world
	UWorld* World = this->GetWorld();
	if (World == nullptr) return;
	
	APlayerController* controller = World->GetFirstPlayerController();
	if (controller == nullptr) return;

	FInputModeGameOnly inputMode;	
	controller->SetInputMode(inputMode);
	controller->bShowMouseCursor = false;
}

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success)
		return false;
	// Initialize buttons
	if (this->HostButton == nullptr)
	{
		return false;
	}
	this->HostButton->OnClicked.AddDynamic(this, &UMainMenu::Host);

	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* NewMenuInterface)
{
	this->MenuInterface = NewMenuInterface;
}

void UMainMenu::Host()
{
	if (this->MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

