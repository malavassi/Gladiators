// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraManager.h"

// Sets default values
ACameraManager::ACameraManager()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void ACameraManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACameraManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//print("1");
	InputComponent->BindAction("Cam1", IE_Pressed, this, &ACameraManager::cam1);
	InputComponent->BindAction("Cam2", IE_Pressed, this, &ACameraManager::cam2);
	InputComponent->BindAction("Cam3", IE_Pressed, this, &ACameraManager::cam3);
}

void ACameraManager::cam1() {
	if (glad1) {
		glad1->setCamara();
	}
}

void ACameraManager::cam2() {
	if (glad2) {
		glad2->setCamara();
	}
}

void ACameraManager::cam3() {
	if (airCam) {
		airCam->setCam();
	}
}

void ACameraManager::init(AGladiator* glad1, AGladiator* glad2, AMyCameraActor* airCam) 
{
	this->glad1 = glad1;
	this->glad2 = glad2;
	this->airCam = airCam;
}