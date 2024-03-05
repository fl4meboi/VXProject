// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/MainWidget.h"
#include <../../../../../../../Source/Runtime/UMG/Public/Components/TextBlock.h>

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();
	

	//델리게이트
	TestWidgetAnimationEvent.BindDynamic(this, &UMainWidget::PlayNextAnimation);
	
	BindToAnimationFinished(Guide, TestWidgetAnimationEvent);
	//델리게이트


	PlayNextAnimation();


}

void UMainWidget::PlayNextAnimation()
{
	GuideNumber--;
	if(0 > GuideNumber)
	{
		return;		
	}
	
	if(3 == GuideNumber)
	{
		//한글 폰트는 TEXT로 한글을 받아야 안깨지는거 확인..
		FString CurrentMessage = TEXT("안녕하세요. VX Studio에 오신 것을 환영합니다.");
		Text->SetText(FText::FromString(CurrentMessage));


	}

	if (2 == GuideNumber)
	{

		FString CurrentMessage = TEXT("이 곳은 초현실적 사운드 홀로, 음악과 상호작용하며 특별한 경험을 즐길 수 있는 공간입니다.");
		Text->SetText(FText::FromString(CurrentMessage));


	}

	if (1 == GuideNumber)
	{

		FString CurrentMessage = TEXT("오디오비주얼 퍼포먼스를 통해 보다 직관적이고 몰입감 있는 체험을 하실 수 있습니다.");
		Text->SetText(FText::FromString(CurrentMessage));


	}

	if (0 == GuideNumber)
	{


		FString CurrentMessage = TEXT("즐거운 관람되시기를 바랍니다.");
		Text->SetText(FText::FromString(CurrentMessage));

	}



	PlayAnimation(Guide);

}
