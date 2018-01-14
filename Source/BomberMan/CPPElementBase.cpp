// Fill out your copyright notice in the Description page of Project Settings.

#include "BomberMan.h"
#include "CPPElementBase.h"


// Sets default values
ACPPElementBase::ACPPElementBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPElementBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPPElementBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

