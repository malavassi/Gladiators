//
// Created by kevin on 05/05/19.
//
#ifndef INC_2_POBLACION_H
#define INC_2_POBLACION_H

#include "LinkedList.h"
#include "Generacion.h"
#include "Gladiator.h"

/**
 * Clase representativa de cada poblacion
 * @author Elorim
 * @date 05/05/19
 * */
class Poblacion {
public:

    Poblacion(){};
    Poblacion(char id);
    ~Poblacion();

    /**
     * Funcion encargada de seleccionar el mejor gladiador
     * @author Elorim
     * */
    void seleccion();
    /**
     * Funcion encargada de reproducir la poblacion, crea inmediatamente la siguiente generacion
     * @author Elorim
     * */
    void reproduccion();
    /**
     * Funcion de fitness local. Calcula la probabilidad de supervivencia de cada individuo
     * y recalcula los stats de cada uno.
     * @author Elorim
     * */
    void fitness_local();

    // Getters & Setters
    Gladiator* getElegido();
private:
    //Atributos
    LinkedList<Generacion> generaciones; /** Generaciones de esta poblacion*/
    Gladiator* elegido;  /**Gladiador elegido para la siguiente iteracion*/
    char id; /**Identificador de la poblacion, A o B*/

    //Funciones
};


#endif //INC_2_POBLACION_H
