// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameMode.h"
#include "CPPGameMode.generated.h"


UENUM()
enum EElementType
{
	eET_None,

	eET_UD,
	eET_D,
};

UENUM()
enum EFloorWallType
{
	eFWT_Floor,

	eFWT_Top,
	eFWT_Bottom,
	eFWT_Left,
	eFWT_Right
};

USTRUCT()
struct FSingleElementInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = BuildScene)
	TEnumAsByte<EElementType>	m_eElementType;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = BuildScene)
	float			m_fX;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = BuildScene)
	float			m_fY;

	FSingleElementInfo()
	{
		m_eElementType = eET_None;
		m_fX = 0.0f;
		m_fY = 0.0f;
	}
};

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ACPPGameMode : public AGameMode
{
	GENERATED_BODY()
	
	ACPPGameMode();

	UFUNCTION(BlueprintCallable, Category = GamePlay)
		TArray<FSingleElementInfo> GenerateMap(int iWidth, int iHeight);

	UFUNCTION(BlueprintCallable, Category = GamePlay)
		void SetFloorWallScaleAndLocation(EFloorWallType eType, AActor* pActor);

	void ResetRate();

public:
	virtual void StartPlay() override;

	/** please don't modify m_iSceneWidth and m_iSceneHeight, unless you know what you're doint */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
		int				m_iSceneWidth;

	/** please don't modify m_iSceneWidth and m_iSceneHeight, unless you know what you're doint */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
		int				m_iSceneHeight;

	/** m_iUDRate + m_iDRate should be <= 100 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
		int				m_iUDRate;

	/** m_iUDRate + m_iDRate should be <= 100 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
		int				m_iDRate;

	/** m_iPickupMoreBombRate + m_iPickupLongerRate + m_iPickupRunspeedRate + m_iPickupPowerupRate should be <= 100 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
		int				m_iPickupMoreBombRate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
		int				m_iPickupLongerRate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
		int				m_iPickupRunspeedRate;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
		int				m_iPickupPowerupRate;

	/** top left x */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Cfg)
		float			m_fSceneBaseX;

	/** top left y */
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Cfg)
		float			m_fSceneBaseY;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Cfg)
		float			m_fSpeedPickupMaxSpeedDelta;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Cfg)
		float			m_fSpeedPickupAccelerationDelta;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Cfg)
		float			m_fPowerUpLast;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Cfg)
		float			m_fBlastLengthDelta;
};
