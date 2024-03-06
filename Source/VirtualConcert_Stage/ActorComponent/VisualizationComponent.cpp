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

	//사운드 큐 생성
	static ConstructorHelpers::FObjectFinder<USoundCue> SoundCueAsset(TEXT("/Script/Engine.SoundCue'/Game/__GDH/Sound/Smile_You_re_On_Acid_Cue.Smile_You_re_On_Acid_Cue'"));
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

	//Bind Cube Scaling Visualization to Audio Playback
	CubeVisualization->AudioComp->OnAudioPlaybackPercent.AddDynamic(this, &UVisualizationComponent::FOnAudioPlaybackPercent);

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

		ASoundCube* SpawnedCube = GetWorld()->SpawnActor<ASoundCube>(Temp100, MyTrans, Params);

		double normal = UKismetMathLibrary::NormalizeToRange((double) i , 0 , 96);
		normal *= 360.0;
		FLinearColor SpectrumCol = UKismetMathLibrary::HSVToRGB(normal, 1.0f ,1.0f ,1.0f );
		SpawnedCube->SetMyMaterial(SpectrumCol);

		if (SpawnedCube)
		{
			SpawnedCubes.Add(SpawnedCube);
		}
	}

	return SpawnedCubes;
}

void UVisualizationComponent::Synesthesia_ScaleCubes(float MusicDur, float Percent, TArray<class ASoundCube*> SoundCube)
{
	float PositionInAudio = MusicDur * Percent;
	
	//반환값을 담기 위한 변수
	TArray<float> Frequencies;

	Synesthesia_Analysis->GetNormalizedChannelConstantQAtTime(PositionInAudio, 0 ,Frequencies);

	
	float ScalingFactor = 3.0f;

	for (int i = 0; i< Frequencies.Num();i++) 
	{
		float Temp = ScalingFactor*Frequencies[i];
		Temp = FMath::Pow(Temp ,1.5f);
		SoundCube[i]->MeshComp->SetRelativeScale3D(FVector(0.1f,0.1f,Temp));
	}

	

}

void UVisualizationComponent::FOnAudioPlaybackPercent(const USoundWave* PlayingSoundWave, const float PlaybackPercent)
{

	Synesthesia_ScaleCubes(MusicDuration, PlaybackPercent, SoundCubes);
	//FString str = FString::Printf(TEXT("%f"), PlaybackPercent);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, str);
	
}

