// Fill out your copyright notice in the Description page of Project Settings.


#include "GladiatorAIController.h"

void AGladiatorAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result) {
	if (cola_movimientos.getSize()>0) {
		FVector newMovement = this->cola_movimientos.getHead()->getData();
		cola_movimientos.pop_front();
		MoveToLocation(newMovement);
	}
}

void AGladiatorAIController::enqueue(FVector enqueue) {
	cola_movimientos.push_back(enqueue);
}

