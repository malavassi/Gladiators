//
// Created by kevin on 05/05/19.
//
#ifndef INC_2_POBLACION_H
#define INC_2_POBLACION_H

#include "LinkedList.h"
#include "Generacion.h"
#include <iostream>
#include "Gladiator.h"
#include "ZonaIntimidacion.h"
/**
 * Clase representativa de cada poblacion
 * @author Elorim
 * @date 05/05/19
 * */
 using namespace std;
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

    ZonaIntimidacion *getZonaIntimidacion() const;

    void setZonaIntimidacion(ZonaIntimidacion *zonaIntimidacion);

private:
    ZonaIntimidacion * zonaIntimidacion;
    //Atributos
    int generacion_c = 0; /**Contador con el numero de generaciones*/
    LinkedList<Generacion*> generaciones; /** Generaciones de esta poblacion*/
    Gladiator* elegido;  /**Gladiador elegido para la siguiente iteracion*/


    char id; /**Identificador de la poblacion, A o B*/

    //Funciones
    /**
     * Muta al gladiador que se le pasa. La mutacion tiene un 10% de probabilidades de darse
     * y consiste en agarrar un valor random del array de atributos y sumarle el 30% de ese atributo
     * @param gladiador Gladiador a mutar.
     * @author elorim
     * */
    void mutar(Gladiator* gladiador);

    /**
     * Invierte al gladiador que se le pasa. La inversion tiene un 5% de probabildades de suceder
     * y consiste en tomar un valor inicial al azar y un valor final al azar del array de atributos
     * e invertir ese sub array.
     *
     * Ejemplo:
     *
     * Tengo un array de atributos: [0,1,2,3] y mis valores aleatorios son: inicial 1, final 3
     * entonces invierto desde la posicion 1 a la tres, quedando: [0,3,2,1]
     * @param gladiador Gladiador a invertir atributos
     * */
    void invertir(Gladiator* gladiador);


    /**
     * Funcion que identifica y retorna al gladiador con mayor resistencia en toda la poblacion
     * @return gladiador con mayor resistencia en la poblacion
     */
    Gladiator* mejorGladiador();

};


#endif //INC_2_POBLACION_H
