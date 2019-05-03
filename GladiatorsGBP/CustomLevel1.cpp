// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomLevel1.h"
#include "SimpleTower.h"
#include "Kismet/GameplayStatics.h"
#include <string>
#include "Matriz.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)

ACustomLevel1::ACustomLevel1(const FObjectInitializer & ObjectInitializer) : ALevelScriptActor(ObjectInitializer){
	  
}

void ACustomLevel1::BeginPlay() {
	Super::ReceiveBeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Hello World!"));

	//Spawn the shiet
	FVector Location(-150.5f, 50.0f, 190.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	UE_LOG(LogTemp, Warning, TEXT("Trying to spawn"));
	//GetWorld()->SpawnActor<AGladiator>(Location, Rotation, SpawnInfo);
	//GetWorld()->SpawnActor<ASimpleTower>(Location, Rotation, SpawnInfo);
	tablero = GetWorld()->SpawnActor<AMatriz>(Location,Rotation, SpawnInfo);
	tablero->setUp();
	tablero->getMatriz().getElemento(1)->getData().getElemento(1)->getData()->spawnGladiator();
	ACasilla1* prueba1 = tablero->getMatriz().getElemento(9)->getData().getElemento(9)->getData();
	ACasilla1* prueba2 = tablero->getMatriz().getElemento(5)->getData().getElemento(5)->getData();
	ACasilla1* prueba3 = tablero->getMatriz().getElemento(1)->getData().getElemento(8)->getData();
	
	// Nota, los movimientos se sobreescriben, solucion:
	// Crear una cola de movimientos, utilizar GetMoveStatus()
	
	//tablero->getMatriz().getElemento(1)->getData().getElemento(1)->getData()->moveTo(prueba2);
	tablero->mover(1, 1, 1, 5);
	tablero->mover(1, 5, 7, 4);
	tablero->mover(7, 4, 9, 9);
	//tablero->getMatriz().getElemento(1)->getData().getElemento(1)->getData()->moveTo(prueba3);
	//tablero->getMatriz().getElemento(1)->getData().getElemento(1)->getData()->moveTo(prueba1);

	cont = 1;

}

void ACustomLevel1::BeginDestroy() {
	Super::BeginDestroy();
	UE_LOG(LogTemp, Warning, TEXT("Bye!"));
}

void ACustomLevel1::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
}