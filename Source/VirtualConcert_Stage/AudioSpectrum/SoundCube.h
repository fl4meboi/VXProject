
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundCube.generated.h"

UCLASS()
class VIRTUALCONCERT_STAGE_API ASoundCube : public AActor
{
	GENERATED_BODY()
	
public:	
	ASoundCube();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	
	// ---------------Component----------------

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	class UMaterialComponent* MatComp;

	// ---------------Component---------------




	// ---------------Variable-----------------
	class UMaterialInstanceDynamic* DynMat;
	
	
	UPROPERTY(EditAnywhere)
	class UMaterialInterface* SrcMaterial;
	
	
	// ---------------Variable-----------------
	






	// ---------------Function-----------------
	UFUNCTION(BlueprintCallable)
	void SetMyMaterial(FLinearColor HSVtoRGB);
	
	// ---------------Function-----------------


};
