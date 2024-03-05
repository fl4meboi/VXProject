// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainWidget.generated.h"

/**
 * 
 */
UCLASS()
class VIRTUALCONCERT_STAGE_API UMainWidget : public UUserWidget
{
	GENERATED_BODY()
	

public:


	// ------------------------ Variable -----------------------
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Animation", Transient, meta = (BindWidgetAnim) )
	class UWidgetAnimation* Guide;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite , meta= (BindWidget), Category = "UI")
	class UTextBlock* Text;

	FWidgetAnimationDynamicEvent TestWidgetAnimationEvent;

	//상태머신
	int32 GuideNumber = 4;

	// ------------------------ Variable -----------------------

	// ------------------------ Function -----------------------

	virtual void NativeConstruct() override;

	UFUNCTION()
	void PlayNextAnimation();

	// ------------------------ Function -----------------------

};
