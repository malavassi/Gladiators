// Fill out your copyright notice in the Description page of Project Settings.


#include "Casilla1.h"

Casilla1::Casilla1()
{
}

Casilla1::Casilla1(int i, int j) 
{
	gladiator = nullptr;
	tower = nullptr;
	int initY = -1300;
	int change = 400;
	int initX = -2000;
	this->x = initX + i * change;
	this->y = initY + j * change;
}

Casilla1::~Casilla1()
{
	delete gladiator;
	delete tower;
}

void Casilla1::setActor(AGladiator* gladiador) {
	this->gladiator = gladiador;
	this->tower = nullptr;
}

void Casilla1::setActor(ASimpleTower* torre) {
	this->gladiator = nullptr;
	this->tower = torre;
}

void Casilla1::clear() {
	this->gladiator = nullptr;
	this->tower = nullptr;
}
