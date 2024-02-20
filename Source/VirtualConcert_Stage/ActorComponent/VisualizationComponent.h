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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Variable")
	class USoundBase* Music;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Variable")
	float MusicDuration;
	// -------------------Variable -------------------


};
