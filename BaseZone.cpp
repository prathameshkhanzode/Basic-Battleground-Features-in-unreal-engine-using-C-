// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseZone.h"


// Sets default values
ABaseZone::ABaseZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
		
	bReplicates = true;
	SetReplicateMovement(true);
	ZoneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Zone Mesh"));
	SetRootComponent(ZoneMesh);

}

// Called when the game starts or when spawned
void ABaseZone::BeginPlay()
{
	Super::BeginPlay();
	StartMovingZone();
	
}

void ABaseZone::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	ZoneMesh->SetWorldScale3D(FVector(Radius, Radius, Height));
}

// Called every frame
void ABaseZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseZone::Server_RecallServerMovement_Implementation()
{
	StartMovingZone();
}

void ABaseZone::Server_CalculateZoneMovementTimer_Implementation()
{
	GetWorld()->GetTimerManager().ClearTimer(MovingTimerHandle);
}

void ABaseZone::Server_StartMovingZone_Implementation()
{
	FVector LocalVector;
	LocalVector = FVector(ZoneMesh->GetComponentScale().X - ZoneInfoArray[CurrentStepNumber - 1].ScaleToDecrease, ZoneMesh->GetComponentScale().Y - ZoneInfoArray[CurrentStepNumber - 1].ScaleToDecrease, Height);
	UE_LOG(LogTemp, Warning, TEXT("Server Function called"));
	Multi_StartMovingZone(LocalVector);
}

void ABaseZone::StartMovingZone_Implementation()
{
	if (CurrentStepNumber < ZoneInfoArray.Num())
	{
		GetWorld()->GetTimerManager().SetTimer(MovingTimerHandle, this, &ABaseZone::Server_StartMovingZone, 0.01f, true);
		GetWorld()->GetTimerManager().SetTimer(CalculateMovingTimerHandle, this, &ABaseZone::Server_CalculateZoneMovementTimer, ZoneInfoArray[CurrentStepNumber].MovingTime, false);
		float TotalTime = ZoneInfoArray[CurrentStepNumber].DelayedStart + ZoneInfoArray[CurrentStepNumber].MovingTime;
		GetWorld()->GetTimerManager().SetTimer(RecallTimerHandle, this, &ABaseZone::Server_RecallServerMovement, TotalTime, false);
		CurrentStepNumber++;
	}
}

void ABaseZone::Multi_StartMovingZone_Implementation(const FVector NewLocation)
{
	if (ZoneMesh)
	{
		ZoneMesh->SetRelativeScale3D(NewLocation);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Zone Mesh Not Valid"));
	}
}

