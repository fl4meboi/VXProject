// Fill out your copyright notice in the Description page of Project Settings.


#include "Dive/DiveLED.h"
#include <../../Engine/Classes/GameFramework/RotatingMovementComponent.h>

// Sets default values
ADiveLED::ADiveLED()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LED = CreateDefaultSubobject<USceneComponent>(TEXT("LED"));
	SetRootComponent(LED);

	LED1 = CreateDefaultSubobject<UChildActorComponent>(TEXT("LED1"));
	LED1->SetupAttachment(LED);
	LED1->SetRelativeLocationAndRotation(FVector(0.0f,230.0f,-240.0f), FRotator(0.0f,0.0f,0.0f));
	LED2 = CreateDefaultSubobject<UChildActorComponent>(TEXT("LED2"));
	LED2->SetupAttachment(LED);
	LED2->SetRelativeLocationAndRotation(FVector(0.0f, -220.0f, 230.0f), FRotator(0.0f, 0.0f, 90.0f));

	LED3 = CreateDefaultSubobject<UChildActorComponent>(TEXT("LED3"));
	LED3->SetupAttachment(LED);
	LED3->SetRelativeLocationAndRotation(FVector(0.0f, -220.0f, -230.0f), FRotator(0.0f, 0.0f, 90.0f));

	LED4 = CreateDefaultSubobject<UChildActorComponent>(TEXT("LED4"));
	LED4->SetupAttachment(LED);
	LED4->SetRelativeLocationAndRotation(FVector(0.0f, -230.0f, -240.0f), FRotator(0.0f, 0.0f, 0.0f));

	RotatingMovementComp = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("RotatingMovementComp"));
	RotatingMovementComp->RotationRate = FRotator(0.0f , 0.0f, 0.0f);
} 

// Called when the game starts or when spawned
void ADiveLED::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ADiveLED::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADiveLED::RotateLED()
{
	RotatingMovementComp->RotationRate = FRotator(0.0f, 0.0f, 45.0f);

}

void ADiveLED::RotateLED1()
{
	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, FTimerDelegate::CreateLambda([&]
	{
		RotateLED();
	}), 0.2f, false);
}

void ADiveLED::RotateLED2()
{
	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, FTimerDelegate::CreateLambda([&]
	{
		RotateLED();
	}), 0.4f, false);
}

void ADiveLED::RotateLED3()
{
	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, FTimerDelegate::CreateLambda([&]
	{
		RotateLED();
	}), 0.6f, false);
}

