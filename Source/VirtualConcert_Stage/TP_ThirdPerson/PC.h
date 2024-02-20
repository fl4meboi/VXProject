// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PC.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALCONCERT_STAGE_API APC : public APlayerController
{
	GENERATED_BODY()
	
public:
	// -------------------Function ----------------

	void SetGameOnlyInputMode();

	// -------------------Function ----------------
};
