// Fill out your copyright notice in the Description page of Project Settings.


#include "DMX/MySpotLightComponent.h"
#include "DMX.h"
#include <../../Engine/Classes/Kismet/KismetMathLibrary.h>


UMySpotLightComponent::UMySpotLightComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UMySpotLightComponent::BeginPlay()
{
	Super::BeginPlay();
	Owner = Cast<ADMX>(GetOwner());

	Delta = 0.067f;
	SetIntensity(160.0f);

	CurrentLight = GetLightColor();
	CurrentOuterAngle = OuterConeAngle;
}

void UMySpotLightComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

void UMySpotLightComponent::TurnUpLight()
{
	Owner->HeadHead->AddLocalRotation(FRotator(0, 0, Delta * 20.0));
}

void UMySpotLightComponent::TurnDownLight()
{
	Owner->HeadHead->AddLocalRotation(FRotator(0, 0, -1 * Delta * 20.0));
	//FString Log = FString::Printf(TEXT("%f"), -1 * Delta * 20.0);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Log);

}

void UMySpotLightComponent::TurnClockDirLight()
{
	Owner->HeadArm->AddLocalRotation(FRotator(0, Delta * 20.0, 0));
}

void UMySpotLightComponent::TurnUnClockDirLight()
{
	Owner->HeadArm->AddLocalRotation(FRotator(0, -1 * Delta * 20.0, 0));

}

void UMySpotLightComponent::SetClockLightColor()
{
	
	FLinearColor CurrentHSV = UKismetMathLibrary::RGBLinearToHSV(CurrentLight);
	CurrentHSV.R += Delta * 5;	
	CurrentHSV.G = 1.0f;
	CurrentHSV.B = 1.0f;
	CurrentHSV.R  = FMath::Fmod(CurrentHSV.R, 360.0f);
	
	FLinearColor LatestColor = CurrentHSV.HSVToLinearRGB();
	SetLightColor(LatestColor);
	FString Log = FString::Printf(TEXT("%f"), CurrentHSV.R);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Log);
	CurrentLight = LatestColor;

}

void UMySpotLightComponent::SetUnClockLightColor()
{
	FLinearColor CurrentHSV = UKismetMathLibrary::RGBLinearToHSV(CurrentLight);
	CurrentHSV.R -= Delta * 5;
	CurrentHSV.G = 1.0f;
	CurrentHSV.B = 1.0f;
	if (CurrentHSV.R < 0)
	{
		CurrentHSV.R +=360.0f;
	}

	FLinearColor LatestColor = CurrentHSV.HSVToLinearRGB();
	SetLightColor(LatestColor);
	FString Log = FString::Printf(TEXT("%f"), CurrentHSV.R);
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, Log);
	CurrentLight = LatestColor;
}

void UMySpotLightComponent::AddOuterAngle()
{
	CurrentOuterAngle += Delta;
	CurrentOuterAngle =	FMath::Clamp(CurrentOuterAngle,0.0f, 80.0f);
	SetOuterConeAngle(CurrentOuterAngle);
}

void UMySpotLightComponent::SubOuterAngle()
{
	CurrentOuterAngle -= Delta;
	CurrentOuterAngle = FMath::Clamp(CurrentOuterAngle, 0.0f, 80.0f);
	SetOuterConeAngle(CurrentOuterAngle);

}
