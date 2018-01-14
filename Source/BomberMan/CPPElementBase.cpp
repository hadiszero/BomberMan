// Fill out your copyright notice in the Description page of Project Settings.

#include "BomberMan.h"
#include "CPPElementBase.h"


// Sets default values
ACPPElementBase::ACPPElementBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPElementBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPElementBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

EPickUpType ACPPElementBase::CheckDropPickUp()
{
	ACPPGameMode* pGM = Cast<ACPPGameMode>(UGameplayStatics::GetGameMode(this));
	if (!pGM)
		return ePUT_None;

	int iRate = rand() % 100;
	if (iRate < pGM->m_iPickupMoreBombRate)
	{
		return ePUT_More;
	}
	else if (iRate < pGM->m_iPickupMoreBombRate + pGM->m_iPickupLongerRate)
	{
		return ePUT_Longer;
	}
	else if (iRate < pGM->m_iPickupMoreBombRate + pGM->m_iPickupLongerRate + pGM->m_iPickupRunspeedRate)
	{
		return ePUT_Faster;
	}
	else if (iRate < pGM->m_iPickupMoreBombRate + pGM->m_iPickupLongerRate + pGM->m_iPickupRunspeedRate + pGM->m_iPickupPowerupRate)
	{
		return ePUT_Remote;
	}

	return ePUT_None;
}