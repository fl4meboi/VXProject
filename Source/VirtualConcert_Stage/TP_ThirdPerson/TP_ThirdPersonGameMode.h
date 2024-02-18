// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TP_ThirdPersonGameMode.generated.h"

UCLASS(minimalapi)
class ATP_ThirdPersonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATP_ThirdPersonGameMode();

	// ---------------Variable ------------
	
	UPROPERTY(EditDefaultsOnly , Category = "Factory")
	class TSubclassOf<UUserWidget> MainFactory;
	
	UPROPERTY(VisibleAnywhere , Category = "UI")
	class UUserWidget* MainWidget;
	
	// ---------------Variable ------------
	
	// ---------------Function ------------
	virtual void BeginPlay()override;
	// ---------------Function ------------


};



