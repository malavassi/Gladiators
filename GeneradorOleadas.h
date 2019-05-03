//
// Created by fabian152195 on 29/04/19.
//

#ifndef GLADIATORS_GENERADOROLEADAS_H
#define GLADIATORS_GENERADOROLEADAS_H

#include "LinkedList.h"
#include "Node.h"
#include "Gladiator.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "PoolGladiadores.h"

using namespace std;

class GeneradorOleadas {

private:
    int contadorGladiador;

    int iQemocionalRandom;
    int condicionFisicaRandom;
    int fuerzaTSuperiorRandom;
    int fuerzaTInferiorRandom;

    int limiteGladiadorPorOleada;

    PoolGladiadores *poolGladiadores;

public:
    GeneradorOleadas();
    LinkedList<Gladiator> generarOleadaInicial();

    int getContadorGladiador() const;

    void setContadorGladiador(int contadorGladiador);

    int getIQemocionalRandom() const;

    void setIQemocionalRandom(int iQemocionalRandom);

    int getCondicionFisicaRandom() const;

    void setCondicionFisicaRandom(int condicionFisicaRandom);

    int getFuerzaTSuperiorRandom() const;

    void setFuerzaTSuperiorRandom(int fuerzaTSuperiorRandom);

    int getFuerzaTInferiorRandom() const;

    void setFuerzaTInferiorRandom(int fuerzaTInferiorRandom);

    PoolGladiadores *getPoolGladiadores() const;

    void setPoolGladiadores(PoolGladiadores *poolGladiadores);

    int getLimiteGladiadorPorOleada() const;

    void setLimiteGladiadorPorOleada(int limiteGladiadorPorOleada);

};


#endif //GLADIATORS_GENERADOROLEADAS_H
