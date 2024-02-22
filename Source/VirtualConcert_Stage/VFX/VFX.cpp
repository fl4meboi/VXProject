// Fill out your copyright notice in the Description page of Project Settings.


#include "VFX/VFX.h"
#include "../ActorComponent/VFXActiveComponent.h"
#include "NiagaraComponent.h"

AVFX::AVFX()
{
	PrimaryActorTick.bCanEverTick = true;

	VFXActiveComp= CreateDefaultSubobject<UVFXActiveComponent>(TEXT("VFXActiveComp"));

	NiagaraComp = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComp"));
}

void AVFX::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVFX::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

