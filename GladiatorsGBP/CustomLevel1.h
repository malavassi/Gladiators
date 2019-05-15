// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Gladiator.h"
#include "Engine/World.h"
#include "GladiatorsGBPCharacter.h"
#include "Gladiator.h"
#include "Matriz.h"
#include "MyCameraActor.h"
#include "CameraManager.h"
#include "Animation/AnimSequence.h"
#include "ConstructorHelpers.h"
#include "CustomUserWidget.h"
#include "Client.h"
#include "Sendable.h"

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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCustomUserWidget* widgetGlad1;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UCustomUserWidget* widgetGlad2;

protected:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	virtual void Tick(float DeltaSeconds) override;
private:
	int cont;
	AMatriz* tablero;/** Tablero del juego*/
	AGladiator* glad1;
	AGladiator* glad2;
	AMyCameraActor* airCam;
	USpringArmComponent* CameraBoom; /**Resorte para la camara*/
	UInputComponent* inputs;
	ACameraManager* cameraManager;
	UAnimSequence* anims;

	Client client;
	
	UFUNCTION(BlueprintCallable)
	void cam1();
	UFUNCTION(BlueprintCallable)
	void cam2();
	UFUNCTION(BlueprintCallable)
		void cama3();
};
