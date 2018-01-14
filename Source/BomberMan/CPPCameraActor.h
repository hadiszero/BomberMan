// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPPCharacter.h"
#include "Camera/CameraActor.h"
#include "CPPCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ACPPCameraActor : public ACameraActor
{
	GENERATED_BODY()

		void UpdateCameraLocation();
	
public:
	ACPPCameraActor();

	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = GamePlay)
	void SetCharacter(ACPPCharacter* pP1, ACPPCharacter* pP2);

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Cfg)
	ACPPCharacter*		m_pP1;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Cfg)
	ACPPCharacter*		m_pP2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
	float				m_fCameraMinHeight;
};
