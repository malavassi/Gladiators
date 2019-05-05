//
// Created by fabian152195 on 29/04/19.
//

#include "PoolGladiadores.h"

PoolGladiadores::PoolGladiadores() {
    this->poolGladiadores = new LinkedList<Generacion>();
    identificadorOleada = 0;
}

PoolGladiadores::PoolGladiadores(LinkedList<Generacion> *poolGladiadores)
        : poolGladiadores(poolGladiadores) {
    this->poolGladiadores = poolGladiadores;
    identificadorOleada = 0;
}

void PoolGladiadores::recorrerPool() {

    int cantidadGeneraciones= poolGladiadores->getSize();
    int cantidadGladiadorPorGeneracion;
    Node<Generacion> *generacion;
    LinkedList<Gladiator> *poblacionA;
    LinkedList<Gladiator> *poblacionB;

    int idGladiador;

    for(int i = 0; i<cantidadGeneraciones; i++){ //ITERACION POR OLEADA

        generacion = poolGladiadores->getElemento(i); //obtiene el nodo de una generacion

        poblacionA = generacion->getData()->getPoblacionA(); //obtiene las poblaciones de esa generacion
        poblacionB = generacion->getData()->getPoblacionB();

        cout<<"GENERACION " << generacion->getId() << endl;

        cantidadGladiadorPorGeneracion = generacion->getData()->getPoblacionA()->getSize(); //ITERACION POR GLADIADORES DE POBLACION

        cout<<"POBLACION A: "<<endl;

        for (int j = 0; j<cantidadGladiadorPorGeneracion ; j++){

            idGladiador = generacion->getData()->getPoblacionA()->getElemento(j)->getData()->getIdUnico();
            cout << "   GladidorID: " << idGladiador << endl;

        }

        cout << "---------------------------- "<< endl;

        cantidadGladiadorPorGeneracion = generacion->getData()->getPoblacionB()->getSize(); //ITERACION POR GLADIADORES DE POBLACION

        cout<<"POBLACION B: "<<endl;

        for (int j = 0; j<cantidadGladiadorPorGeneracion ; j++){

            idGladiador = generacion->getData()->getPoblacionB()->getElemento(j)->getData()->getIdUnico();
            cout << "   GladidorID: " << idGladiador << endl;

        }

        cout << "---------------------------- "<< endl;
        cout << "---------------------------- \n"<< endl;

    }

}

int PoolGladiadores::getIdentificadorOleada() const {
    return identificadorOleada;
}

void PoolGladiadores::setIdentificadorOleada(int identificadorOleada) {
    PoolGladiadores::identificadorOleada = identificadorOleada;
}

LinkedList<Generacion> *PoolGladiadores::getPoolGladiadores() const {
    return poolGladiadores;
}

void PoolGladiadores::setPoolGladiadores(LinkedList<Generacion> *poolGladiadores) {
    PoolGladiadores::poolGladiadores = poolGladiadores;
}
