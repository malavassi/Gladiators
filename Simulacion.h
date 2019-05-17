//
// Created by kevin on 05/05/19.
//

#ifndef GLADIATORS_SIMULACION_H
#define GLADIATORS_SIMULACION_H
#include"Poblacion.h"
#include "mainwindow.h"
#include <iostream>

/**
 * Clase encargada del flow del programa
 * @author elorim
 * @date 05/05/19
 * */
 using namespace std;
class Simulacion {
public:
    /**
     * Constructor, inicializa todas las variables para dar inicio, aqui se crea la primera iteracion
     * @author elorim
     * */
    Simulacion();
    ~Simulacion();

    /**
     * Inicia la simulacion, asume primera generacion iniciada
     * @author elorim
     * */
    void iniciar();
private:
    //Atributos
    Poblacion* poblacionA;
public:
    Poblacion *getPoblacionA() const;

    Poblacion *getPoblacionB() const;

private:
    /**Poblacion de A*/
    Poblacion* poblacionB; /**Poblacion de Backtracking*/

    //Metodos
    void siguienteIteracion();

};


#endif //GLADIATORS_SIMULACION_H
