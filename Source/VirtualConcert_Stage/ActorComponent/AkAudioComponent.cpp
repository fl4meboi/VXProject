// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponent/AkAudioComponent.h"
#include <../../CoreUObject/Public/UObject/UObjectGlobals.h>
#include "../VFX/VFX.h"
#include <../../Engine/Classes/Kismet/GameplayStatics.h>
#include "VFXActiveComponent.h"
#include "../TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "../MaterialActor/DisplayActor.h"
#include "MaterialComponent.h"

void UAkAudioComponent::BeginPlay()
{
	Super::BeginPlay();
	
	Player = Cast<ATP_ThirdPersonCharacter>(GetOwner());
	
	static FName CBName("CallbackVFX");
	BindCallback.BindUFunction(this, CBName);


	//마커와 반응할 vfx 등록 찾기
	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AVFX::StaticClass(), AllActors);
	
	// ======================등록 검색===========================
	for(auto TempVfx : AllActors)
	{
		if (TempVfx->GetName().Contains("BP_Fireworks") == true)
		{
				Fireworks.Add(Cast<AVFX>(TempVfx));
		}
		else if (TempVfx->GetName().Contains("BP_BeamVer1") == true)
		{
			BeamVer1.Add(Cast<AVFX>(TempVfx));
		}
		else if (TempVfx->GetName().Contains("BP_BeamVer2") == true)
		{
			BeamVer2.Add(Cast<AVFX>(TempVfx));
		}
		else if (TempVfx->GetName().Contains("BP_Cloud") == true)
		{
			Cloud.Add(Cast<AVFX>(TempVfx));
		}
	}

	// ======================등록 검색===========================

}

void UAkAudioComponent::CallbackVFX(EAkCallbackType CallbackType, UAkCallbackInfo* CallbackInfo)
{

	UAkMarkerCallbackInfo* CBInfo = Cast<UAkMarkerCallbackInfo>(CallbackInfo);
	
	
	if (CBInfo->Label == "Sharp")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Sharp"));
		for(auto ActiveVfx : Fireworks)
		{
			ActiveVfx->VFXActiveComp->ActiveVFX();
		}
		Player->DisplayActorObjects[0]->MatComp->MarkerSharp();

	}
	else if (CBInfo->Label == "Tempo")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Tempo"));
		for (auto ActiveVfx : BeamVer1)
		{
			ActiveVfx->VFXActiveComp->ActiveVFX();
		}
		Player->DisplayActorObjects[0]->MatComp->MarkerTempo();

	}
	else if (CBInfo->Label == "Add")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Add"));
		for (auto ActiveVfx : BeamVer2)
		{
			ActiveVfx->VFXActiveComp->ActiveVFX();
		}
	}
	else if (CBInfo->Label == "Raise")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Raise"));
		for (auto ActiveVfx : Cloud)
		{
			ActiveVfx->VFXActiveComp->ActiveVFX();
		}
		Player->DisplayActorObjects[0]->MatComp->MarkerRaise();
	}
	else if (CBInfo->Label == "Electronic")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Electronic"));
		Player->DisplayActorObjects[0]->MatComp->MarkerElectronic();



	}
	else if (CBInfo->Label == "Swayle")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Swayle"));
	}
	else if (CBInfo->Label == "Yall")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Yall"));
	}
	else if (CBInfo->Label == "Assey")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Assey"));
	}
	else if (CBInfo->Label == "Tempo")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Tempo"));
	}
	else if (CBInfo->Label == "Ready")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Ready"));
		Player->DisplayActorObjects[0]->MatComp->MarkerReady();

	}
	else if (CBInfo->Label == "Stop")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Stop"));
	}

}

void UAkAudioComponent::PlayAkEvent()
{
	PostAssociatedAkEvent(4, BindCallback);

}
