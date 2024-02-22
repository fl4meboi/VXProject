
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VFX.generated.h"

UCLASS()
class VIRTUALCONCERT_STAGE_API AVFX : public AActor
{
	GENERATED_BODY()
	
public:	
	AVFX();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	// ------------------Component -------------
	UPROPERTY(VisibleAnywhere ,Category ="Component")
	class UVFXActiveComponent* VFXActiveComp;
	
	UPROPERTY(EditAnywhere ,Category ="Component")
	class UNiagaraComponent* NiagaraComp;

	// ------------------Component -------------
};
