// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleTower.h"
#include "Gladiator.h"
#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Gladiator.h"
#include "Engine/World.h"
#include "GladiatorsGBPCharacter.h"
#include "GladiatorAIController.h"
#include "LinkedList.h"
#include "MyTriggerBox.h"
#include "Engine/TriggerBox.h"

#include "Casilla1.generated.h"

/**
 Clase encargada de adminitrar las casillas y los contenidos de esta
 @author Elorim
 */
UCLASS()
class GLADIATORSGBP_API ACasilla1 : public ATriggerBox
{
	GENERATED_BODY()
public:
	ACasilla1();

	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	/**
	Constructor, dada la posicion en la 
	*/
	//ACasilla1();
	ACasilla1(int i, int j);
	ACasilla1(int ii, int jj, int xx, int yy);
	~ACasilla1();
	/**
	Esta funcion y su sobrecarga se encarga de poner un gladiador, una torre o un triggerbox en esta casilla. Al poner uno o otro, vuelve el otro un nullptr.
	@param gladiator Puntero al gladiador a poner en la casilla
	*/
	void setActor(AGladiator* gladiator);
	/**
	Esta funcion y su sobrecarga se encarga de poner un gladiador, una torre o un triggerbox en esta casilla. Al poner uno o otro, vuelve el otro un nullptr.
	@param tower Puntero a la torre a poner en la casilla
	*/
	void setActor(ASimpleTower* tower);
	/**
	Desocupa a la casilla de una torre o un gladiador.
	*/
	void clear(bool all);
	/** Genera una torre en esta casilla*/
	ASimpleTower* spawnTower(int type);
	/** Genera un gladiador en esta casilla*/
	AGladiator* spawnGladiator();
	/**
	Mueve a lo que tenga la casilla a otra casilla. En caso de ser un gladiador lo hace caminar, si es una torre se teleporta
	@param casilla Puntero a la casilla donde se quiere mover 
	*/
	void moveTo(ACasilla1* casilla);

	// Getters & setters comunes
	void setTodo(int i, int j, int x, int y);
	AGladiator* getGladiator();
	ASimpleTower* getSimpleTower();
	void addDependency(ACasilla1* casilla);
	void setTriggerTower(ASimpleTower* tower);
	int getX();
	int getY();
private:
	int x; /** Posicion real en x en la interfaz */
	int y; /** Posicion real en y en la interfaz*/
	int i; /** Posicion en la matriz en x, empieza en 0*/
	int j; /** Posicion en la matriz en y, empieza en 0 */
	ASimpleTower* tower; /**Torre en esta casilla, si hay una*/
	AGladiator* gladiator; /** Gladiador en esta casilla, si hay uno*/
	ASimpleTower* triggerTower; /** Puntero a la torre que va a disparar*/
	LinkedList<ACasilla1*> casillasDependientes; /**Lista de punteros a casillas que debo limpiar si limpio la actual*/
	AGladiatorAIController* controller; /** Controlador del gladiador, si lo hay*/
	LinkedList<AGladiator*> shooted;
	bool isShooted(AGladiator* check);
};
