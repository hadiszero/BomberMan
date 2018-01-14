// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "CPPGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API UCPPGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UCPPGameInstance();

public:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Gameplay)
	int			m_iP1Score;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = Gameplay)
	int			m_iP2Score;

	
};
