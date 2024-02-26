#include "ActorComponent/MaterialComponent.h"
#include "../Guide/Arrow.h"
#include "../MaterialActor/DisplayActor.h"

UMaterialComponent::UMaterialComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMaterialComponent::BeginPlay()
{
	Super::BeginPlay();

	//오너 저장
	Owner = GetOwner();

	DisplayActor = Cast<ADisplayActor>(Owner);

	if (DisplayActor)
	{

	//머티리얼 저장
	UMaterialInterface* SrcMaterial;
	
	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Drum.M_Drum'")));
	if (SrcMaterial)
	{
		SrcMaterials.Add(SrcMaterial);

	}
	
	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Flower.M_Flower'")));
	if (SrcMaterial)
	{
		SrcMaterials.Add(SrcMaterial);

	}

	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Flower2.M_Flower2'")));
	if (SrcMaterial)
	{
		SrcMaterials.Add(SrcMaterial);

	}

	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Flower3.M_Flower3'")));
	if (SrcMaterial)
	{
		SrcMaterials.Add(SrcMaterial);

	}

	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Line.M_Line'")));
	if (SrcMaterial)
	{
		SrcMaterials.Add(SrcMaterial);

	}

	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Pattern.M_Pattern'")));
	if (SrcMaterial)
	{
		SrcMaterials.Add(SrcMaterial);

	}

	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Pixels.M_Pixels'")));
	if (SrcMaterial)
	{
		SrcMaterials.Add(SrcMaterial);

	}

	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Rotate.M_Rotate'")));
	if (SrcMaterial)
	{
		SrcMaterials.Add(SrcMaterial);

	}

	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_RotateCircle.M_RotateCircle'")));
	if (SrcMaterial)
	{
		SrcMaterials.Add(SrcMaterial);

	}

	for (auto Temp : SrcMaterials)
	{
		auto TempDyn = DisplayActor->MeshComp->CreateDynamicMaterialInstance(0, Temp);
		DynMats.Add(TempDyn);
	}
	
	}
}

void UMaterialComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	Updatate(DeltaTime);

}
// 액터에서 호출 (라이프 사이클 문제 해결용)
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
	if (bIsRotateFlower == true)
	{
		if (DynMat == DynMats[3])
		{
			RotateFlower(Delta);
		}
		else
		{
			bIsRotateFlower = false;
		}
	}

}

void UMaterialComponent::OnEvent()
{

	MaterialTimeReset();
	OnSwitch();
}

// 머티리얼 시간을 0으로 리셋.
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

void UMaterialComponent::MarkerSharp()
{
	if (DisplayActor)
	{
		DisplayActor->MeshComp->SetMaterial(0, DynMats[0]);

	}

}

void UMaterialComponent::MarkerTempo()
{

	if (DisplayActor)
	{
		DisplayActor->MeshComp->SetMaterial(0, DynMats[5]);

	}

}

void UMaterialComponent::MarkerRaise()
{
	if (DisplayActor)
	{
		DisplayActor->MeshComp->SetMaterial(0, DynMats[2]);
		DynMat = DynMats[2];
		OnEvent();
	}

}

void UMaterialComponent::MarkerElectronic()
{
	if (DisplayActor)
	{
		DisplayActor->MeshComp->SetMaterial(0, DynMats[3]);
		DynMat = DynMats[3];
		OnEvent();
		bIsRotateFlower = true;
	}
}

void UMaterialComponent::RotateFlower(float Delta)
{
	if(CurrentA >= 0.99f)
	{
		RaiseLerp = false;
	}
	if (CurrentA <= 0.01f)
	{
		RaiseLerp = true;
	}
	if (RaiseLerp == false)
	{
		CurrentA = FMath::Lerp(CurrentA, 0.0f, Delta);
		DynMat->SetScalarParameterValue(FName("Rotate"), CurrentA);

	}
	else if (RaiseLerp == true)
	{
		CurrentA = FMath::Lerp(CurrentA, 1.0f, Delta);
		DynMat->SetScalarParameterValue(FName("Rotate"), CurrentA);
		
	}

	//FString str = FString::Printf(TEXT("%f"), CurrentA);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, str);

}

void UMaterialComponent::MarkerReady()
{
	if (DisplayActor)
	{
		DisplayActor->MeshComp->SetMaterial(0, DynMats[8]);
		DynMat = DynMats[8];
	}
}