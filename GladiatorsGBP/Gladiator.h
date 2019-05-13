// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyAnimInstance.h"
#include "Particles/ParticleSystem.h"
//For the UGameplayStatics::SpawnEmitterAttached
#include "Kismet/GameplayStatics.h"
 
 //All particle definitions for using functions of UParticleSystemComponent
 #include "ParticleDefinitions.h"

#include "Gladiator.generated.h"

UCLASS()
class GLADIATORSGBP_API AGladiator : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGladiator();
	~AGladiator() {AGladiator::cont--;}
	void setChars(int res, int iq, int cF, int TS, int TI, int edad, int prob, int genEsperadas);
	bool getReady();
	void setCamara(); /** Pone la camara en el objetivo actual*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)  // BlueprintReadONly solo es usable en publicas
		int resistencia;

	UCameraComponent* getCamera() { return FollowCamera;}
	USkeletalMeshComponent* getMesh() { return mesh; }

private:
	USkeletalMeshComponent* mesh;
	//UStaticMeshComponent* mesh;
	static int cont;
	
	int inteligenciaEmocional;
	int condicionFisica;
	int fuerzaTroncoSup;
	int fuerzaTroncoInf;
	int edad;
	int prob;
	int genEsperadas;
	int id;
	bool ready;
	bool ded;  /**Booleano del gladiador muerto*/
	USpringArmComponent* CameraBoom; /**Resorte para la camara*/
	UCameraComponent* FollowCamera;  /**Camara*/
	UMyAnimInstance* animations; /**Link a las animaciones*/

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
