// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponent/AkAudioComponent.h"
#include <../../CoreUObject/Public/UObject/UObjectGlobals.h>

UAkAudioComponent::UAkAudioComponent(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{


}

void UAkAudioComponent::BeginPlay()
{
	Super::BeginPlay();
	static FName CBName("CallbackVFX");
	BindCallback.BindUFunction(this, CBName);

	PostAssociatedAkEvent(4, BindCallback);
}

void UAkAudioComponent::CallbackVFX(EAkCallbackType CallbackType, UAkCallbackInfo* CallbackInfo)
{

	UAkMarkerCallbackInfo* CBInfo = Cast<UAkMarkerCallbackInfo>(CallbackInfo);
	
	
	if (CBInfo->Label == "Sharp")
	{
	
	}
	else if (CBInfo->Label == "Tempo")
	{
		
	}

	

}
