// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DiveLED.generated.h"

UCLASS()
class VIRTUALCONCERT_STAGE_API ADiveLED : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADiveLED();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// ----------------Component ------------------
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class USceneComponent* LED;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UChildActorComponent* LED1;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UChildActorComponent* LED2;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UChildActorComponent* LED3;	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UChildActorComponent* LED4;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class URotatingMovementComponent* RotatingMovementComp;
	// ----------------Component ------------------

	// ----------------Function -------------------
	
	void RotateLED();
	void RotateLED1();
	void RotateLED2();
	void RotateLED3();


	// ----------------Function -------------------

};
