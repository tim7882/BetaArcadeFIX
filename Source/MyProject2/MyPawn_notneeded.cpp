// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn_notneeded.h"

// Sets default values
AMyPawn_notneeded::AMyPawn_notneeded()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyPawn_notneeded::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn_notneeded::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn_notneeded::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

