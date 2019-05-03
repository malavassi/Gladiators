// Fill out your copyright notice in the Description page of Project Settings.


#include "Gladiator.h"
#include "ConstructorHelpers.h"
#include "GladiatorAIController.h"

// Sets default values
AGladiator::AGladiator()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGladiator::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGladiator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGladiator::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	

}

void AGladiator::moveTo(auto* casilla) {
	// AddMovement?
	AGladiatorAIController* controller = Cast<AGladiatorAIController>(GetController());
	if (controller) {
		controller->MoveToActor(casilla, 5.f, false);
	}
	//AddMovementInput(GetActorForwardVector(), 20000);
}

