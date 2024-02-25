#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DMX.generated.h"

UCLASS()
class VIRTUALCONCERT_STAGE_API ADMX : public AActor
{
		GENERATED_BODY()
	
public:	
	ADMX();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:

	UPROPERTY(VisibleAnywhere, Category = Component)
	class UStaticMeshComponent* HeadBase;
	UPROPERTY(VisibleAnywhere, Category = Component)
	class UStaticMeshComponent* HeadArm;
	UPROPERTY(VisibleAnywhere, Category = Component)
	class UStaticMeshComponent* HeadHead;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = Component)
	class UMySpotLightComponent* SpotComp;

};
