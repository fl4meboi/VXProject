

#include "ActorComponent/VFXActiveComponent.h"
#include "NiagaraComponent.h"
#include "../VFX/VFX.h"
UVFXActiveComponent::UVFXActiveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UVFXActiveComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	VfxObject = Cast<AVFX>(Owner);
}


void UVFXActiveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UVFXActiveComponent::ActiveVFX()
{
	if(VfxObject)
	{
		VfxObject->NiagaraComp->ActivateSystem(true);
	}

}

