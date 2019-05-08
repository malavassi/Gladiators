// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

/**
 * Clase para unir el blueprint de animaciones y el codigo de C++
 @author elorim
 */
UCLASS()
class GLADIATORSGBP_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool dying; /**Indica si el personaje esta muriendo*/
	
};
