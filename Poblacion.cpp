//
// Created by kevin on 05/05/19.
//

#include <cstdlib>
#include "Poblacion.h"

Poblacion::Poblacion(char id) { // Se ejecuta solo una vez, en la primera generacion, cuando all inicia
    generaciones = LinkedList<Generacion>();  // Inicializa la lista de generaciones
    this->id = id;  // Establece mi id
    Generacion generacion = Generacion();  // Crea una nueva generacion
    generaciones.push_front(generacion); // agrego la nueva generacion a generaciones
    elegido = nullptr;  // Establezco en nulo el men que falta
}

Poblacion::~Poblacion() {
    delete elegido;
}

void Poblacion::fitness_local() {
    for(int generacion_c=0;generacion_c<generaciones.getSize();generacion_c++){ // Iterador de generaciones
        Generacion genActual = generaciones.getElemento(generacion_c)->getData(); // Generacion actual sobre la que se trabaja
        for(int gladiador_c=0;gladiador_c<genActual.getGladiadores().getSize();gladiador_c++){ // Iterador de gladiadores
            // Logica de fitness starts
            Gladiator* gladiador = genActual.getGladiadores().getElemento(gladiador_c)->getData(); // Gladiador en el que voy a trabajar

            // Primero bajo atributos fisicos segun la edad
            int reduce = (10*gladiador->getEdad()/20) - 10;  // Cada 20 annos bajo un 10%
            // Calcula nuevos atributos
            int nuevCF = gladiador->getCondicionFisica() - gladiador->getCondicionFisica()*reduce/100;
            int nuevFS = gladiador->getFuerzaTSuperior() - gladiador->getFuerzaTSuperior()*reduce/100;
            int nuevFI = gladiador->getFuerzaTInferior() - gladiador->getFuerzaTInferior()*reduce/100;
            // Settea nuevos atributos
            gladiador->setAtributes(gladiador->getIQemocional(), nuevCF, nuevFS, nuevFI, false);  // Siempre que se ejecute el fitness los gladiadores no van a ser recien nacidos, por eso es false

            //Segundo, sumo la nueva resistencia
            int nuevRes = gladiador->getIQemocional()+gladiador->getFuerzaTInferior()+ gladiador->getFuerzaTSuperior()+
                    gladiador->getCondicionFisica();  // Agregar porcentajes si es necesario
            gladiador->setResistencia(nuevRes);  // Setteo la res

            //Tercero, calculo la nueva probabilidad de supervivencia
            int nuevProb = rand()%100 + 1;  // Por el momento es aleatoria
            gladiador->setProbabilidadSupervivencia(nuevProb);  // Setteo la probabilidad
        }
    }
}

void Poblacion::seleccion() {
    Gladiator* best = nullptr;  // Puntero que apunta al mejor gladiador
    for(int generacion_c=0;generacion_c<generaciones.getSize();generacion_c++){ // Iterador de generaciones
        Generacion genActual = generaciones.getElemento(generacion_c)->getData(); // Generacion actual sobre la que se trabaja
        for(int gladiador_c=0;gladiador_c<genActual.getGladiadores().getSize();gladiador_c++){ // Iterador de gladiadores
            // Logica de seleccion starts
            Gladiator* gladiador = genActual.getGladiadores().getElemento(gladiador_c)->getData(); // Gladiador en el que voy a trabajar
            if(best == nullptr){  // Si no hay un best aun
                best = gladiador;
            }else{
                if(gladiador->getProbabilidadSupervivencia()>best->getProbabilidadSupervivencia()){  // Si la probabilidad de superviviencia del actual es mejor que la del mejor, reemplace
                    best = gladiador;
                }// Si no pues no hace nada
            }
        }
    }
    elegido = best;  // Setteo al mejor como el elegido


}
