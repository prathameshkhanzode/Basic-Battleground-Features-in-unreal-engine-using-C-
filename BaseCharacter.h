// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include "BaseCharacter.generated.h"


UCLASS()
class BATTLEGROUND_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Create Variables

	// Define Input Keys

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BG Variables")
		FString MoveForwardKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BG Variables")
		FString MoveRightKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BG Variables")
		FString LookUpKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BG Variables")
		FString TurnKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BG Variables")
		FString JumpKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BG Variables")
		FString SprintKey;

	//Max Walk speed

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BG Variables")
		float MaxWalkSpeed;

	//Max Sprint speed

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BG Variables")
		float MaxSprintSpeed;

protected:

	void MoveForward(float AxisVal);
	void MoveRight(float AxisVal);
	void LookUp(float AxisVal);
	void Turn(float AxisVal);
	void Jump();
	void Sprint();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta =(AllowPrivateAccess=true))
	bool bPlayerIsSprinting;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	UCameraComponent* CameraComponent;
};
