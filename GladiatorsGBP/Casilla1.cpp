// Fill out your copyright notice in the Description page of Project Settings.


#include "Casilla1.h"

ACasilla1::ACasilla1()
{
}

ACasilla1::ACasilla1(int i, int j) 
{
	gladiator = nullptr;
	tower = nullptr;
	int initY = -1300;
	int change = 400;
	int initX = -2000;
	this->x = initX + i * change;
	this->y = initY + j * change;
}

ACasilla1::ACasilla1(int i, int j, int x, int y) {
	gladiator = nullptr;
	tower = nullptr;
	this->i = i;
	this->j = j;
	this->x = x;
	this->y = y;
}

ACasilla1::~ACasilla1()
{
}

void ACasilla1::setActor(AGladiator* gladiador) {
	this->gladiator = gladiador;
	this->tower = nullptr;
}

void ACasilla1::setActor(ASimpleTower* torre) {
	this->gladiator = nullptr;
	this->tower = torre;
}

void ACasilla1::clear() {
	this->gladiator = nullptr;
	this->tower = nullptr;
}

void ACasilla1::spawnTower() {
	FVector Location(x,y,190.f);
	FRotator Rotation(0.f, 0.f, 0.f);
	FActorSpawnParameters SpawnInfo;
	ASimpleTower* torre = GetWorld()->SpawnActor<ASimpleTower>(Location, Rotation, SpawnInfo);
	this->tower = torre;
}

void ACasilla1::spawnGladiator() {
	FVector Location(x, y, 190.f);
	FRotator Rotation(0.f, 0.f, 0.f);
	FActorSpawnParameters SpawnInfo;
	AGladiator* gladiador = GetWorld()->SpawnActor<AGladiator>(Location, Rotation, SpawnInfo);
	this->gladiator = gladiador;
}

void ACasilla1::setTodo(int ii, int jj, int xx, int yy) {
	this->i = ii;
	this->j = jj;
	this->x = xx;
	this->y = yy;
}