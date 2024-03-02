

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
// ���϶���
void UVFXActiveComponent::ModifyLocation(FVector startLoc, FVector dir, float speed, int32 segment, float interval)
{

	TArray<FVector> linePositions;

	for (int32 i = 0; i < segment; i++)
	{

		// dir �������� segment ȸ��ŭ interval ����(��)���� �ݺ��ؼ� �̵����� ��ġ�� ����Ѵ�.
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

		// ��� ��� ������ �迭 ������ ��Ƴ��´�.
		linePositions.Add(newLocation);
		UE_LOG(LogTemp, Warning, TEXT("%f %f %f"), newLocation.X, newLocation.Y, newLocation.Z);

		

	}
	// ���� ��ġ���� ������ �����ؼ� �׸���.
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
