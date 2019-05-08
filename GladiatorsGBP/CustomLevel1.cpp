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

	airCam = GetWorld()->SpawnActor<AMyCameraActor>(FVector(-160,710,3780),FRotator(0,0,0),SpawnInfo);
	airCam->GetCameraComponent()->SetRelativeRotation(FRotator(-90,-90.f,-90));
	

	//tablero->addTower(0, 0, 0);
	glad1 = tablero->addGladiador(0, 1);
	glad2 = tablero->addGladiador(0,0);
	
	airCam->setCam();
	//tablero->mover(0,0,9,9);

	//FViewTargetTransitionParams Params;
	//Cast<APlayerController>(glad1->GetController())->SetViewTarget(glad1, Params);

	//glad1->getCamera()->SetActive(true);
	//glad1->setResistencia(1);
	//tablero->mover(1, 1, 0, 1);
	//tablero->teleportActor(1, 1, 9, 9);
	// Nota, los movimientos se sobreescriben, solucion:
	// Crear una cola de movimientos, utilizar GetMoveStatus()


	
	//tablero->getMatriz().getElemento(1)->getData().getElemento(1)->getData()->moveTo(prueba2);
	//tablero->mover(1, 1, 1, 5);
	//tablero->mover(1, 5, 7, 4);
	//tablero->mover(7, 4, 9, 9);
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
	if (!glad1 && !glad2) {
		UGameplayStatics::OpenLevel(GetWorld(), "ThirdPersonExampleMap");  // Reinicia nivel
	}
}