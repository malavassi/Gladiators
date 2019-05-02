// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleTower.h"
#include "Gladiator.h"

/**
 Clase encargada de adminitrar las casillas y los contenidos de esta
 @author Elorim
 */
class GLADIATORSGBP_API Casilla1
{
public:
	Casilla1();
	Casilla1(int x, int y);
	~Casilla1();
	/**
	Esta funcion y su sobrecarga se encarga de poner un gladiador o una torre en esta casilla. Al poner uno o otro, vuelve el otro un nullptr.
	@param gladiator Puntero al gladiador a poner en la casilla
	*/
	void setActor(AGladiator* gladiator);
	/**
	Esta funcion y su sobrecarga se encarga de poner un gladiador o una torre en esta casilla. Al poner uno o otro, vuelve el otro un nullptr.
	@param tower Puntero a la torre a poner en la casilla
	*/
	void setActor(ASimpleTower* tower);
	/**
	Desocupa a la casilla de una torre o un gladiador.
	*/
	void clear();
private:
	int x; /** Posicion real en x en la interfaz */
	int y; /** Posicion real en y en la interfaz*/
	int i; /** Posicion en la matriz en x, empieza en 0*/
	int j; /** Posicion en la matriz en y, empieza en 0 */
	ASimpleTower* tower; /**Torre en esta casilla, si hay una*/
	AGladiator* gladiator; /** Gladiador en esta casilla, si hay uno*/
};
