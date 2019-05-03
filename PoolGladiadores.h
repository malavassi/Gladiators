//
// Created by fabian152195 on 29/04/19.
//

#ifndef GLADIATORS_POOLGLADIADORES_H
#define GLADIATORS_POOLGLADIADORES_H


#include "LinkedList.h"
#include "Gladiator.h"
#include <iostream>

using namespace std;

class PoolGladiadores {

private:
    int identificadorOleada;
    LinkedList<LinkedList<Gladiator>> *poolGladiadores;

public:
    PoolGladiadores();
    PoolGladiadores(LinkedList<LinkedList<Gladiator>> *poolGladiadores);
    void recorrerPool();

    int getIdentificadorOleada() const;

    void setIdentificadorOleada(int identificadorOleada);

    LinkedList<LinkedList<Gladiator>> *getPoolGladiadores() const;

    void setPoolGladiadores(LinkedList<LinkedList<Gladiator>> *poolGladiadores);
};


#endif //GLADIATORS_POOLGLADIADORES_H
