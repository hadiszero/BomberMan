// Fill out your copyright notice in the Description page of Project Settings.

#include "BomberMan.h"
#include "CPPCameraActor.h"
#include "Kismet/KismetMathLibrary.h"


ACPPCameraActor::ACPPCameraActor()
{
	PrimaryActorTick.bCanEverTick = true;
	m_fCameraMinHeight = 700.0f;
}

void ACPPCameraActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdateCameraLocation();
}

void ACPPCameraActor::BeginPlay()
{
	GetCameraComponent()->AspectRatio = 1.0f;

	Super::BeginPlay();
}

void ACPPCameraActor::SetCharacter(ACPPCharacter* pP1, ACPPCharacter* pP2)
{
	if (pP1)
	{
		m_pP1 = pP1;
	}

	if (pP2)
	{
		m_pP2 = pP2;
	}
}

void ACPPCameraActor::UpdateCameraLocation()
{
	if (!m_pP1 || !m_pP2)
		return;

	FVector fP1Location = m_pP1->GetActorLocation();
	FVector fP2Location = m_pP2->GetActorLocation();

	float fDist = UKismetMathLibrary::VSize(fP1Location - fP2Location);

	FVector fCenter = FMath::Lerp(fP1Location, fP2Location, 0.5f);

	float fXLen = FMath::Abs(fP1Location.X - fP2Location.X) / 2.0f;
	float fYLen = FMath::Abs(fP1Location.Y - fP2Location.Y) / 2.0f;

	float fCameraZ = (fXLen > fYLen ? fXLen : fYLen) + 300.0f;

	SetActorLocation(FVector(fCenter.X, fCenter.Y, fCameraZ < m_fCameraMinHeight ? m_fCameraMinHeight : fCameraZ));
}
