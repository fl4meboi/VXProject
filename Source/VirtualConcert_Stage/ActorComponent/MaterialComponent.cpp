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


		this->DynMat = DMObj;


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

void UMaterialComponent::OnBindWithBlueprint()
{

	MaterialTimeReset();
	OnSwitch();

}

// ��Ƽ���� �ð��� 0���� ����.
void UMaterialComponent::MaterialTimeReset()
{
	
	float CurrentGameTime = GetWorld()->GetTimeSeconds();
	DynMat->SetScalarParameterValue(FName("SetStartTime"), CurrentGameTime);

}

void UMaterialComponent::OnSwitch()
{
	
	DynMat->SetScalarParameterValue(FName("OnActive"),1.0f);

}

void UMaterialComponent::SetSplats(float Count)
{
	DynMat->SetScalarParameterValue(FName("SplatsAbsolute"),Count );
}

void UMaterialComponent::SetColor(FLinearColor HSVtoRGB)
{
	DynMat->SetVectorParameterValue(FName("Color"), HSVtoRGB);
}