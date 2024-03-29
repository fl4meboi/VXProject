// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DisplayActor.generated.h"

UCLASS()
class VIRTUALCONCERT_STAGE_API ADisplayActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADisplayActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	// ---------------Component----------------

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UMaterialComponent* MatComp;

	// ---------------Component---------------


	// ---------------Variable-----------------
	class UMaterialInstanceDynamic* DynMat;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* SrcMaterial;
	
	// ---------------Variable-----------------
};
