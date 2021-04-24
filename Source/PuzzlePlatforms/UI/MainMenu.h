// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize();


private:
	UFUNCTION()
	void Host();

	UPROPERTY(meta = (BindWidget))
	class UButton* HostButton = nullptr;
	
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinButton = nullptr;
};
