// Fill out your copyright notice in the Description page of Project Settings.

#include "BomberMan.h"
#include "CPPGameMode.h"





ACPPGameMode::ACPPGameMode()
{
	ResetRate();

	m_iSceneWidth = 30;
	m_iSceneHeight = 30;
}

void ACPPGameMode::ResetRate()
{
	m_iDRate = 60;
	m_iUDRate = 20;
}

void ACPPGameMode::StartPlay()
{
	m_fSceneBaseX = -(m_iSceneWidth / 2.0f * 100.0f);
	m_fSceneBaseY = -(m_iSceneHeight / 2.0f * 100.0f);

	Super::StartPlay();
}

TArray<FSingleElementInfo> ACPPGameMode::GenerateMap(int iWidth, int iHeight)
{
	if (m_iDRate + m_iUDRate > 100)
	{
		ResetRate();
	}

	const int iAbsEmptyAreaWidth = 2;
	const int iAbsEmptyAreaHeight = 2;

	TArray<FSingleElementInfo> eaMap;

	if (iWidth < 4 || iHeight < 4)
		return eaMap;

	for (int i = 0; i < iHeight; ++i)
	{
		for (int j = 0; j < iWidth; ++j)
		{
			FSingleElementInfo oSingleElementInfo;
			if ((i < iAbsEmptyAreaWidth && j < iAbsEmptyAreaHeight)
				|| (iHeight - 1 - i) < iAbsEmptyAreaWidth && (iWidth - 1 - j) < iAbsEmptyAreaHeight)
			{
				oSingleElementInfo.m_eElementType = eET_None;
			}
			else
			{
				int iRandRate = rand() % 100;
				if (iRandRate < m_iUDRate)
				{
					oSingleElementInfo.m_eElementType = eET_UD;
				}
				else if (iRandRate < (m_iUDRate + m_iDRate))
				{
					oSingleElementInfo.m_eElementType = eET_D;
				}
				else
				{
					oSingleElementInfo.m_eElementType = eET_None;
				}
			}

			int iCurElementIndex = eaMap.Num();
			
			oSingleElementInfo.m_fX = m_fSceneBaseX + iCurElementIndex % iWidth * 100 + 50.0f;
			oSingleElementInfo.m_fY = m_fSceneBaseY + iCurElementIndex / iWidth * 100 + 50.0f;

			eaMap.Add(oSingleElementInfo);
		}
	}

 	return eaMap;
}

void ACPPGameMode::SetFloorWallScaleAndLocation(EFloorWallType eType, AActor* pActor)
{
	if (!pActor)
		return;

	switch (eType)
	{
	case eFWT_Floor:
	{
		pActor->SetActorScale3D(FVector(m_iSceneWidth, m_iSceneHeight, 1.0f));
		break;
	}
	case eFWT_Top:
	{
		pActor->SetActorScale3D(FVector(m_iSceneWidth, 1.0f, 1.0f));
		pActor->SetActorLocation(FVector(0.0f, float(m_iSceneHeight) / 2.0f * (-100.0f) - 50.0f, 50.0f));
		break;
	}
	case eFWT_Bottom:
	{
		pActor->SetActorScale3D(FVector(m_iSceneWidth, 1, 1));
		pActor->SetActorLocation(FVector(0.0f, float(m_iSceneHeight) / 2.0f * (100.0f) + 50.0f, 50.0f));
		break;
	}
	case eFWT_Left:
	{
		pActor->SetActorScale3D(FVector(m_iSceneHeight, 1, 1));
		pActor->SetActorLocation(FVector(float(m_iSceneWidth) / 2.0f * (-100.0f) - 50.0f, 0.0f, 50.0f));
		break;
	}
	case eFWT_Right:
	{
		pActor->SetActorScale3D(FVector(m_iSceneHeight, 1, 1));
		pActor->SetActorLocation(FVector(float(m_iSceneWidth) / 2.0f * (100.0f) + 50.0f, 0.0f, 50.0f));
		break;
	}
	default:
		break;
	}
}
