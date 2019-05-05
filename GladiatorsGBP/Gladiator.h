// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Gladiator.generated.h"

UCLASS()
class GLADIATORSGBP_API AGladiator : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGladiator();
	void setChars(int res, int iq, int cF, int TS, int TI, int edad, int prob, int genEsperadas);

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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OnHit(AActor * SelfActor, class AActor * OtherActor, FVector NormalImpulse, const FHitResult &Hit);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};