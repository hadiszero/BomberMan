// Fill out your copyright notice in the Description page of Project Settings.

#include "BomberMan.h"
#include "CPPPickUpBase.h"


// Sets default values
ACPPPickUpBase::ACPPPickUpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void ACPPPickUpBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPPickUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPPPickUpBase::OnPicked(ACPPCharacter* pCharacter)
{
	if (!pCharacter)
		return;

	switch (m_ePickUpType)
	{
	case ePUT_Longer:
	{
		pCharacter->OnBlastLengthPickupCPP();
		break;
	}
	case ePUT_More:
	{
		pCharacter->OnBombCntPickupCPP();
		break;
	}
	case ePUT_Faster:
	{
		pCharacter->OnRunSpeedPickupCPP();
		break;
	}
	case ePUT_Remote:
	{
		pCharacter->OnPowerUpPickupCPP();
		break;
	}
	default:
		break;
	}

	GWorld->DestroyActor(this);
}