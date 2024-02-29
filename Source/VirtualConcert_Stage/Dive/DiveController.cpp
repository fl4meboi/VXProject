// Fill out your copyright notice in the Description page of Project Settings.


#include "Dive/DiveController.h"
#include "Dive/DiveLED.h"
#include <../../Engine/Classes/Kismet/GameplayStatics.h>
// Sets default values
ADiveController::ADiveController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADiveController::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> AllActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ADiveLED::StaticClass(), AllActors);
	for (auto TempActor : AllActors)
	{	
		LEDs.Add(Cast<ADiveLED>(TempActor));
	
	}
}

// Called every frame
void ADiveController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADiveController::RotateAllLED()
{
	for (int i = 0 ; i < LEDs.Num() ; i++)
	{
		if (i == 0)
		{
			LEDs[i]->RotateLED();

		}
		else if (i == 1)
		{
			LEDs[i]->RotateLED1();

		}
		else if (i == 2)
		{
			LEDs[i]->RotateLED2();

		}
		else if (i == 3)
		{
			LEDs[i]->RotateLED3();

		}


	}
}
