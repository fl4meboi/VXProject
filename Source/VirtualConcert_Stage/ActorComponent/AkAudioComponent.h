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
public:
	

	virtual void BeginPlay() override;
	FOnAkPostEventCallback BindCallback;

	UFUNCTION()
	void CallbackVFX(EAkCallbackType CallbackType, UAkCallbackInfo* CallbackInfo);

	
	// --------------Variable-------------
	TArray<class AVFX*> Fireworks;
	TArray<class AVFX*> BeamVer1;
	TArray<class AVFX*> BeamVer2;
	TArray<class AVFX*> Cloud;
	
	class ATP_ThirdPersonCharacter* Player;


	// --------------Variable-------------
	

	// --------------Function-------------
	void PlayAkEvent();

	// --------------Function-------------


};
