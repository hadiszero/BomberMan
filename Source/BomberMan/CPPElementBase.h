// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CPPPickUpBase.h"
#include "GameFramework/Actor.h"
#include "CPPElementBase.generated.h"

UCLASS()
class BOMBERMAN_API ACPPElementBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPElementBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Gameplay)
		EPickUpType CheckDropPickUp();

	
	
};
