// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainWidget.h"
#include <../../../../../../../Source/Runtime/UMG/Public/Components/TextBlock.h>

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	TestWidgetAnimationEvent.BindDynamic(this, &UMainWidget::PlayNextAnimation);
	
	BindToAnimationFinished(Guide, TestWidgetAnimationEvent);
	

	
	FString CurrentMessage = TEXT("드디어 된다. 야호");
	Text->SetText(FText::FromString(CurrentMessage));
	PlayNextAnimation();


}

void UMainWidget::PlayNextAnimation()
{

	
	PlayAnimation(Guide);

}
