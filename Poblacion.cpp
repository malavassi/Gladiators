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

Gladiator *Poblacion::getElegido() {
    return elegido;
}

void Poblacion::reproduccion() {

    // CROSSOVER
    LinkedList<Gladiator*> to_reproduce = LinkedList<Gladiator*>();  // Lista en la que se va a guardar a los menes que hay que reproducir
    // Populando la lista
    for(int generacion_c=0;generacion_c<generaciones.getSize();generacion_c++){ // Iterador de generaciones
        Generacion genActual = generaciones.getElemento(generacion_c)->getData(); // Generacion actual sobre la que se trabaja
        for(int gladiador_c=0;gladiador_c<genActual.getGladiadores().getSize();gladiador_c++){ // Iterador de gladiadores
            Gladiator* gladiador = genActual.getGladiadores().getElemento(gladiador_c)->getData(); // Gladiador en el que voy a trabajar
            to_reproduce.push_front(gladiador); // agregando el gladiador
        }
    }

    // Aleatorizar la lista
    to_reproduce.randomize(); // Aleatoriza la lista

    while(to_reproduce.getSize()>0){ // Se mantiene siempre que hayan elementos en la lista

        // Elijo dos padres (esta asegurado que sera random porque la lista se aleatoriza cada vez que corre la funcion)
        Gladiator* padre1 = to_reproduce.pop_front();
        Gladiator* padre2 = to_reproduce.pop_front();
        Gladiator* nuevo = new Gladiator(); // Creo un nuevo gladiador en blanco

        // Genero dos numeros random que van a ser los atributos que el primer padre va a pasar al hijo
        int veces = 0;
        int attr_pasar[] = {-1,-1,-1,-1}; // Inicializo en -1 para indicar que no se han asignado
        int pasado = -1; // Aqui guardo el atributo que ya asigno para que no asigne el mismo de nuevo
        while(veces != 2) {  // Termina cuando se ejecuta dos veces
            int attr = rand() % 4; // Numero random del 0 al 4
            while (pasado == attr) {  // Se fija que no sea el mismo numero que el pasado, si lo es, cambia
                attr = rand() % 4;  // Recalculo
            }
            attr_pasar[attr] = padre1->getAttr(attr);
            pasado = attr; // guardo el pasado
            veces++;  // itero
        }

        //Asigno los dos atributos que no fueron asignados antes
        for(int i=0;i<4;i++){
            if(attr_pasar[i] == -1){  // Si el atributo i es -1 (no fue asignado)
                    attr_pasar[i] = padre2->getAttr(i);  // Le asigna el atributo i del padre 2
                }
        }

        // Setteo los atributos al bebe
        nuevo->setAtributesI(attr_pasar); // Setteo los atributos iniciales

        // FIN CROSSOVER

        // MUTACION



    }


}
