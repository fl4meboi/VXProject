#include "AudioSpectrum/SoundCube.h"
#include "../ActorComponent/MaterialComponent.h"

ASoundCube::ASoundCube()
{
	PrimaryActorTick.bCanEverTick = true;


	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);

	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (TempMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(TempMesh.Object);
	}

	MeshComp->SetCollisionProfileName(FName("NoCollision"));



	MatComp = CreateDefaultSubobject<UMaterialComponent>(TEXT("MatComp"));


}

void ASoundCube::BeginPlay()
{
	Super::BeginPlay();
	

	

}

void ASoundCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASoundCube::SetMaterial(FLinearColor HSVtoRGB)
{
	
	UMaterialInterface* SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.MaterialInstanceConstant'/Game/__GDH/Metarials/MI_EmissiveLight.MI_EmissiveLight'")));


	if (SrcMaterial)
	{
		DynMat = MeshComp->CreateDynamicMaterialInstance(0, SrcMaterial);
	}

	MatComp->SetDynMat(DynMat);
	MatComp->SetColor(HSVtoRGB);

}

