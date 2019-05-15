#pragma once
#include "LinkedList.h"
#include "Casilla1.h"

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "Gladiator.h"
#include "Engine/World.h"
#include "GladiatorsGBPCharacter.h"


#include "Matriz.generated.h"

UCLASS()
class AMatriz: public AActor {
	GENERATED_BODY()
public:
	void setUp();
	AMatriz();
	~AMatriz();

	/**
	Mueve el objeto de la casilla inicial a la casilla final
	@param ii i inicial
	@param ij j inicial
	@param fi i final
	@param fj j final
	*/
	void mover(int ii, int ij, int fi, int fj);


	/**
	Agrega una torre del tipo especificado en la casilla especificada
	@param torre Integer con el tipo de torre a agregar. 0 - 2
	@param i i de la casilla donde se va a agregar
	@param j j de la casilla donde se va a agregar
	*/
	void addTower(int torre, int i, int j);

	/**
	Agrega un gladiador en la casilla especificada
	@param i i de la casilla a agregar el gladiador
	@param j j de la casilla a agregar el gladiador
	@returns Puntero al nuevo gladiador
	*/
	AGladiator* addGladiador(int i, int j);

	/**
	Teleporta el actor que haya en la casilla ii, ij a la casilla fi,fj
	@param ii i inicial
	@param ij j inicial
	@param fi i final
	@param fj j final
	*/
	void teleportActor(int ii, int ij, int fi, int fj);
	
	/**
	Inicia el record de los movimientos en la matriz
	@autor elorim
	*/
	void init();
	/*Getters & setters*/
	void addMovimientosS(LinkedList<int> movs);  /**Agrega movimientos sincronos*/
	LinkedList<LinkedList<ACasilla1*>> getMatriz();
	ACasilla1* getCasilla(int i, int j);
	ACasilla1* getDestino() { return casillaDestino; };
private:
	ACasilla1* casillaDestino; /**Casilla destino de un gladiador, cuando se alcance esta casilla hay que ejecutar el siguiente nodo de animaciones.*/
	LinkedList<LinkedList<ACasilla1*>> matriz;  /** Matriz donde se va a llevar a cabo del juego*/
	LinkedList<LinkedList<int>> movimientosPendientes;  /**Lista doblemente enlazada encargada de controlar todos los movimientos en la matriz*/

};

