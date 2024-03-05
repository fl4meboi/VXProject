#include "MaterialActor/SplitRenderActor.h"
#include "../ActorComponent/MaterialComponent.h"
ASplitRenderActor::ASplitRenderActor()
{
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

void ASplitRenderActor::BeginPlay()
{
	Super::BeginPlay();
	

	UMaterialInterface* SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/Custom/RenderTarget/Rectangle/M_Rectangle.M_Rectangle'")));

	if (SrcMaterial)
	{
		DynMat = MeshComp->CreateDynamicMaterialInstance(0, SrcMaterial);
	}

	// 라이프 싸이클로 인해, 컴포넌트에게 액터 정보 넘겨주기
	MatComp->SetDynMat(DynMat);

}

void ASplitRenderActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

