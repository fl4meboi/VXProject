#include "ActorComponent/VisualizationComponent.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "../TP_ThirdPerson/PC.h"
#include "../AudioSpectrum/CubeVisualization.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Components/AudioComponent.h>
#include <../../../../../../../Source/Runtime/Engine/Classes/Sound/SoundCue.h>
#include "../AudioSpectrum/SoundCube.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Kismet/KismetMathLibrary.h>
#include <../../../../../../../Plugins/Runtime/AudioSynesthesia/Source/AudioSynesthesia/Classes/ConstantQNRT.h>

UVisualizationComponent::UVisualizationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	//���� ť ����
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
	MusicDuration = Music->Duration;

	//Spawn the Audio Cube
	SoundCubes = SpawnSoundCubes(NumberCubes, CubeSpace);

}


void UVisualizationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

TArray<ASoundCube*> UVisualizationComponent::SpawnSoundCubes(int32 NumberOfCubes, float CubeSpacing)
{

	TArray<ASoundCube*> SpawnedCubes;

	for (int i = 0; i < NumberOfCubes; i++)
	{
		FVector CompLoc = CubeVisualization->AudioComp->GetComponentLocation();
		FVector MyLoc = CompLoc + FVector(0.0f, (float)i * CubeSpacing, 0.0f);
		FTransform MyTrans(FRotator(0.0f), MyLoc, FVector(0.1f));

		FActorSpawnParameters Params;
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		ASoundCube* SpawnedCube = GetWorld()->SpawnActor<ASoundCube>(ASoundCube::StaticClass(), MyTrans, Params);

		double normal = UKismetMathLibrary::NormalizeToRange((double) i , 0 , 96);
		normal *= 360.0;
		FLinearColor SpectrumCol = UKismetMathLibrary::HSVToRGB(normal, 1.0f ,1.0f ,1.0f );
		SpawnedCube->SetMaterial(SpectrumCol);

		if (SpawnedCube)
		{
			SpawnedCubes.Add(SpawnedCube);
		}
	}

	return SpawnedCubes;
}

void UVisualizationComponent::Synesthesia_ScaleCubes(float MusicDur, float Percent, TArray<class ASoundCube*> SoundCube)
{
	PositionInAudio = MusicDur * Percent;

}

