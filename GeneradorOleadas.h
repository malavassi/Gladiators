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

//Clase encargada de generar las oleadas ->dos poblaciones de Gladiadores)

class GeneradorOleadas {

private:
    int contadorGladiador; //id UNICO para cada Gladiador

    int iQemocionalRandom; //para asignar un valor random de iQemocional del 1 al 5
    int condicionFisicaRandom; //para asignar un valor random de condicion fisica
    int fuerzaTSuperiorRandom; //same
    int fuerzaTInferiorRandom; //... same

    int limiteGladiadorPorOleada; //limite de cuantos gladiadores por poblacion (entiendase poblacion == oleada... its not the same but, luego se cambia)

    int contadorGeneracion; //contador para identificar cual generacion se va creando

    PoolGladiadores *poolGladiadores; //pool en el que va a generar las oleadas
    //luego deberia tener como atributo a la clase encargada de aplicar el fitness

public:
    GeneradorOleadas(); //constructor
    void generarOleadaInicial(); //Genera la primer Oleada (sin fitness)

    //getters y setters
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
