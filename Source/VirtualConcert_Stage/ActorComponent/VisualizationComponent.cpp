#include "ActorComponent/VisualizationComponent.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "../TP_ThirdPerson/PC.h"
#include "../AudioSpectrum/CubeVisualization.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Components/AudioComponent.h>
#include <../../../../../../../Source/Runtime/Engine/Classes/Sound/SoundCue.h>

UVisualizationComponent::UVisualizationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	//사운드 큐 생성
	static ConstructorHelpers::FObjectFinder<USoundCue> SoundCueAsset(TEXT("/Script/Engine.SoundCue'/Game/__GDH/Sound/SC_CHERE.SC_CHERE'"));
	if(SoundCueAsset.Succeeded())
	{
		Music = SoundCueAsset.Object;
	}
}


void UVisualizationComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();

	//Enable Input
	auto PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	Owner->EnableInput(PlayerController);
	if (auto PC = Cast<APC>(PlayerController))
	{
		PC->SetGameOnlyInputMode();
	}

	//Set Audio Source and Save Music Duration
	CubeVisualization = Cast<ACubeVisualization>(Owner);
	
	CubeVisualization->AudioComp->SetSound(Music);
	Music->Duration = MusicDuration;

}


void UVisualizationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

