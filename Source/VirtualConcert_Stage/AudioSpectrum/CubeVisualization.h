#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeVisualization.generated.h"

UCLASS()
class VIRTUALCONCERT_STAGE_API ACubeVisualization : public AActor
{
	GENERATED_BODY()
	
public:	
	ACubeVisualization();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	
	// -------------------Component-------------
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UAudioComponent* AudioComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	class UVisualizationComponent* VisualizationComp;

	// -------------------Component-------------
	
	// -------------------Variable-------------


	// -------------------Variable-------------

	// -----------------Function-----------------
	void StopMusic();
	// -----------------Function-----------------

	
};
