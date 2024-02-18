
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Arrow.generated.h"

UCLASS()
class VIRTUALCONCERT_STAGE_API AArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	AArrow();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// -------------Comp --------------
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UVisibleComponent* VisibleComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UMaterialComponent* MatComp;

	// -------------Comp --------------
	
	// -------------Variable --------------
	UPROPERTY(VisibleAnywhere, Category = "Variable")
	UMaterialInstanceDynamic* DynMat;
	
	
	// -------------Variable --------------
	
	// -------------Function--------------
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	void UpDatate(float Delta);

	

	// -------------Function--------------

	

};
