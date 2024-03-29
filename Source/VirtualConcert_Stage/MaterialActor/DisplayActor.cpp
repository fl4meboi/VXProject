// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialActor/DisplayActor.h"
#include "../ActorComponent/MaterialComponent.h"

// Sets default values
ADisplayActor::ADisplayActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Plane.Plane'"));

	if (TempMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(TempMesh.Object);
	}

	MeshComp->SetCollisionProfileName(FName("ReactObject"));



	MatComp = CreateDefaultSubobject<UMaterialComponent>(TEXT("MatComp"));
}

// Called when the game starts or when spawned
void ADisplayActor::BeginPlay()
{
	Super::BeginPlay();

	//UMaterialInterface* SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Brick.M_Brick'")));

	if (SrcMaterial)
	{
		DynMat = MeshComp->CreateDynamicMaterialInstance(0, SrcMaterial);
	}

	// 라이프 싸이클로 인해, 컴포넌트에게 액터 정보 넘겨주기
	MatComp->SetDynMat(DynMat);

}

// Called every frame
void ADisplayActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

