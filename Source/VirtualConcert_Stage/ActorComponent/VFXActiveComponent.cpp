

#include "ActorComponent/VFXActiveComponent.h"
#include "NiagaraComponent.h"
#include "../VFX/VFX.h"
#include "NiagaraDataInterfaceArrayFloat.h"
#include "NiagaraDataInterfaceArrayFunctionLibrary.h"
#include "NiagaraFunctionLibrary.h"

UVFXActiveComponent::UVFXActiveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UVFXActiveComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	VfxObject = Cast<AVFX>(Owner);
}


void UVFXActiveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}

void UVFXActiveComponent::ActiveVFX()
{
	if(VfxObject)
	{
		VfxObject->NiagaraComp->ActivateSystem(true);
	}

}

void UVFXActiveComponent::ModifedUserParameter()
{
	if (VfxObject)
	{
		FVector Temp = FVector(100.0f , 100.0f ,100.0f);
		VfxObject->NiagaraComp->SetVectorParameter(FName("Velocity"), Temp);

	}
}
// 빔일때만
void UVFXActiveComponent::ModifyLocation(FVector startLoc, FVector dir, float speed, int32 segment, float interval)
{

	TArray<FVector> linePositions;

	for (int32 i = 0; i < segment; i++)
	{

		// dir 방향으로 segment 회만큼 interval 간격(초)으로 반복해서 이동했을 위치를 계산한다.
		float elapsedTime = interval * i;
		FVector gravityVec = FVector(0, 0, GetWorld()->GetDefaultGravityZ());
		FVector newLocation = startLoc + dir * speed * elapsedTime + (0.5f * gravityVec * elapsedTime * elapsedTime);

		/*FHitResult hitInfo;
		if (i > 0 && GetWorld()->LineTraceSingleByChannel(hitInfo, linePositions[i - 1], newLocation, ECC_Visibility))
		{
			
			linePositions.Add(hitInfo.ImpactPoint);
			UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), hitInfo.ImpactPoint.X, hitInfo.ImpactPoint.Y , hitInfo.ImpactPoint.Z);

			break;
		}*/

		// 계산 결과 값들은 배열 변수에 담아놓는다.
		linePositions.Add(newLocation);
		UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), newLocation.X, newLocation.Y, newLocation.Z);

		

	}
	// 계산된 위치들을 선으로 연결해서 그린다.
	for (int32 i = 0; i < linePositions.Num() - 1; i++)
	{
		DrawDebugLine(GetWorld(), linePositions[i], linePositions[i + 1], FColor::Green, false, 1.0f, 0, 2.0f);

	}
	
	if (VfxObject)
	{
		if (VfxObject->NiagaraComp)
		{
			
				UE_LOG(LogTemp, Warning, TEXT("%s"), *VfxObject->GetActorNameOrLabel());

			
		}
	}

	UNiagaraDataInterfaceArrayFunctionLibrary::SetNiagaraArrayVector(VfxObject->NiagaraComp, FName("Array"), linePositions);

}
