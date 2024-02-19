#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SplitRenderActor.generated.h"

UCLASS()
class VIRTUALCONCERT_STAGE_API ASplitRenderActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASplitRenderActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// ---------------Component----------------

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UMaterialComponent* MatComp;

	// ---------------Component---------------


	// ---------------Variable-----------------
	class UMaterialInstanceDynamic* DynMat;
	// ---------------Variable-----------------

};
