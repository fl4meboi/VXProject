#include "Guide/Arrow.h"
#include "VisibleComponent.h"
#include "../TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "../ActorComponent/MaterialComponent.h"
AArrow::AArrow()
{
	PrimaryActorTick.bCanEverTick = true;



	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Plane.Plane'"));
	if(TempMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(TempMesh.Object);
			
	}
	SetRootComponent(MeshComp);
	//�浹 ����
	MeshComp->SetCollisionProfileName(FName("ReactObject"));

	//�浹 �̺�Ʈ ����
	
	MeshComp->OnComponentBeginOverlap.AddDynamic(this,&AArrow::OnComponentBeginOverlap);

	

	VisibleComp = CreateDefaultSubobject<UVisibleComponent>(TEXT("VisibleComp"));
	MatComp = CreateDefaultSubobject<UMaterialComponent>(TEXT("MatComp"));
}

void AArrow::BeginPlay()
{
	Super::BeginPlay();
	
	//���׸��� ���� ����
	UMaterialInterface* SrcMaterial = Cast<UMaterialInterface>(StaticLoadObject(UMaterialInterface::StaticClass(), nullptr, TEXT("/Script/Engine.Material'/Game/__GDH/Metarials/M_Arrow.M_Arrow'")));
	DynMat = MeshComp->CreateDynamicMaterialInstance(0, SrcMaterial);
	
	
	// ������ ����Ŭ�� ����, ������Ʈ���� ���� ���� �Ѱ��ֱ�
	MatComp->SetDynMat(DynMat);
}

void AArrow::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpDatate(DeltaTime);

}

void AArrow::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if(auto Player = Cast<ATP_ThirdPersonCharacter>(OtherActor))
	{
		VisibleComp->bIsElevator = true;
		
		VisibleComp->DeStroyActor();
		
		MatComp->bIsDesolve = true;
	}

	


}

void AArrow::UpDatate(float Delta)
{

	
		VisibleComp->Elevate(Delta);
	


}
