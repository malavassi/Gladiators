//
// Created by fabian152195 on 29/04/19.
//

#include "PoolGladiadores.h"

PoolGladiadores::PoolGladiadores() {
    this->poolGladiadores = new LinkedList<LinkedList<Gladiator>>();
    identificadorOleada = 0;
}

PoolGladiadores::PoolGladiadores(LinkedList<LinkedList<Gladiator>> *poolGladiadores)
        : poolGladiadores(poolGladiadores) {
    this->poolGladiadores = poolGladiadores;
    identificadorOleada = 0;
}

void PoolGladiadores::recorrerPool() {

    int cantidadGeneraciones= poolGladiadores->getSize();
    int cantidadGladiadorPorGeneracion;
    Node<LinkedList<Gladiator>> *generacion;
    int idGladiador;

    for(int i = 0; i<cantidadGeneraciones; i++){ //ITERACION POR OLEADA

        generacion = poolGladiadores->getElemento(i);

        cout<<"GENERACION " << generacion->getId() << endl;

        cantidadGladiadorPorGeneracion = generacion->getData()->getSize(); //ITERACION POR GLADIADORES DE OLEADA


        for (int j = 0; j<cantidadGladiadorPorGeneracion ; j++){

            idGladiador = generacion->getData()->getElemento(j)->getData()->getIdUnico();
            cout << "   GladidorID: " << idGladiador << endl;

        }

        cout << "---------------------------- "<< endl;

    }

}

int PoolGladiadores::getIdentificadorOleada() const {
    return identificadorOleada;
}

void PoolGladiadores::setIdentificadorOleada(int identificadorOleada) {
    PoolGladiadores::identificadorOleada = identificadorOleada;
}

LinkedList<LinkedList<Gladiator>> *PoolGladiadores::getPoolGladiadores() const {
    return poolGladiadores;
}

void PoolGladiadores::setPoolGladiadores(LinkedList<LinkedList<Gladiator>> *poolGladiadores) {
    PoolGladiadores::poolGladiadores = poolGladiadores;
}
