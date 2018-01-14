// Fill out your copyright notice in the Description page of Project Settings.

#include "BomberMan.h"
#include "CPPBomb.h"


// Sets default values
ACPPBomb::ACPPBomb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_fCountDown = 3.0f;
	m_fBlastLength = 100.0f;
	m_bRemoteBomb = false;
	m_pOwner = nullptr;
	m_bTriggered = false;
}

// Called when the game starts or when spawned
void ACPPBomb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TickCountDown(DeltaTime);
}

void ACPPBomb::TickCountDown(float DeltaTime)
{
	m_fCountDown -= DeltaTime;

	if (m_fCountDown < 0.0f)
	{
		TriggerExplode();
	}
}

void ACPPBomb::TriggerExplode()
{
	PrimaryActorTick.bCanEverTick = false;
	m_bTriggered = true;

	if (m_pOwner)
		m_pOwner->OnBoooooomCPP(m_bRemoteBomb);

	OnExplode();
}