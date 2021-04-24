// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetMenuInterface(IMenuInterface* NewMenuInterface);
	// Initialize main menu
	void Setup();
	// Removes Main menu and setup game input mode
	virtual void Remove();

protected:
	virtual bool Initialize();

private:
	UFUNCTION()
	void Host();

	UFUNCTION()
	void GoToJoinMenu();

	UFUNCTION()
	void GoToMainMenu();

	UFUNCTION()
	void Join();

// ----------
// PROPERTIES
// ----------
private:
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UWidget* MainMenu = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UWidget* JoinMenu = nullptr;
    // ---------
	// MAIN MENU
	// --------
	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton = nullptr;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton = nullptr;

	// ---------
	// JOIN MENU
	// --------
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinGameButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	class UButton* BackToMenuButton = nullptr;	

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* IPAddressTextBox = nullptr;

	IMenuInterface* MenuInterface;
};
