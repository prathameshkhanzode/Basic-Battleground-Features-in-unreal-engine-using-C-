// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Base_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class BATTLEGROUND_API UBase_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta =(AllowPrivateAccess=true))
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta =(AllowPrivateAccess=true))
	ACharacter* CharacterRef;

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

};
