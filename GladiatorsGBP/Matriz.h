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

	LinkedList<LinkedList<ACasilla1*>> getMatriz();
	ACasilla1* getCasilla(int i, int j);
private:
	LinkedList<LinkedList<ACasilla1*>> matriz;
};

