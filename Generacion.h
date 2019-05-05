//
// Created by fabian152195 on 04/05/19.
//

#ifndef GLADIATORS_GENERACION_H
#define GLADIATORS_GENERACION_H

#include "LinkedList.h"
#include "Gladiator.h"


//Generacion u 'oleada' se compone de dos poblaciones
class Generacion {

private:
    LinkedList<Gladiator> * poblacionA;
    LinkedList<Gladiator> * poblacionB;

public:

    Generacion();

    //getters y setters

    LinkedList<Gladiator> *getPoblacionA() const;

    void setPoblacionA(LinkedList<Gladiator> *poblacionA);

    LinkedList<Gladiator> *getPoblacionB() const;

    void setPoblacionB(LinkedList<Gladiator> *poblacionB);

};


#endif //GLADIATORS_GENERACION_H
