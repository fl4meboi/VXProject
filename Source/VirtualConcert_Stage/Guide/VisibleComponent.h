#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VisibleComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIRTUALCONCERT_STAGE_API UVisibleComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UVisibleComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	// -------------- Variable --------------
	class AActor* Owner;
	float CurrentA = 0.0f;
	float Latest = 0.0f;
	// 상태머신
	bool bIsElevator = false;

	// -------------- Variable --------------
	
	
	// -------------- Function --------------
	void Elevate(float Delta);
	void DeStroyActor();
	// -------------- Function --------------

};
