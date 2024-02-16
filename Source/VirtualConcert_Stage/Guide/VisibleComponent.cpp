
#include "Guide/VisibleComponent.h"
UVisibleComponent::UVisibleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UVisibleComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();

	//UE_LOG(LogTemp,Warning,TEXT("%s"), *Owner->GetActorNameOrLabel());

}

void UVisibleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UVisibleComponent::Elevate(float Delta)
{

	if(bIsElevator)
	{

		CurrentA = FMath::Lerp(CurrentA, 100.0f, Delta);
		FVector CurrentPos = Owner->GetActorLocation();
		if (CurrentA < 100.0f)
		{
			float Displacement = CurrentA - Latest;

			CurrentPos.Z += Displacement;
			Owner->SetActorLocation(CurrentPos);

		}
		Latest = CurrentA;

	}


}

void UVisibleComponent::DeStroyActor()
{

	// 2ÃÊ µÚ ÆÄ±«
	FTimerHandle handle;
	Owner->GetWorldTimerManager().SetTimer(handle, FTimerDelegate::CreateLambda([&]
	{

		Owner->Destroy();

	}), 2, false);
}
