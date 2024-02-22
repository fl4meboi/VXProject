// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AkComponent.h"
#include "AkAudioComponent.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALCONCERT_STAGE_API UAkAudioComponent : public UAkComponent
{
	GENERATED_BODY()
	
	UAkAudioComponent(const class FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	FOnAkPostEventCallback BindCallback;

	UFUNCTION()
	void CallbackVFX(EAkCallbackType CallbackType, UAkCallbackInfo* CallbackInfo);
};
