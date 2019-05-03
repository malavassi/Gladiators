#include "Matriz.h"



AMatriz::AMatriz()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMatriz::setUp() {
	int initY = -1300;
	int change = 400;
	int initX = -2000;
	for (int i = 0; i < 10; i++) {
		LinkedList<ACasilla1*> columna = LinkedList<ACasilla1*>();
		for (int j = 0; j < 10; j++) {

			int x = initX + i * change;
			int y = initY + j * change;
			FVector Location(x, y, 190.0f);
			FRotator Rotation(0.f, 0.f, 0.f);
			FActorSpawnParameters SpawnInfo;
			ACasilla1* casilla = GetWorld()->SpawnActor<ACasilla1>(Location, Rotation, SpawnInfo);
			casilla->setTodo(i, j, x, y);
			columna.push_back(casilla);
		}
		matriz.push_back(columna);
	}
}


AMatriz::~AMatriz()
{
}

void AMatriz::mover(int ii, int ij, int fi, int fj)
{
	ACasilla1* inicial = getCasilla(ii, ij);
	ACasilla1* final = getCasilla(fi, fj);
	if (inicial && final) {
		if (final->getGladiator() == nullptr && final->getSimpleTower() == nullptr) {
			AGladiator* gladiador = inicial->getGladiator();
			ASimpleTower* tower = inicial->getSimpleTower();
			if (gladiador) {
				inicial->moveTo(final);
				inicial->clear();
				final->setActor(gladiador);
			}
			else if (tower) {
				inicial->moveTo(final);
				inicial->clear();
				final->setActor(tower);
			}
		}
	}
}

LinkedList<LinkedList<ACasilla1*>> AMatriz::getMatriz() {
	return matriz;
}

ACasilla1 * AMatriz::getCasilla(int i, int j)
{
	return getMatriz().getElemento(i)->getData().getElemento(j)->getData();
}
