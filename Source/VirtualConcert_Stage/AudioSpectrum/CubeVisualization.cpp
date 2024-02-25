

#include "AudioSpectrum/CubeVisualization.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Components/AudioComponent.h>
#include "../ActorComponent/VisualizationComponent.h"

ACubeVisualization::ACubeVisualization()
{
	PrimaryActorTick.bCanEverTick = true;

	
	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));
	SetRootComponent(AudioComp);

	VisualizationComp = CreateDefaultSubobject<UVisualizationComponent>(TEXT("VisualizationComp"));

	// �뷡 �ߺ� ���ֱ� ����.(��������Ʈ�� ����Ǳ� ����.)
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

