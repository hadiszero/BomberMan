// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPPCharacter.h"
#include "GameFramework/Actor.h"
#include "CPPPickUpBase.generated.h"

UENUM()
enum EPickUpType
{
	ePUT_Longer,
	ePUT_More,
	ePUT_Faster,
	ePUT_Remote
};

UCLASS()
class BOMBERMAN_API ACPPPickUpBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPPickUpBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Cfg)
	TEnumAsByte<EPickUpType>				m_ePickUpType;

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	void				OnPicked(ACPPCharacter* pCharacter);
};
