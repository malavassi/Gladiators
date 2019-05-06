//
// Created by fabian152195 on 04/05/19.
//

#ifndef GLADIATORS_GENERACION_H
#define GLADIATORS_GENERACION_H

#include "LinkedList.h"
#include "Gladiator.h"

/**
 * Clase encargada de representar las generaciones
 * @author fabian
 * */
//Generacion u 'oleada' se compone de dos poblaciones
class Generacion {

private:
    LinkedList<Gladiator*> gladiadores; /**Gladiadores de esta generacion */
    //static int contador; /**Contador de generaciones, aumenta con cada nueva generacion*/
    int numero; /**Numero de oleada*/
    int promedio_supervivencia; /**El promedio de de la probabilidad de supervivencia de la generacion en su mejor momento*/
    const int numero_gladiadores = 7; /**Numero de gladiadores por crear, mantenerlo par para la reproduccion*/
    int average_age; /**Edad promedio de los gladiadores*/

public:
    /**Constructor vacio, solo se ejecuta en la primera generacion*/
    Generacion(int numero);
    /**
     * Constructor comun, se ejecuta en todas las demas generaciones.
     * Establece la lista de gladiadores que se le pasa como la propia.
     * @param gladiadores Lista de punteros a gladiadores que va a usar como propia.
     * @author elorim
     * */
    Generacion(LinkedList<Gladiator*> gladiadores, int numero);
    ~Generacion();

    /**
     * Avanza la edad de todos los gladiadores veinte annos
     * @author elorim
     * */
    void avanzarEdad();

    //getters y setters
    int getNumero();
    int getPromedioSupervivencia();
    LinkedList<Gladiator*> getGladiadores();
    int getEdad();

};


#endif //GLADIATORS_GENERACION_H
