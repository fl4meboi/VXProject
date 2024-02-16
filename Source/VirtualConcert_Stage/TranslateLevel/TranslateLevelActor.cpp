// Fill out your copyright notice in the Description page of Project Settings.


#include "TranslateLevel/TranslateLevelActor.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Components/StaticMeshComponent.h>
#include <../../../../../../../Source/Runtime/Engine/Classes/Components/BoxComponent.h>
#include "../TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values
ATranslateLevelActor::ATranslateLevelActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 메쉬 생성
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	
	if(TempMesh.Succeeded())
	{
		MeshComp->SetStaticMesh(TempMesh.Object);
		MeshComp->SetRelativeScale3D(FVector(1.0f,1.0f,0.11f));
	}
	SetRootComponent(MeshComp);
	MeshComp->SetCollisionProfileName(FName("NoCollision"));

	// 충돌 생성
	
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
		
	CollisionComp->SetupAttachment(RootComponent);
	CollisionComp->SetRelativeScale3D(FVector(1.5f));
	
	// 충돌 설정 (프로필)
	CollisionComp->SetCollisionProfileName(FName("ReactObject"));

	// 충돌 이벤트 설정
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ATranslateLevelActor::OnComponentBeginOverlap);
}

// Called when the game starts or when spawned
void ATranslateLevelActor::BeginPlay()
{
	Super::BeginPlay();
	
	

}

// Called every frame
void ATranslateLevelActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATranslateLevelActor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if(auto Player = Cast<ATP_ThirdPersonCharacter>(OtherActor) && 
	!TransferLevelName.IsEmpty() )
	{

		UGameplayStatics::OpenLevel(this, FName(TransferLevelName));
	}
}

