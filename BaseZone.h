// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseZone.generated.h"

USTRUCT(BlueprintType)
struct FZoneInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BG Structs")
	float DelayedStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BG Structs")
	float MovingTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BG Structs")
	float ScaleToDecrease = 0.1f;
};

UCLASS()
class BATTLEGROUND_API ABaseZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Override the Construction Event
	virtual void OnConstruction(const FTransform& Transform) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* ZoneMesh;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Server, Reliable)
	void StartMovingZone();

	UFUNCTION(Server, Reliable)
	void Server_StartMovingZone();

	UFUNCTION(Server, Reliable)
	void Server_RecallServerMovement();

	UFUNCTION(Server, Reliable)
	void Server_CalculateZoneMovementTimer();

	UFUNCTION(NetMulticast, Reliable)
	void Multi_StartMovingZone(const FVector NewLocation);

	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "BG Variables")
	float Radius;

	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "BG Variables")
	float Height;

	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "BG Variables")
	int32 CurrentStepNumber;

	UPROPERTY(EditAnywhere, BLueprintReadWrite, Category = "BG Variables")
	TArray<FZoneInfo> ZoneInfoArray;

	FTimerHandle MovingTimerHandle;
	FTimerHandle RecallTimerHandle;
	FTimerHandle CalculateMovingTimerHandle;

};
