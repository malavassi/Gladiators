//
// Created by kevin on 05/05/19.
//

#include "Simulacion.h"

void Simulacion::iniciar() {
    bool terminar = false;
    while(terminar == false){
    cout<<"\n";
    cout<<"Introduzca un comando:\n 1: Reproducir\n0: Finalizar\n";
    int seleccion;
    cin>>seleccion;
    switch(seleccion){
        case 1:
            siguienteIteracion();
            break;
        case 0:
            terminar = true;
            break;
    }
    }
}

Simulacion::Simulacion() {  // Ya creo la oleada inicial
    cout<<"Creando oleadas iniciales\n";
    this->poblacionA = new Poblacion('A');
    this->poblacionB = new Poblacion('B');
    cout<<"Oleadas iniciales generadas\n";
    cout<<"Los elegidos son: gladiador "<<poblacionA->getElegido()->getIdUnico()<<" de la poblacion A con "<<
    poblacionA->getElegido()->getProbabilidadSupervivencia()<<"% y gladiador "<<
        poblacionB->getElegido()->getIdUnico()<<" de la poblacion B con "<<poblacionB->getElegido()->getProbabilidadSupervivencia()
        <<"% que Noguera bendiga su sacrificio\n";
}

Simulacion::~Simulacion() {

}

void Simulacion::siguienteIteracion() {
    cout<<"Los gladiadores han vuelto de sus combates, no comieron ceviche\n";
    poblacionA->reproduccion();
    poblacionB->reproduccion();
    cout<<"Veinte annos han pasado y es hora de hacer tribulaciones a Noguera, quienes seran los elegidos?\n";
    poblacionA->fitness_local();
    poblacionB->fitness_local();
    cout<<"Llego la hora de hacer libaciones a Noguera\n";
    cout<<"  Seleccionando en la poblacion A\n";
    poblacionA->seleccion();
    cout<<"  Seleccionando en la poblacion B\n";
    poblacionB->seleccion();
    cout<<"Los elegidos son: gladiador "<<poblacionA->getElegido()->getIdUnico()<<" de la poblacion A con "<<
    poblacionA->getElegido()->getProbabilidadSupervivencia()<<"% y gladiador "<<
        poblacionB->getElegido()->getIdUnico()<<" de la poblacion B con "<<poblacionB->getElegido()->getProbabilidadSupervivencia()
        <<"% que Noguera bendiga su sacrificio\n";

}
