// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Casilla.generated.h"

UCLASS()
class GLADIATORSGBP_API ACasilla : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACasilla();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int pX; /** Posicion real de la casilla en X */ 
	int pY; /** Posicion real de la casilla en Y */
	int i; /** Posicion en la matriz en X */
	int j; /** Posicion en la matriz en Y*/

};
