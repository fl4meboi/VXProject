// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SpotLightComponent.h"
#include "MySpotLightComponent.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALCONCERT_STAGE_API UMySpotLightComponent : public USpotLightComponent
{
	GENERATED_BODY()

public:
	UMySpotLightComponent();

	virtual void BeginPlay()override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// ------------------------- Variable ----------------------

	class ADMX* Owner;

	float Delta;

	FLinearColor CurrentLight;

	float CurrentOuterAngle;
	// ------------------------- Variable ----------------------


	// ------------------------- Function ----------------------

	void TurnUpLight();
	void TurnDownLight();
	void TurnClockDirLight();
	void TurnUnClockDirLight();

	void SetClockLightColor();
	void SetUnClockLightColor();
	
	void AddOuterAngle();
	void SubOuterAngle();

	// ------------------------- Function ----------------------

};
