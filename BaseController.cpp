// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseController.h"
#include "GameFramework/CharacterMovementComponent.h" 

// Sets default values
ABaseController::ABaseController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

