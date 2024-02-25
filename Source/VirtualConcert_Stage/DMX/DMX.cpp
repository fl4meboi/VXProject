#include "DMX/DMX.h"
#include "MySpotLightComponent.h"

ADMX::ADMX()
{
	PrimaryActorTick.bCanEverTick = true;

	HeadBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadBase"));
	SetRootComponent(HeadBase);
	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh(TEXT("/Script/Engine.StaticMesh'/Game/AudioSynesthesia/demo/Mesh/SM_MovingHead_Base.SM_MovingHead_Base'"));
	if (TempMesh.Succeeded())
	{
		HeadBase->SetStaticMesh(TempMesh.Object);

	}

	HeadArm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadArm"));
	HeadArm->SetupAttachment(HeadBase);
	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh2(TEXT("/Script/Engine.StaticMesh'/Game/AudioSynesthesia/demo/Mesh/SM_MovingHead_Yoke.SM_MovingHead_Yoke'"));
	if (TempMesh2.Succeeded())
	{
		HeadArm->SetStaticMesh(TempMesh2.Object);

	}

	HeadHead = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadHead"));
	HeadHead->SetupAttachment(HeadArm);
	ConstructorHelpers::FObjectFinder<UStaticMesh> TempMesh3(TEXT("/Script/Engine.StaticMesh'/Game/AudioSynesthesia/demo/Mesh/SM_MovingHead_Head.SM_MovingHead_Head'"));
	if (TempMesh3.Succeeded())
	{
		HeadHead->SetStaticMesh(TempMesh3.Object);

	}
	HeadHead->SetRelativeLocation(FVector(0.0, 0.0, 27.260201));

	SpotComp = CreateDefaultSubobject<UMySpotLightComponent>(TEXT("SpotComp"));
	SpotComp->SetupAttachment(HeadHead);
	SpotComp->SetRelativeLocation(FVector(0.0, 0.0, 5.581896));
	SpotComp->SetRelativeRotation(FRotator(90, 0, 0));

}

void ADMX::BeginPlay()
{
	Super::BeginPlay();

}

void ADMX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

