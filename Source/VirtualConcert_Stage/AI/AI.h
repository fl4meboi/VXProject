// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AI.generated.h"

UCLASS()
class VIRTUALCONCERT_STAGE_API AAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Variable
	UPROPERTY(EditDefaultsOnly)
	class UMaterialInterface* SrcMaterial;
	
	
	class UMaterialInstanceDynamic* DynMat; 
	float CurrentA = 1.0f;
	bool bIsFade = false;
	bool bIsEnd = false;
	//Fucntion
	void FadeMaterial(float Delta);
	void EndMaterial(float Delta);
	//根鸥林 持绢林扁
	UPROPERTY(EditAnywhere, BlueprintReadWrite , Category = "Variable")
	class UAnimMontage* ActionMontage;
	
	void PlayMontageAction(int32 Number);
	
};
