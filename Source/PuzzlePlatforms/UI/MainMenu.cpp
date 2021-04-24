// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"

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

void UMainMenu::Host()
{
	UE_LOG(LogTemp, Warning, TEXT("Hosting"));
}

