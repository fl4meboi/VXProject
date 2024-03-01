// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/AI.h"
#include <../../Engine/Classes/Animation/AnimMontage.h>

// Sets default values
AAI::AAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI::BeginPlay()
{
	Super::BeginPlay();
	

	//머티리얼 저장
	UMaterialInterface* SrcMaterial;

	SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Blueprint/Player/M_HoloAI.M_HoloAI'")));
	if (SrcMaterial)
	{
		DynMat = GetMesh()->CreateDynamicMaterialInstance(0, SrcMaterial);
		GetMesh()->SetMaterial(1, DynMat);
		GetMesh()->SetMaterial(2, DynMat);
	}


}

// Called every frame
void AAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsFade)
	{
		FadeMaterial(DeltaTime);
	}
	if (bIsEnd) 
	{
		EndMaterial(DeltaTime);
	}
}

// Called to bind functionality to input
void AAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAI::FadeMaterial(float Delta)
{
	CurrentA = FMath::Lerp(CurrentA, -1.0f , Delta);

	
		DynMat->SetScalarParameterValue(FName("FadeAmount"), CurrentA);
	

	if (CurrentA <= -0.99f)
	{
		bIsFade =false;
	}
}

void AAI::EndMaterial(float Delta)
{
	CurrentA = FMath::Lerp(CurrentA, 1.0f, Delta);


	DynMat->SetScalarParameterValue(FName("FadeAmount"), CurrentA);


	if (CurrentA >= 0.99f)
	{
		bIsEnd = false;
	}
}

// type2 ~ 15
void AAI::PlayMontageAction(int32 Number)
{
	FString Str = FString::Printf(TEXT("type%d"), Number);
	FName SectionName = FName(*Str);
	PlayAnimMontage(ActionMontage,1 ,SectionName);
}

