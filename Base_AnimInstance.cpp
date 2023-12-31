// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_AnimInstance.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

void UBase_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (CharacterRef)
	{
		Speed = CharacterRef->GetVelocity().Size();
	}
	else
	{
		CharacterRef = Cast<ACharacter>(GetOwningActor());
	}
}
