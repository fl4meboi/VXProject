// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_ThirdPersonGameMode.h"
#include "TP_ThirdPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include <../../../../../../../Source/Runtime/UMG/Public/Blueprint/UserWidget.h>
#include "../UI/MainWidget.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Kismet/GameplayStatics.h>

ATP_ThirdPersonGameMode::ATP_ThirdPersonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ATP_ThirdPersonGameMode::BeginPlay()
{
	
	 MainWidget = Cast<UUserWidget>(CreateWidget(GetWorld(),MainFactory));
	 if (Cast<UMainWidget>(MainWidget))
	 {

			MainWidget->AddToViewport();		
	 }


	 // 마우스 커서 온
	 /*auto pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	 pc->SetShowMouseCursor(true);
	 */
}

