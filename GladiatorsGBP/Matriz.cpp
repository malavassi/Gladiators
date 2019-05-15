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
			AGladiator* gladiador = inicial->getGladiator();
			ASimpleTower* tower = inicial->getSimpleTower();
			if (gladiador) {
				inicial->moveTo(final);  // Mueve graficamente
				if (inicial->getGladSec()) {  // Despues de haber movido graficamente, si hay un secundario lo pone de primario
					inicial->setActor(inicial->getGladSec());
					inicial->setGladSec(nullptr);
				}
				inicial->clear(false);
				final->setActor(gladiador);
			}
			else if (tower) {
				teleportActor(ii,ij,fi,fj);
			}
		
	}
}

void AMatriz::init() {
	LinkedList<int> movActuales = movimientosPendientes.getElemento(0)->getData();
	movimientosPendientes.pop_front();

	for (int i = 0; i < movActuales.getSize();i++) {
		int movimiento = movActuales.getElemento(i)->getData();
		int xi = (int)(movimiento / 1000);
		int yi = (int)(movimiento / 100) - xi * 10;
		int xf = (int)((int)(movimiento % 100) - (movimiento % 10) / 10);
		int yf = (int)(movimiento % 10);
		if (i == 0) {  // Primer elemento es primer gladiador
			casillaDestino = (getCasilla(xf,yf));
		}
		mover(xi, yi, xf, yf);
	}

}

AGladiator* AMatriz::addGladiador(int i, int j)
{
	return getMatriz().getElemento(i)->getData().getElemento(j)->getData()->spawnGladiator();
}

LinkedList<LinkedList<ACasilla1*>> AMatriz::getMatriz() {
	return matriz;
}

ACasilla1 * AMatriz::getCasilla(int i, int j)
{
	return getMatriz().getElemento(i)->getData().getElemento(j)->getData();
}

void AMatriz::addTower(int torr, int i, int j) {
		ASimpleTower* torre = getMatriz().getElemento(i)->getData().getElemento(j)->getData()->spawnTower();
		torre->setType(torr);
		ACasilla1* actual = getCasilla(i, j);
		LinkedList<FVector> triggerBoxes = torre->getTriggerBoxes();
		int size = triggerBoxes.getSize();
		for (int c = 0; c < size;c++) {
			int rx = triggerBoxes.getElemento(c)->getData().X; 
			int ry = triggerBoxes.getElemento(c)->getData().Y;
			int ax = i+rx;
			int ay = j+ry;
			if (ax>=0 && ay>=0 && ax<10 && ay<10) {
				ACasilla1* trigger = getCasilla(ax, ay);
				trigger->setTriggerTower(torre);
				actual->addDependency(trigger);
			}
		}
	
}

void AMatriz::addMovimientosS(LinkedList<int> movs) {
	movimientosPendientes.push_back(movs); 
}

void AMatriz::teleportActor(int ii, int ij, int fi, int fj) {
	ACasilla1* inicial = getCasilla(ii, ij);
	ACasilla1* final = getCasilla(fi, fj);
	if (inicial && final) {
		if (final->getGladiator() == nullptr) {
			AGladiator* gladiador = inicial->getGladiator();
			ASimpleTower* tower;
			if (inicial->getOldTower()) {  // Si hay un conflicto de torres muevo la vieja
				tower = inicial->getOldTower();
			}else {
				tower = inicial->getSimpleTower();
			}
			
			if (gladiador) {
				gladiador->SetActorLocation(FVector(final->getX(), final->getY(), 130.0f));
				final->setActor(gladiador);
				inicial->clear(false);
			}
			else if (tower) {

				final->setActor(tower);
				tower->SetActorLocation(FVector(final->getX(), final->getY(), 130.0f));
				if (inicial->getOldTower()) {
					inicial->setOldTower(nullptr);
				}
				else {
					inicial->clear(true);
				}
				ACasilla1* actual = getCasilla(fi, fj);
				LinkedList<FVector> triggerBoxes = tower->getTriggerBoxes();
				int size = triggerBoxes.getSize();
				for (int c = 0; c < size; c++) {  // Muevo las triggerboxes
					int rx = triggerBoxes.getElemento(c)->getData().X;
					int ry = triggerBoxes.getElemento(c)->getData().Y;
					int ax = fi + rx;
					int ay = fj + ry;
					if (ax >= 0 && ay >= 0 && ax < 10 && ay < 10) {
						ACasilla1* trigger = getCasilla(ax, ay);
						trigger->setTriggerTower(tower);
						actual->addDependency(trigger);
					}
				}
			}
		}
	}
}
