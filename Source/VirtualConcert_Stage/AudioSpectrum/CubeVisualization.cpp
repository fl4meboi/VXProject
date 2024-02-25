

#include "AudioSpectrum/CubeVisualization.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Components/AudioComponent.h>
#include "../ActorComponent/VisualizationComponent.h"

ACubeVisualization::ACubeVisualization()
{
	PrimaryActorTick.bCanEverTick = true;

	
	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	SetRootComponent(AudioComp);

	VisualizationComp = CreateDefaultSubobject<UVisualizationComponent>(TEXT("VisualizationComp"));

	// 노래 중복 없애기 위함.(델리게이트는 실행되기 위함.)
	AudioComp->SetVolumeMultiplier(0.01f);
}

void ACubeVisualization::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACubeVisualization::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

