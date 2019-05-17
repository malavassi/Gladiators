//
// Created by fabian152195 on 04/05/19.
//

#include <clocale>
#include <ctime>
#include <cstdlib>
#include "Generacion.h"
//int Generacion::contador = 0; // Es estatica para que sea automatica
Generacion::Generacion(int numero) {  // Solo ejecutar la primera generacion
    promedio_supervivencia = 0;
    cout<<"    Creando la primera generacion\n";
    gladiadores = LinkedList<Gladiator*>(); // Crea la lista de generaciones
    this->numero = numero;  // guarda el numero de generacion
    //Generacion::contador++;  // Aumenta la variable estatica

     // Lo tenia fabian, no se que hace

    if(numero == 0){  // Si es la primera generacion
        while (gladiadores.getSize() < numero_gladiadores) {
            int condicionFisicaRandom = (rand() % 4) + 1;  // Calcula valores random de attrs
            int fuerzaTInferiorRandom = (rand() % 4) + 1;
            int fuerzaTSuperiorRandom = (rand() % 4) + 1;
            int IQEmocional = (rand() % 4) + 1;

            Gladiator* gladiador = new Gladiator(condicionFisicaRandom, fuerzaTInferiorRandom, fuerzaTSuperiorRandom,
                    IQEmocional);  // Crea el gladiador
            gladiadores.push_back(gladiador);  // Lo agrega a la lista
        } // repite por la cantidad de gladiadores que se quieran crear
    }
    cout<<"    Se creo la primera generacion con: "<<gladiadores.getSize()<<" gladiadores\n";
}

LinkedList<Gladiator *> Generacion::getGladiadores() {
    return gladiadores;
}


int Generacion::getNumero() {
    return numero;
}

Generacion::~Generacion() {

}

Generacion::Generacion(LinkedList<Gladiator *> gladiadores, int numero) {
    this->gladiadores = gladiadores;
    this->numero = numero;
    //Generacion::contador++;

}

void Generacion::addProm(int valor){
    promedio_supervivencia += (valor/20);
}

void Generacion::avanzarEdad() {
    average_age +=20;
    for(int i=0;i<gladiadores.getSize();i++){
        gladiadores.getElemento(i)->getData()->avanzarEdad();
    }


}

int Generacion::getEdad() {
    return average_age;
}

