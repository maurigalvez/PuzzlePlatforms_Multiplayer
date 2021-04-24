// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success)
		return false;
	// Initialize buttons
	if (this->HostButton == nullptr) return false;	
	this->HostButton->OnClicked.AddDynamic(this, &UMainMenu::Host);

	if (this->JoinButton == nullptr) return false;
	this->JoinButton->OnClicked.AddDynamic(this, &UMainMenu::GoToJoinMenu);

	if (this->BackToMenuButton == nullptr) return false;
	this->BackToMenuButton->OnClicked.AddDynamic(this, &UMainMenu::GoToMainMenu);

	if (this->JoinGameButton == nullptr) return false;
	this->JoinGameButton->OnClicked.AddDynamic(this, &UMainMenu::Join);

	return true;
}

void UMainMenu::GoToJoinMenu()
{
	if (this->MenuSwitcher == nullptr || this->JoinMenu == nullptr) return;
	// switch to join menu
	this->MenuSwitcher->SetActiveWidget(this->JoinMenu);
}

void UMainMenu::GoToMainMenu()
{
	if (this->MenuSwitcher == nullptr || this->MainMenu == nullptr) return;
	// switch to main menu
	this->MenuSwitcher->SetActiveWidget(this->MainMenu);
}

void UMainMenu::Host()
{
	if (this->MenuInterface != nullptr)
	{
		this->MenuInterface->Host();
	}
}

void UMainMenu::Join()
{
	// check if textbox is not null
	if (this->IPAddressTextBox == nullptr) return;

	if (this->MenuInterface != nullptr)
	{
		FText text = this->IPAddressTextBox->GetText();
		if (!text.IsEmpty())
		{
			const FString& Address = text.ToString();
			this->MenuInterface->Join(Address);
		}
	}
}

