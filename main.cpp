#include <iostream>
#include "GeneradorOleadas.h"
#include "PoolGladiadores.h"


using namespace std;

int main() {
    cout << "TEST" << endl;

    GeneradorOleadas * generadorOleadas = new GeneradorOleadas;
    PoolGladiadores* poolGladiadores = new PoolGladiadores();

    generadorOleadas->setPoolGladiadores(poolGladiadores);

    generadorOleadas->generarOleadaInicial();

    return 0;



}