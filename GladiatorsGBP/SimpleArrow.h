// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleArrow.generated.h"

UCLASS()
class GLADIATORSGBP_API ASimpleArrow : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASimpleArrow();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
	void setTarget(FVector target);

	void setType(int type);

	UFUNCTION()
		UStaticMeshComponent* getMesh();
	UFUNCTION()
		void OnHit(AActor * SelfActor, class AActor * OtherActor, FVector NormalImpulse, const FHitResult &Hit);
private:
	UPROPERTY()
		UStaticMeshComponent* mesh;
	UPROPERTY()
	FVector target; /**Objetivo al que va la flecha*/
	UPROPERTY()
	float tX;/**Coordenada X del objetivo*/
	UPROPERTY()
	float tY;/**Coordenada Y del objetivo*/
	UPROPERTY()
	float tZ;/**Coordenada Z del objetivo*/
	UPROPERTY()
	bool targetAq; /**Positivo si choca*/
	UPROPERTY()
	FVector currentPos; /**Posicion de la flecha*/
	UPROPERTY()
	float speed; /**Velocidad de la flecha*/
	int type; /**Tipo de flecha. 0 normal, 1 fuego, 2 explosiva*/

};