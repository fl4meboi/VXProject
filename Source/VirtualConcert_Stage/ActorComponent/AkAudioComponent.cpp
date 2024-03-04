// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponent/AkAudioComponent.h"
#include <../../CoreUObject/Public/UObject/UObjectGlobals.h>
#include "../VFX/VFX.h"
#include <../../Engine/Classes/Kismet/GameplayStatics.h>
#include "VFXActiveComponent.h"
#include "../TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "../MaterialActor/DisplayActor.h"
#include "MaterialComponent.h"
#include "../AI/AI.h"
#include <../../LevelSequence/Public/LevelSequence.h>
#include <../../MovieScene/Public/MovieSceneSequencePlaybackSettings.h>
#include <../../LevelSequence/Public/LevelSequencePlayer.h>
#include "../AudioSpectrum/MyAudioSynesthesia.h"
#include "../AudioSpectrum/CubeVisualization.h"


UAkAudioComponent::UAkAudioComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	

}

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
		else if (TempVfx->GetName().Contains("BP_Ver2Fireworks") == true)
		{
			Fireworks2.Add(Cast<AVFX>(TempVfx));
		}
		else if (TempVfx->GetName().Contains("BP_DelayFireworks") == true)
		{
			FireworksDelay.Add(Cast<AVFX>(TempVfx));
		}
		else if (TempVfx->GetName().Contains("BP_Fish") == true)
		{
			Fish.Add(Cast<AVFX>(TempVfx));
		}
		else if (TempVfx->GetName().Contains("BP_Assey") == true)
		{
			Assey.Add(Cast<AVFX>(TempVfx));
		}
		else if (TempVfx->GetName().Contains("BP_Swayle") == true)
		{
			Swayle.Add(Cast<AVFX>(TempVfx));
		}
		else if (TempVfx->GetName().Contains("BP_Yall") == true)
		{
			Yall.Add(Cast<AVFX>(TempVfx));
		}
		else if (TempVfx->GetName().Contains("BP_Ver2Fish") == true)
		{
			Fish2.Add(Cast<AVFX>(TempVfx));
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
		ActiveFirewoks();
		ActiveFish();
		for (auto ActiveDisplay : Player->DisplayActorObjects)
		{
			ActiveDisplay->MatComp->MarkerSharp();
		}
		

	}
	else if (CBInfo->Label == "Dj")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Dj"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->bIsFade = true;
		}

	}
	else if (CBInfo->Label == "DjOff")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("DjOff"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->bIsEnd = true;
		}

	}
	else if (CBInfo->Label == "type2")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type2"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(2);
		}

	}
	else if (CBInfo->Label == "type3")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type3"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(3);
		}

	}
	else if (CBInfo->Label == "type4")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type4"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(4);
		}

	}
	else if (CBInfo->Label == "type5")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type5"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(5);
		}

	}
	else if (CBInfo->Label == "type6")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type6"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(6);
		}

	}
	else if (CBInfo->Label == "type7")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type7"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(7);
		}

	}
	else if (CBInfo->Label == "type8")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type8"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(8);
		}

	}
	else if (CBInfo->Label == "type9")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type9"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(9);
		}

	}
	else if (CBInfo->Label == "type10")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type10"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(10);
		}

	}
	else if (CBInfo->Label == "type11")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type11"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(11);
		}

		}
	else if (CBInfo->Label == "type12")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type12"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(12);
		}

		}
	else if (CBInfo->Label == "type13")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type13"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(13);
		}

		}
	else if (CBInfo->Label == "type14")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type14"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(14);
		}

		}
	else if (CBInfo->Label == "type15")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type15"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(15);
		}

		}
	else if (CBInfo->Label == "type16")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type16"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(16);
		}

		}
	else if (CBInfo->Label == "type17")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type17"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(17);
		}

	}
	else if (CBInfo->Label == "type18")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type18"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(18);
		}

	}
	else if (CBInfo->Label == "type19")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type19"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(19);
		}
		
	}
	else if (CBInfo->Label == "type20")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type20"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(20);
		}

	}
	else if (CBInfo->Label == "type21")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type21"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(21);
		}

	}
	else if (CBInfo->Label == "type22")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type22"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(22);
		}

		}
	else if (CBInfo->Label == "type23")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type23"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(23);
		}

		}
	else if (CBInfo->Label == "type24")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type24"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(24);
		}

		}
	else if (CBInfo->Label == "type25")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type25"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(25);
		}

		}
	else if (CBInfo->Label == "type26")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("type26"));
		for (auto ActiveAI : Player->AIObjects)
		{
			ActiveAI->PlayMontageAction(26);
		}

		}
	else if (CBInfo->Label == "Tempo")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Tempo"));
		for (auto ActiveDisplay : Player->DisplayActorObjects)
		{
			ActiveDisplay->MatComp->MarkerTempo();
		}
		ActiveFirewoks2();

	}
	else if (CBInfo->Label == "Add")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Add"));
		
	}
	else if (CBInfo->Label == "Raise")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Raise"));
		
		for (auto ActiveDisplay : Player->DisplayActorObjects)
		{
			ActiveDisplay->MatComp->MarkerRaise();
		}
		ActiveFirewoks();


	}
	else if (CBInfo->Label == "Electronic")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Electronic"));
		for (auto ActiveDisplay : Player->DisplayActorObjects)
		{
			ActiveDisplay->MatComp->MarkerElectronic();
		}
		ActiveFirewoksDelay();

	}
	else if (CBInfo->Label == "Swayle")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Swayle"));
		ActiveSwayle();
	}
	else if (CBInfo->Label == "Yall")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Yall"));
		ActiveYall();
	}
	else if (CBInfo->Label == "Assey")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Assey"));
		ActiveAssey();
	}
	else if (CBInfo->Label == "Tempo")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Tempo"));
	}
	else if (CBInfo->Label == "Ready")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Ready"));
		for (auto ActiveDisplay : Player->DisplayActorObjects)
		{
			ActiveDisplay->MatComp->MarkerReady();
		}

	}
	else if (CBInfo->Label == "Stop")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Stop"));
	}
	else if (CBInfo->Label == "Fish")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Fish"));
		ActiveFish();
	}
	else if (CBInfo->Label == "Fish2")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Fish2"));
		ActiveFish2();

	}
	else if (CBInfo->Label == "LEDRotate")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("LEDRotate"));
		Player->RotateLED();

	}
	else if (CBInfo->Label == "LEDLoc")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("LEDLoc"));
		Player->PlaySequenceLEDLoc();
	}
	else if (CBInfo->Label == "LEDLocRev")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("LEDLocRev"));
		Player->ReverseSequenceLEDLoc();
	}
	else if (CBInfo->Label == "LEDScale")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("LEDScale"));
		Player->PlaySequenceLEDScale();
	}
	else if (CBInfo->Label == "LEDScaleRev")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("LEDScaleRev"));
		Player->ReverseSequenceLEDScale();
	}
	else if (CBInfo->Label == "DMX")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("DMX"));
		Player->PlaySequenceDMX();
	}
	else if (CBInfo->Label == "SharkDive")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("SharkDive"));
		Player->PlaySequenceSharkDive();
	}
	else if (CBInfo->Label == "SharkWave")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("SharkDive"));
		Player->PlaySequenceSharkWave();
	}
	else if (CBInfo->Label == "Finish")
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Finish"));
		Player->AudioSynesthesia->StopMusic();
		Player->CubeVisualization->StopMusic();
		bPlayMusic = false;
	}

}

void UAkAudioComponent::PlayAkEvent()
{
	if (bPlayMusic == false)
	{
		PostAssociatedAkEvent(4, BindCallback);
		bPlayMusic= true;
	}
	else
	{
		StopAkEvent();
		bPlayMusic = false;
	}

}

void UAkAudioComponent::StopAkEvent()
{
	Stop();
}

void UAkAudioComponent::ActiveFish()
{
	for (auto ActiveVfx : Fish)
	{
		ActiveVfx->VFXActiveComp->ActiveVFX();
	}

}

void UAkAudioComponent::ActiveFish2()
{
	for (auto ActiveVfx : Fish2)
	{
		ActiveVfx->VFXActiveComp->ActiveVFX();
	}


}

void UAkAudioComponent::ActiveFirewoks()
{
	for (auto ActiveVfx : Fireworks)
	{
		ActiveVfx->VFXActiveComp->ActiveVFX();
	}

}

void UAkAudioComponent::ActiveFirewoks2()
{
	for (auto ActiveVfx : Fireworks)
	{
		ActiveVfx->VFXActiveComp->ActiveVFX();
	}

	FTimerHandle handle;
	Player->GetWorldTimerManager().SetTimer(handle, FTimerDelegate::CreateLambda([&]
	{

		for (auto ActiveVfx : Fireworks2)
		{
			ActiveVfx->VFXActiveComp->ActiveVFX();
		}

	}), 1.0f, false);


}

void UAkAudioComponent::ActiveFirewoksDelay()
{
	for (auto ActiveVfx : FireworksDelay)
	{
		ActiveVfx->VFXActiveComp->ActiveVFX();
	}

}

void UAkAudioComponent::ModifiedNiagara()
{
	for (auto ActiveVfx : Fish)
	{
		ActiveVfx->VFXActiveComp->ModifedUserParameter();
	}

}
void UAkAudioComponent::ActiveAssey()
{
	for (auto ActiveVfx : Assey)
	{
		ActiveVfx->VFXActiveComp->ActiveVFX();
	}
}

void UAkAudioComponent::ActiveSwayle()
{
	for (auto ActiveVfx : Swayle)
	{
		ActiveVfx->VFXActiveComp->ActiveVFX();
	}
}

void UAkAudioComponent::ActiveYall()
{
	for (auto ActiveVfx : Yall)
	{
		ActiveVfx->VFXActiveComp->ActiveVFX();
	}
}