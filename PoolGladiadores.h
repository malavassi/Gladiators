//
// Created by fabian152195 on 29/04/19.
//

#ifndef GLADIATORS_POOLGLADIADORES_H
#define GLADIATORS_POOLGLADIADORES_H


#include "LinkedList.h"
#include "Gladiator.h"
#include "Generacion.h"
#include <iostream>

using namespace std;

//Esta es la clase que almacena TODOS los gladiadores
//por generacion y cada generacion a su vez esta dividida
//en dos poblaciones (que llamo PoblacionA o PoblacionB)
class PoolGladiadores {

private:
    int identificadorOleada; //useless, no lo he eliminado
    LinkedList<Generacion> *poolGladiadores; //puntero principal del pool

public:
    PoolGladiadores(); //constructor por defecto
    PoolGladiadores(LinkedList<Generacion> *poolGladiadores);
    void recorrerPool();  //recorre todo el pool, ver prueba. Tested

    int getIdentificadorOleada() const; //nevermind

    void setIdentificadorOleada(int identificadorOleada); //nevermind

    LinkedList<Generacion> *getPoolGladiadores() const; //pues getters y setters

    void setPoolGladiadores(LinkedList<Generacion> *poolGladiadores);
};


#endif //GLADIATORS_POOLGLADIADORES_H
