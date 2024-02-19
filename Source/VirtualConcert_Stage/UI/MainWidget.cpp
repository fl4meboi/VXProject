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
	
	if(4 == GuideNumber)
	{
		//한글 폰트는 TEXT로 한글을 받아야 안깨지는거 확인..
		FString CurrentMessage = TEXT("안녕하세요. VX Stuido에 오신걸 환영합니다.");
		Text->SetText(FText::FromString(CurrentMessage));


	}

	if (3 == GuideNumber)
	{

		FString CurrentMessage = TEXT("저희는 사용자의 입력이나, 환경 변화에 반응하여 시각효과를 보여주는 목표를 가지고 있습니다.");
		Text->SetText(FText::FromString(CurrentMessage));


	}

	if (2 == GuideNumber)
	{

		FString CurrentMessage = TEXT("사용자가 가상 환경에서 실제로 몰입할 수 있도록 도움을 주고 있습니다.");
		Text->SetText(FText::FromString(CurrentMessage));


	}

	if (1 == GuideNumber)
	{


		FString CurrentMessage = TEXT("사운드를 통해 보다 직관적이고, 몰입감 있는 상호작용을 경험할 수 있을 겁니다.");
		Text->SetText(FText::FromString(CurrentMessage));

	}

	if (0 == GuideNumber)
	{


		FString CurrentMessage = TEXT("아직은 부족한게 많지만, 나중에 보다 더 괜찮은 모습으로 나오겠습니다. ㅠ");
		Text->SetText(FText::FromString(CurrentMessage));


	}


	PlayAnimation(Guide);

}
