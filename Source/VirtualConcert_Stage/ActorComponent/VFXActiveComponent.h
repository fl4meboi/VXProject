
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VFXActiveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIRTUALCONCERT_STAGE_API UVFXActiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UVFXActiveComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	// ---------------Variable-----------
	class AActor* Owner;
	class AVFX* VfxObject;
	// ---------------Variable-----------
	
	// ---------------Function-----------
	
	void ActiveVFX();
	
	// ---------------Function-----------


};
