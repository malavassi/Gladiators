// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Gladiator.generated.h"

UCLASS()
class GLADIATORSGBP_API AGladiator : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGladiator();
	void setChars(int res, int iq, int cF, int TS, int TI, int edad, int prob, int genEsperadas);
	bool getReady();
	void setCamara(); /** Pone la camara en el objetivo actual*/

	UCameraComponent* getCamera() { return FollowCamera;}

private:
	//UStaticMeshComponent* mesh;
	int resistencia;
	int inteligenciaEmocional;
	int condicionFisica;
	int fuerzaTroncoSup;
	int fuerzaTroncoInf;
	int edad;
	int prob;
	int genEsperadas;
	bool ready;
	USpringArmComponent* CameraBoom; /**Resorte para la camara*/
	UCameraComponent* FollowCamera;  /**Camara*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void setResistencia(int cantidad);
	void bajarResistencia(int cantidad);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnHit(AActor * SelfActor, class AActor * OtherActor, FVector NormalImpulse, const FHitResult &Hit);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
