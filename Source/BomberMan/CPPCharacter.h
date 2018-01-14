// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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

	/** PlayerID, 1 or 2 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = GamePlay)
	int				m_iPlayerID;
	
};
