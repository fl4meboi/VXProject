// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialActor/MaterialActor.h"
#include "../ActorComponent/MaterialComponent.h"

// Sets default values
AMaterialActor::AMaterialActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if(TempMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(TempMesh.Object);
	}

	MeshComp->SetCollisionProfileName(FName("ReactObject"));

	
	
	MatComp = CreateDefaultSubobject<UMaterialComponent>(TEXT("MatComp"));
}

// Called when the game starts or when spawned
void AMaterialActor::BeginPlay()
{
	Super::BeginPlay();
	

	//UMaterialInterface* SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/M_Rectangle.M_Rectangle'")));

	if(SrcMaterial)
	{
		DynMat = MeshComp->CreateDynamicMaterialInstance(0, SrcMaterial);
	}

	// 라이프 싸이클로 인해, 컴포넌트에게 액터 정보 넘겨주기
	MatComp->SetDynMat(DynMat);

}

// Called every frame
void AMaterialActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

