#include "ActorComponent/MaterialComponent.h"
#include "../Guide/Arrow.h"

UMaterialComponent::UMaterialComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMaterialComponent::BeginPlay()
{
	Super::BeginPlay();

	//오너 저장
	Owner = GetOwner();

	


}

void UMaterialComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	Updatate(DeltaTime);

}
// 액터에서 호출 (라이프 사이클 문제 해결용)
void UMaterialComponent::SetDynMat(UMaterialInstanceDynamic* DMObj)
{

	// 여기 나중에 부모 자식관계로 코드 간략화하기
	

		this->DynMat = DMObj;
		UE_LOG(LogTemp, Warning, TEXT("MatComp : %s"), *this->DynMat->GetName());


}

void UMaterialComponent::DisolveAlpha(float Delta)
{
		
	CurrentA = FMath::Lerp(CurrentA, 0.0f, Delta);

	if(CurrentA > 0.0f)
	{
		DynMat->SetScalarParameterValue(FName("AlphaIntensity"), CurrentA);
	}

}

void UMaterialComponent::Updatate(float Delta)
{
	if(bIsDesolve == true)
	{
			DisolveAlpha(Delta);
	}

}

