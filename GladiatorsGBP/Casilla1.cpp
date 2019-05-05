// Fill out your copyright notice in the Description page of Project Settings.


#include "Casilla1.h"
#include "DrawDebugHelpers.h"

// Ayuda al debugger
#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))


ACasilla1::ACasilla1()
{
	gladiator = nullptr;
	tower = nullptr;
	triggerTower = nullptr;
	casillasDependientes = LinkedList<ACasilla1*>();
	OnActorBeginOverlap.AddDynamic(this, &ACasilla1::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ACasilla1::OnOverlapEnd);
	

}

void ACasilla1::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	// check if Actors do not equal nullptr and that 
	if (OtherActor && (OtherActor != this) && triggerTower !=nullptr) {
		// print to screen using above defined method when actor enters trigger box
		print("Overlap Begin");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
		triggerTower->Fire(OtherActor);
	}
}

void ACasilla1::OnOverlapEnd(AActor * OverlappedActor, AActor * OtherActor)
{
	// check if Actors do not equal nullptr and that 
	if (OtherActor && (OtherActor != this) && triggerTower!=nullptr) {
		// print to screen using above defined method when actor enters trigger box
		print("Overlap Begin");
		printFString("Overlapped Actor = %s", *OverlappedActor->GetName());
	}
}

ACasilla1::ACasilla1(int i, int j)
{
	gladiator = nullptr;
	tower = nullptr;
	triggerTower = nullptr;
	casillasDependientes = LinkedList<ACasilla1*>();
	OnActorBeginOverlap.AddDynamic(this, &ACasilla1::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ACasilla1::OnOverlapEnd);
	
}

ACasilla1::ACasilla1(int i, int j, int x, int y) {
	gladiator = nullptr;
	tower = nullptr;
	this->i = i;
	this->j = j;
	this->x = x;
	this->y = y;
	casillasDependientes = LinkedList<ACasilla1*>();
	OnActorBeginOverlap.AddDynamic(this, &ACasilla1::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ACasilla1::OnOverlapEnd);
	
}

ACasilla1::~ACasilla1()
{
}

void ACasilla1::setActor(AGladiator* gladiador) {
	this->gladiator = gladiador;
	this->tower = nullptr;
	if (gladiador) {
		controller = Cast<AGladiatorAIController>(gladiator->GetController());
	}
}

void ACasilla1::setActor(ASimpleTower* torre) {
	this->gladiator = nullptr;
	this->tower = torre;
	controller = nullptr;
}



void ACasilla1::clear() {
	this->gladiator = nullptr;
	this->tower = nullptr;
	this->controller = nullptr;
	this->triggerTower = nullptr;
	if (casillasDependientes.getSize()>0) {
		int size = casillasDependientes.getSize();
		for (int c = 0; c < size;c++) {
			casillasDependientes.getElemento(c)->getData()->clear();
		}
	}
	this->casillasDependientes.clearList();
}

ASimpleTower* ACasilla1::spawnTower() {
	FVector Location(x,y,190.f);
	FRotator Rotation(0.f, 0.f, 0.f);
	FActorSpawnParameters SpawnInfo;
	ASimpleTower* torre = GetWorld()->SpawnActor<ASimpleTower>(Location, Rotation, SpawnInfo);
	this->gladiator = nullptr;
	controller = nullptr;
	this->tower = torre;
	return torre;
}

AGladiator* ACasilla1::spawnGladiator() {
	FVector Location(x, y, 190.f);
	FRotator Rotation(0.f, 0.f, 0.f);
	FActorSpawnParameters SpawnInfo;
	AGladiator* gladiador = GetWorld()->SpawnActor<AGladiator>(Location, Rotation, SpawnInfo);
	this->gladiator = gladiador;
	this -> tower = nullptr;
	if (gladiador) {
		controller = Cast<AGladiatorAIController>(gladiator->GetController());
	}
	return gladiador;
}

void ACasilla1::setTodo(int ii, int jj, int xx, int yy) {
	this->i = ii;
	this->j = jj;
	this->x = xx;
	this->y = yy;
}

AGladiator* ACasilla1::getGladiator() {
	return gladiator;
}

ASimpleTower* ACasilla1::getSimpleTower() {
	return tower;
}

void ACasilla1::addDependency(ACasilla1 * casilla)
{
	casillasDependientes.push_back(casilla);
}

void ACasilla1::setTriggerTower(ASimpleTower * tower)
{
	this->triggerTower = tower;
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
}


void ACasilla1::moveTo(ACasilla1* casilla) {
	if (gladiator != nullptr) {
		//AAIController *controller = gladiator->GetController<AAIController>();
		if (controller) {
			if (controller->GetMoveStatus() == EPathFollowingStatus::Moving) {
				controller->enqueue(FVector(casilla->getX(), casilla->getY(), 230));
			}
			else {
				controller->MoveToLocation(FVector(casilla->getX(), casilla->getY(), 230));
			}
		}
		//AddMovementInput(GetActorForwardVector(), 20000);
	}
}

int ACasilla1::getX() {
	return x;
}

int ACasilla1::getY() {
	return y;
}

