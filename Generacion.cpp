//
// Created by fabian152195 on 04/05/19.
//

#include "Generacion.h"

Generacion::Generacion() {

    this->poblacionA = new LinkedList<Gladiator>();
    this->poblacionB = new LinkedList<Gladiator>();

}

LinkedList<Gladiator> *Generacion::getPoblacionA() const {
    return poblacionA;
}

void Generacion::setPoblacionA(LinkedList<Gladiator> *poblacionA) {
    Generacion::poblacionA = poblacionA;
}

LinkedList<Gladiator> *Generacion::getPoblacionB() const {
    return poblacionB;
}

void Generacion::setPoblacionB(LinkedList<Gladiator> *poblacionB) {
    Generacion::poblacionB = poblacionB;
}

