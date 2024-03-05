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
	
	UAkAudioComponent(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	FOnAkPostEventCallback BindCallback;

	UFUNCTION()
	void CallbackVFX(EAkCallbackType CallbackType, UAkCallbackInfo* CallbackInfo);

	
	// --------------Variable-------------
	UPROPERTY(VisibleAnywhere ,Category = "Variable")
	TArray<class AVFX*> Fireworks;
	UPROPERTY(VisibleAnywhere ,Category = "Variable")
	TArray<class AVFX*> Fireworks2;
	TArray<class AVFX*> Fish;
	UPROPERTY(VisibleAnywhere ,Category = "Variable")
	TArray<class AVFX*> FireworksDelay;
	UPROPERTY(VisibleAnywhere ,Category = "Variable")
	TArray<class AVFX*> Assey;
	UPROPERTY(VisibleAnywhere ,Category = "Variable")
	TArray<class AVFX*> Swayle;
	UPROPERTY(VisibleAnywhere ,Category = "Variable")
	TArray<class AVFX*> Yall;
	UPROPERTY(VisibleAnywhere ,Category = "Variable")
	TArray<class AVFX*> Fish2;
	UPROPERTY(VisibleAnywhere ,Category = "Variable")
	TArray<class AVFX*> Hyrights;
	int32 TempI = 0;

	class ATP_ThirdPersonCharacter* Player;

	bool bPlayMusic;
	
	// --------------Variable-------------
	

	// --------------Function-------------
	void PlayAkEvent();
	void StopAkEvent();
	void ActiveFish();
	void ActiveFish2();
	void ActiveFirewoks();
	void ActiveFirewoks2();
	void ActiveFirewoksDelay();
	void ModifiedNiagara();
	void ActiveAssey();
	void ActiveSwayle();
	void ActiveYall();
	void ActiveHyrights();
	void ActiveEachHyright();
	// --------------Function-------------


};
