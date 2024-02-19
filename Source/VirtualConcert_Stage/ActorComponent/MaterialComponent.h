#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MaterialComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VIRTUALCONCERT_STAGE_API UMaterialComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMaterialComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// -------------------Varaible-----------------
	UPROPERTY(VisibleAnywhere, Category = "Variable")
	class AActor* Owner;

	UPROPERTY(VisibleAnywhere, Category = "Variable")
	class UMaterialInstanceDynamic* DynMat;
	
	//상태머신 
	bool bIsDesolve = false;

	float CurrentA = 1.0f;

	// -------------------Varaible-----------------
	 
	
	
	// -------------------Function-----------------
	
	void SetDynMat(class UMaterialInstanceDynamic* DMObj);
	
	void DisolveAlpha(float Delta);

	void Updatate(float Delta);

	
	// 비쥬얼 오디오 임시 연결용 BlueprintCallable	
	
	UFUNCTION(BlueprintCallable)
	void OnBindWithBlueprint();
	
	void MaterialTimeReset();

	void OnSwitch();


	// 스플릿 개수 임시 적용
	UFUNCTION(BlueprintCallable)
	void SetSplats(float Count);

	void SetColor(FLinearColor HSVtoRGB);

	// -------------------Function-----------------



};
