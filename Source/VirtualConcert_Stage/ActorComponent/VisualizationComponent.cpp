#include "ActorComponent/VisualizationComponent.h"

UVisualizationComponent::UVisualizationComponent()
{
	PrimaryComponentTick.bCanEverTick = true;



}


void UVisualizationComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UVisualizationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

