// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Gladiator.h"
#include "Camera/CameraActor.h"
#include "MyCameraActor.h"
#include "CameraManager.generated.h"

UCLASS()
class GLADIATORSGBP_API ACameraManager : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void init(AGladiator* glad1, AGladiator* glad2, AMyCameraActor* airCam);

private:
	void cam1();
	void cam2();
	void cam3();
	AGladiator* glad1;
	AGladiator* glad2;
	AMyCameraActor* airCam;

};
