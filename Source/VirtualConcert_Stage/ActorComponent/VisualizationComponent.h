#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VisualizationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIRTUALCONCERT_STAGE_API UVisualizationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UVisualizationComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// -------------------Variable -------------------
	class AActor* Owner;

	class ACubeVisualization* CubeVisualization;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	class USoundBase* Music;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Variable")
	float MusicDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	int32 NumberCubes = 96;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	float CubeSpace = 20.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Variable")
	TArray<class ASoundCube *> SoundCubes;


	// 꼭 에디터에서 넣어주기
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	class UConstantQNRT* Synesthesia_Analysis;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Variable")
	TSubclassOf<class ASoundCube> Temp100; 


	// -------------------Variable -------------------
	
	// -------------------Function-------------------

	UFUNCTION(BlueprintCallable)
	TArray<class ASoundCube*> SpawnSoundCubes(int32 NumberOfCubes, float CubeSpacing);

	UFUNCTION(BlueprintCallable)
	void Synesthesia_ScaleCubes(float MusicDur,float Percent, TArray<class ASoundCube*> SoundCube);

	UFUNCTION()
	void FOnAudioPlaybackPercent(const class USoundWave* PlayingSoundWave, const float PlaybackPercent);

	// -------------------Function-------------------


};
