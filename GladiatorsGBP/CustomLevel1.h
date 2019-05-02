// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Gladiator.h"
#include "Engine/World.h"
#include "GladiatorsGBPCharacter.h"
#include "Matriz.h"

#include "CustomLevel1.generated.h"


/**
 * 
 */
UCLASS()
class GLADIATORSGBP_API ACustomLevel1 : public ALevelScriptActor
{
	GENERATED_BODY()
public:
	ACustomLevel1(const FObjectInitializer & ObjectInitializer);

protected:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	virtual void Tick(float DeltaSeconds) override;
private:
	int cont;
	AMatriz* tablero;

};
