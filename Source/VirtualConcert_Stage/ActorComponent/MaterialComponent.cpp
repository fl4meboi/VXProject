#include "ActorComponent/MaterialComponent.h"
#include "../Guide/Arrow.h"

UMaterialComponent::UMaterialComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMaterialComponent::BeginPlay()
{
	Super::BeginPlay();

	//���� ����
	Owner = GetOwner();

	


}

void UMaterialComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	Updatate(DeltaTime);

}
// ���Ϳ��� ȣ�� (������ ����Ŭ ���� �ذ��)
void UMaterialComponent::SetDynMat(UMaterialInstanceDynamic* DMObj)
{

	// ���� ���߿� �θ� �ڽİ���� �ڵ� ����ȭ�ϱ�
	

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

