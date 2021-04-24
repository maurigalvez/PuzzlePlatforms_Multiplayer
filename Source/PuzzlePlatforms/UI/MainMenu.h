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

protected:
	virtual bool Initialize();

private:
	UFUNCTION()
	void Host();

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton = nullptr;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton = nullptr;

	IMenuInterface* MenuInterface;
};
