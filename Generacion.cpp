//
// Created by fabian152195 on 04/05/19.
//

#include <clocale>
#include <ctime>
#include <cstdlib>
#include "Generacion.h"
int Generacion::contador = 0; // Es estatica para que sea automatica
Generacion::Generacion() {  // Solo ejecutar la primera generacion
    gladiadores = LinkedList<Gladiator*>(); // Crea la lista de generaciones
    numero = Generacion::contador;  // guarda el numero de generacion
    Generacion::contador++;  // Aumenta la variable estatica

    srand(time(NULL)); // Lo tenia fabian, no se que hace

    if(numero == 0){  // Si es la primera generacion
        while (gladiadores.getSize() < numero_gladiadores) {
            int condicionFisicaRandom = (rand() % 20) + 1;  // Calcula valores random de attrs
            int fuerzaTInferiorRandom = (rand() % 20) + 1;
            int fuerzaTSuperiorRandom = (rand() % 20) + 1;
            int IQEmocional = (rand() % 20) + 1;

            Gladiator* gladiador = new Gladiator(condicionFisicaRandom, fuerzaTInferiorRandom, fuerzaTSuperiorRandom,
                    IQEmocional);  // Crea el gladiador
            gladiadores.push_back(gladiador);  // Lo agrega a la lista
        } // repite por la cantidad de gladiadores que se quieran crear

    }
}

LinkedList<Gladiator *> Generacion::getGladiadores() {
    return gladiadores;
}

int Generacion::getPromedioSupervivencia() {
    return promedio_supervivencia;
}

int Generacion::getNumero() {
    return numero;
}

Generacion::~Generacion() {

}

