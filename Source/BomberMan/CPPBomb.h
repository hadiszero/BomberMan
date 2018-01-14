// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPPCharacter.h"
#include "GameFramework/Actor.h"
#include "CPPBomb.generated.h"

UCLASS()
class BOMBERMAN_API ACPPBomb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPBomb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TickCountDown(float DeltaTime);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Gameplay)
	float		m_fCountDown;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Gameplay)
	float		m_fBlastLength;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Gameplay)
	bool		m_bRemoteBomb;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Gameplay)
	ACPPCharacter*	m_pOwner;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Gameplay)
	bool			m_bTriggered;

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void		TriggerExplode();

	UFUNCTION(BlueprintImplementableEvent, Category = Gameplay)
	void		OnExplode();
};
