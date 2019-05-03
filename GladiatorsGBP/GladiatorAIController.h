// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "LinkedList.h"
#include "GladiatorAIController.generated.h"

/**
 * Clase encargada del movimiento de los gladiadores
 @author Elorim
 @date 3/5/2019
 */
UCLASS()
class GLADIATORSGBP_API AGladiatorAIController : public AAIController
{
	GENERATED_BODY()
public:
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result);
	void enqueue(FVector movement);
private:
	LinkedList<FVector> cola_movimientos;  /** Encargada de llevar el registro de los movimientos solicitados*/
	
};
