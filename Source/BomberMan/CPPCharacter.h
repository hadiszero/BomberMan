// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPPGameMode.h"
#include "GameFramework/Character.h"
#include "CPPCharacter.generated.h"

UCLASS()
class BOMBERMAN_API ACPPCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPPCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void TickPowerUpStatus(float DeltaTime);

	/** PlayerID, 1 or 2 */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = GamePlay)
	int				m_iPlayerID;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = GamePlay)
	float			m_fBlastLength;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = GamePlay)
	int				m_iMaxBombCnt;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = GamePlay)
	int				m_iCurBombCnt;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = GamePlay)
	int				m_iMaxRemoteBombCnt;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = GamePlay)
	int				m_iCurRemoteBombCnt;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = GamePlay)
	float			m_fLeftPowerUpTime;

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void			OnBlastLengthPickupCPP();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void			OnBombCntPickupCPP();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void			OnRunSpeedPickupCPP();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void			OnPowerUpPickupCPP();

	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void			OnPoweredUp();

	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
		void			OnPowerUpTimeUp();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		bool			CanSpawnBombCPP();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void			OnSpawnBombCPP();

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void			OnBoooooomCPP(bool bRemoteBomb);

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		void			OnIgniteCPP();

private:
	ACPPGameMode*		m_pGM;

};
