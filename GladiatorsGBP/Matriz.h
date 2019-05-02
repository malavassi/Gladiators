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
	LinkedList<LinkedList<ACasilla1*>> getMatriz();
private:
	LinkedList<LinkedList<ACasilla1*>> matriz;
};

