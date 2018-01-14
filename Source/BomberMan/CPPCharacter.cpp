// Fill out your copyright notice in the Description page of Project Settings.

#include "BomberMan.h"
#include "CPPCharacter.h"


// Sets default values
ACPPCharacter::ACPPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_iPlayerID = 0;
	m_fBlastLength = 100.0f;
	m_iMaxBombCnt = 1;
	m_iCurBombCnt = 1;
	m_iMaxRemoteBombCnt = 0;
	m_iCurRemoteBombCnt = 0;
	m_fLeftPowerUpTime = -1.0f;
}

// Called when the game starts or when spawned
void ACPPCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (m_iPlayerID != 1 && m_iPlayerID != 2)
	{
		GWorld->DestroyActor(this);
	}

	m_pGM = Cast<ACPPGameMode>(UGameplayStatics::GetGameMode(this));
	m_pGI = Cast<UCPPGameInstance>(UGameplayStatics::GetGameInstance(this));

	if (m_fLeftPowerUpTime > 0.0f)
	{
		OnPoweredUp();
	}
}

// Called every frame
void ACPPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TickPowerUpStatus(DeltaTime);
	UpdateStatusString();
}

void ACPPCharacter::UpdateStatusString()
{
	if (!m_pGI)
		return;

	char caBuf[512];
	sprintf_s(caBuf, "Bomb: %d/%d\nRemoteBomb: %d/%d\nScore: %d", 
		m_iCurBombCnt, m_iMaxBombCnt, m_iCurRemoteBombCnt, m_iMaxRemoteBombCnt, 
		m_iPlayerID == 1 ? m_pGI->m_iP1Score : m_pGI->m_iP2Score);

	m_sStatusString = ANSI_TO_TCHAR(caBuf);
}

void ACPPCharacter::TickPowerUpStatus(float DeltaTime)
{
	if (m_fLeftPowerUpTime < 0.0f)
	{
		return;
	}

	m_fLeftPowerUpTime -= DeltaTime;
	if (m_fLeftPowerUpTime < 0.0f)
	{
		m_fLeftPowerUpTime = -1.0f;
		m_iMaxRemoteBombCnt = 0;
		m_iCurRemoteBombCnt = 0;

		OnPowerUpTimeUp();
	}
}

// Called to bind functionality to input
void ACPPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ACPPCharacter::OnBlastLengthPickupCPP()
{
	if (!m_pGM)
		return;

	m_fBlastLength += m_pGM->m_fBlastLengthDelta;
}

void ACPPCharacter::OnBombCntPickupCPP()
{
	m_iMaxBombCnt += 1;
	m_iCurBombCnt += 1;
}

void ACPPCharacter::OnRunSpeedPickupCPP()
{
	if (!m_pGM)
		return;

	UCharacterMovementComponent* pMovement = Cast<UCharacterMovementComponent>(GetMovementComponent());
	if (pMovement)
	{
		pMovement->MaxWalkSpeed += m_pGM->m_fSpeedPickupMaxSpeedDelta;
		pMovement->MaxAcceleration += m_pGM->m_fSpeedPickupAccelerationDelta;
	}
}

void ACPPCharacter::OnPowerUpPickupCPP()
{
	if (!m_pGM)
		return;
	
	//	if we're already in powerup status, don't reset remote bomb count
	if (m_fLeftPowerUpTime < 0)
	{
		m_iCurRemoteBombCnt = 1;
		m_iMaxRemoteBombCnt = 1;
	}

	m_fLeftPowerUpTime = m_pGM->m_fPowerUpLast;
	
	OnPoweredUp();
}

bool ACPPCharacter::CanSpawnBombCPP()
{
	//	we'll set m_fLeftPowerUpTime to -1, when we are not powered up, 
	//	so we don't need to make a nearly equal here
	if (m_fLeftPowerUpTime > 0.0f)
	{
		return m_iCurRemoteBombCnt > 0 ? true : false;
	}
	else
	{
		return m_iCurBombCnt > 0 ? true : false;
	}
}

void ACPPCharacter::OnSpawnBombCPP()
{
	//	we'll set m_fLeftPowerUpTime to -1, when we are not powered up, 
	//	so we don't need to make a nearly equal here
	if (m_fLeftPowerUpTime > 0.0f)
	{
		m_iCurRemoteBombCnt = FMath::Clamp(--m_iCurRemoteBombCnt, 0, m_iMaxRemoteBombCnt);
	}
	else
	{
		m_iCurBombCnt = FMath::Clamp(--m_iCurBombCnt, 0, m_iMaxBombCnt);
	}
}

void ACPPCharacter::OnBoooooomCPP(bool bRemoteBomb)
{
	if (bRemoteBomb)
	{
		m_iCurRemoteBombCnt = FMath::Clamp(++m_iCurRemoteBombCnt, 0, m_iMaxRemoteBombCnt);
	}
	else
	{
		m_iCurBombCnt = FMath::Clamp(++m_iCurBombCnt, 0, m_iMaxBombCnt);
	}
}

void ACPPCharacter::OnIgniteCPP()
{
	OnBoooooomCPP(true);
}
