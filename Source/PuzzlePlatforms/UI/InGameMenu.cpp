// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"
#include "Components/Button.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success)
		return false;

	// initialize buttons
	if (this->ResumeGameButton == nullptr) return false;

	if (this->ExitGameButton == nullptr) return false;

	return true;
}