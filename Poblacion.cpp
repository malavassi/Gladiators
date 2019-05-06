//
// Created by kevin on 05/05/19.
//

#include <cstdlib>
#include <tgmath.h>
#include "Poblacion.h"

Poblacion::Poblacion(char id) { // Se ejecuta solo una vez, en la primera generacion, cuando all inicia
    cout<<"  Creando la poblacion "<< id<<endl;
    generaciones = LinkedList<Generacion*>();  // Inicializa la lista de generaciones
    this->id = id;  // Establece mi id
    Generacion* generacion = new Generacion(generacion_c);  // Crea una nueva generacion
    generaciones.push_front(generacion); // agrego la nueva generacion a generaciones
    generacion_c++;
    elegido = nullptr;  // Establezco en nulo el men que falta
    cout<<"  Se creo la poblacion "<<id<<endl;
    cout<<"  Ejecutando funcion fitness sobre la poblacion "<<id<<" total\n";
    fitness_local();
    cout<<"  Funcion fitness finalizada"<<endl;
    cout<<"  Ejecutando funcion de seleccion"<<endl;
    seleccion();
    cout<<"  Funcion de seleccion finalizada\n";
}

Poblacion::~Poblacion() {
    delete elegido;
}

void Poblacion::fitness_local() {
    for(int generacion_c=0;generacion_c<generaciones.getSize();generacion_c++){ // Iterador de generaciones
        Generacion* genActual = generaciones.getElemento(generacion_c)->getData(); // Generacion actual sobre la que se trabaja
        genActual->avanzarEdad(); // Avanza la edad de todas las generaciones, menos de las recien nacidas
        if(genActual->getEdad()>=100){
            cout<<"Rezamos porque "<<generacion_c<<" vaya con Noguera\n";
             (generaciones.pop_element(generacion_c));
        }

        for(int gladiador_c=0;gladiador_c<genActual->getGladiadores().getSize();gladiador_c++){ // Iterador de gladiadores
            // Logica de fitness starts
            Gladiator* gladiador = genActual->getGladiadores().getElemento(gladiador_c)->getData(); // Gladiador en el que voy a trabajar

            // Primero bajo atributos fisicos segun la edad
            int reduce = (10*gladiador->getEdad()/20) - 10;  // Cada 20 annos bajo un 10%
            cout<<"    Al gladiador "<<gladiador->getIdUnico()<<" se le disminuiran sus atributos un "<<reduce<<"%"<<" debido a su edad de: "<<gladiador->getEdad()<<endl;
            // Calcula nuevos atributos
            if(reduce!=0) {
                cout << "      Su CF pasa de: " << gladiador->getCondicionFisica();
                int nuevCF = gladiador->getCondicionFisica() - gladiador->getCondicionFisica() * reduce / 100;
                cout << " a " << nuevCF << endl;
                cout << "      Su FTS pasa de: " << gladiador->getFuerzaTSuperior();
                int nuevFS = gladiador->getFuerzaTSuperior() - gladiador->getFuerzaTSuperior() * reduce / 100;
                cout << " a " << nuevFS << endl;
                cout << "      Su FTI pasa de: " << gladiador->getCondicionFisica();
                int nuevFI = gladiador->getFuerzaTInferior() - gladiador->getFuerzaTInferior() * reduce / 100;
                cout<<" a "<<nuevFI<<endl;
                // Settea nuevos atributos
                gladiador->setAtributes(gladiador->getIQemocional(), nuevCF, nuevFS, nuevFI,
                                        false);  // Siempre que se ejecute el fitness los gladiadores no van a ser recien nacidos, por eso es false
            }else{
                cout<<"      Los atributos quedan intactos"<<endl;
            }

            //Segundo, sumo la nueva resistencia
            int nuevRes = gladiador->getIQemocional()*20/100+gladiador->getFuerzaTInferior()*25/100+ gladiador->getFuerzaTSuperior()*25/100+
                    gladiador->getCondicionFisica()*30/100;  // Agregar porcentajes si es necesario
            gladiador->setResistencia(nuevRes);  // Setteo la res
            cout<<"    Basado en sus atributos, el gladiador "<<gladiador->getIdUnico()<<" posee una resistencia de:"<<gladiador->getResistencia()<<endl;

            //Tercero, calculo la nueva probabilidad de supervivencia
            int nuevProb = gladiador->getResistencia();  // Por el momento es llanamente la resistencia
            gladiador->setProbabilidadSupervivencia(nuevProb);  // Setteo la probabilidad
            cout<<"    La probabilidad de supervivencia es de:"<<gladiador->getProbabilidadSupervivencia()<<endl;
        }
    }
}

void Poblacion::seleccion() {
    Gladiator* best = elegido;  // Puntero que apunta al mejor gladiador
    for(int generacion_c=0;generacion_c<generaciones.getSize();generacion_c++){ // Iterador de generaciones
        Generacion* genActual = generaciones.getElemento(generacion_c)->getData(); // Generacion actual sobre la que se trabaja
        for(int gladiador_c=0;gladiador_c<genActual->getGladiadores().getSize();gladiador_c++){ // Iterador de gladiadores
            // Logica de seleccion starts
            Gladiator* gladiador = genActual->getGladiadores().getElemento(gladiador_c)->getData(); // Gladiador en el que voy a trabajar
            if(best == nullptr){  // Si no hay un best aun
                cout<<"    Debido a que no existe un campeon, gladiador "<<gladiador->getIdUnico()<<" tomara la vacante, con una probabilidad de supervivencia de:"
                <<gladiador->getProbabilidadSupervivencia()<<endl;
                best = gladiador;
            }else{
                if(gladiador->getProbabilidadSupervivencia()>best->getProbabilidadSupervivencia()){  // Si la probabilidad de superviviencia del actual es mejor que la del mejor, reemplace
                    cout<<"    Gladiador "<<gladiador->getIdUnico()<<" con su probabilidad de supervivencia de: "<<gladiador->getProbabilidadSupervivencia()<<
                    " ha mejorado al previo campeon, gladiador "<<best->getIdUnico()<< "de probabilidad de supervivencia de:"<<best->getProbabilidadSupervivencia()
                    <<" tenemos nuevo campeon.\n";
                    best = gladiador;
                }// Si no pues no hace nada
            }
        }
    }
    cout<<"    Gladiador "<<best->getIdUnico()<<" se ha coronado campeon, es el elegido por Dios Noguera para entrar a la zona de intimidacion, que su sacrificio no sea en vano\n";
    elegido = best;  // Setteo al mejor como el elegido


}

Gladiator *Poblacion::getElegido() {
    return elegido;
}

void Poblacion::reproduccion() {
    cout<<"  Inicia la reproduccion de la poblacion "<<id<<endl;
    // Crea la nueva generacion
    LinkedList<Gladiator*> nuevos = LinkedList<Gladiator*>();

    // CROSSOVER
    LinkedList<Gladiator*> to_reproduce = LinkedList<Gladiator*>();  // Lista en la que se va a guardar a los menes que hay que reproducir
    // Populando la lista
    for(int generacion_c=0;generacion_c<generaciones.getSize();generacion_c++){ // Iterador de generaciones
        Generacion* genActual = generaciones.getElemento(generacion_c)->getData(); // Generacion actual sobre la que se trabaja
        for(int gladiador_c=0;gladiador_c<genActual->getGladiadores().getSize();gladiador_c++){ // Iterador de gladiadores
            Gladiator* gladiador = genActual->getGladiadores().getElemento(gladiador_c)->getData(); // Gladiador en el que voy a trabajar
            to_reproduce.push_front(gladiador); // agregando el gladiador
        }
    }

    // Ordenar la lista
    bubbleSort(to_reproduce); // Ordena la lista
    cout<<"  Las parejas son las siguientes:\n";
    for(int i=0;i<to_reproduce.getSize();i+=2){
        if(i+1<to_reproduce.getSize()) {
            cout << "    Gladiador " << to_reproduce.getElemento(i)->getData()->getResistencia() << " con gladiador "
                 << to_reproduce.getElemento(i + 1)->getData()->getIdUnico() << endl;
        }else{
            cout<<"      Gladiador "<<to_reproduce.getElemento(i)->getData()->getResistencia() << " no tiene pareja";
        }
    }

    while(to_reproduce.getSize()>0){ // Se mantiene siempre que hayan elementos en la lista

        // Elijo dos padres (esta asegurado que sera random porque la lista se aleatoriza cada vez que corre la funcion)
        Gladiator* padre1 = to_reproduce.pop_front();
        Gladiator* padre2 = to_reproduce.pop_front();
        if(padre1 && padre2) {  // Revisa que ambos existan, si no existe uno o ambos, no reproduce, esto porque algunas veces puede que no hayan parejas
            Gladiator *nuevo = new Gladiator(); // Creo un nuevo gladiador en blanco
            cout << "      El bebe gladiador es: " << nuevo->getIdUnico() << endl;

            // Genero dos numeros random que van a ser los atributos que el primer padre va a pasar al hijo
            int veces = 0;
            int attr_pasar[] = {-1, -1, -1, -1}; // Inicializo en -1 para indicar que no se han asignado
            int pasado = -1; // Aqui guardo el atributo que ya asigno para que no asigne el mismo de nuevo
            while (veces != 2) {  // Termina cuando se ejecuta dos veces
                int attr = rand() % 4; // Numero random del 0 al 4
                while (pasado == attr) {  // Se fija que no sea el mismo numero que el pasado, si lo es, cambia
                    attr = rand() % 4;  // Recalculo
                }
                attr_pasar[attr] = padre1->getAttr(attr);
                switch (attr) {
                    case 0:
                        cout << "        El bebe tiene la inteligencia de gladiador " << padre1->getIdUnico() << endl;
                        break;
                    case 1:
                        cout << "        El bebe tiene el pecho de gladiador " << padre1->getIdUnico() << endl;
                        break;
                    case 2:
                        cout << "        El bebe tiene las piernas de gladiador " << padre1->getIdUnico() << endl;
                        break;
                    case 3:
                        cout << "        El bebe tiene el aguante de gladiador " << padre1->getIdUnico() << endl;
                }
                pasado = attr; // guardo el pasado
                veces++;  // itero
            }

            //Asigno los dos atributos que no fueron asignados antes
            for (int i = 0; i < 4; i++) {
                if (attr_pasar[i] == -1) {  // Si el atributo i es -1 (no fue asignado)
                    attr_pasar[i] = padre2->getAttr(i);  // Le asigna el atributo i del padre2
                    switch (i) {
                        case 0:
                            cout << "        El bebe tiene la inteligencia de gladiador " << padre2->getIdUnico()
                                 << endl;
                            break;
                        case 1:
                            cout << "        El bebe tiene el pecho de gladiador " << padre2->getIdUnico() << endl;
                            break;
                        case 2:
                            cout << "        El bebe tiene las piernas de gladiador " << padre2->getIdUnico() << endl;
                            break;
                        case 3:
                            cout << "        El bebe tiene el aguante de gladiador " << padre2->getIdUnico() << endl;
                    }
                }
            }

            // Setteo los atributos al bebe
            nuevo->setAtributesI(attr_pasar); // Setteo los atributos iniciales

            // FIN CROSSOVER

            // MUTACION
            int mutacion = rand() % 100 + 1; // tira los dados del destino
            int inversion = rand() % 100 + 1;
            if (mutacion <= 20) { // 10% de probabilidades de mutar
                cout << "       El bebe tuvo suerte, sucedera mutacion\n";
                mutar(nuevo);  // Muto
                cout << "      Fin de mutacion\n";
            }
            if (inversion <= 10) {  // 5% de probabilidades de inversion
                cout << "      El bebe tuvo suerte, sucedera inversion\n";
                invertir(nuevo); // Invierto
                cout << "      Fin de inversion\n";
            }
            cout << "        Atributos finales del bebe:" << " IQ:" << nuevo->getIQemocional() << " FS:"
                 << nuevo->getFuerzaTSuperior() <<
                 " FI:" << nuevo->getFuerzaTInferior() << " CF:" << nuevo->getCondicionFisica() << endl;

            nuevos.push_front(nuevo);  // Agrega a la lista de la nueva generacion
        }

    }  // Repite

    generaciones.push_front(new Generacion(nuevos, generacion_c));  // Crea la nueva generacion y la agrega a la lista de generaciones
    cout<<"Nacio una bella nueva generacion de: "<<generaciones.front()->getGladiadores().getSize()<<" bebes!\n";
    generacion_c++;

}

void Poblacion::mutar(Gladiator *gladiador) {
    int attrMutar = rand()%4; // Aleatoriza el atributo a mutar
    switch(attrMutar){
        case 0:
            cout<<"        El bebe sera mas inteligente\n";
            break;
        case 1:
            cout<<"        El bebe sera mas fuerte de pecho\n";
            break;
        case 2:
            cout<<"        El bebe sera mas grueso de piernas\n";
            break;
        case 3:
            cout<<"        El bebe tendra mas estamina\n";
            break;
    }
    int newAttrs[4]; // Nuevo array de atributos
    for(int i=0;i<4;i++){  // iterando atributos
        if(i==attrMutar){  // si el atributo actual es igual al atributo a mutar, mute
            cout<<"        El atributo del bebe pasa de: "<<gladiador->getAttr(i)<<" a ";
            newAttrs[i] = (gladiador->getAttr(i))+(gladiador->getAttr(i))*60/100;  // Sumando el 60% y guardando
            cout<<newAttrs[i]<<endl;
        }else{  // si no
            newAttrs[i] = gladiador->getAttr(i);  // Solo metalo al array
        }
    }
    gladiador->setAtributesM(newAttrs);
}

void Poblacion::invertir(Gladiator *gladiador) {
    int inicio = rand()%4; // inicio a invertir
    while(inicio==3){  // Evitar que sea el final, porque si no no hay que invertir
        inicio = rand()%4;
    }
    int final = rand()%4; // final de la inversion
    while(final<=inicio) { // Evitar que el final sea el inicio o menor, si no no hay que invertir
        final = rand() % 4;
    }

    int arr[4] = {gladiador->getAttr(0),gladiador->getAttr(1),gladiador->getAttr(2),gladiador->getAttr(3)};  // array sobre el que se trabajara

    // Invirtiendo
    int size = final-inicio; // Calculando el tamanno del subarray a invertir
    for(int i=inicio;i<inicio+ceil(size/2);i++){ // Iterando el subarray, termina cuando llega a la mitad de la longitud del subarray
        int inverso = 3-i; // La posicion inversa de la posicion i es la posicion arrSize-1-i
        int temp = arr[inverso];
        arr[inverso] = arr[i];
        arr[i] = temp;
    }
    // Despues de este proceso arr es el array invertido

    // Settear
    gladiador->setAtributesI(arr);
}


void Poblacion::bubbleSort(LinkedList<Gladiator*> lista)
{
    int i, j;
    for (i = 0; i < lista.getSize()-1; i++)
        // Last i elements are already in place
        for (j = 0; j < lista.getSize()-i-1; j++)
            if (lista.getElemento(j)->getData()->getResistencia() < lista.getElemento(j+1)->getData()->getResistencia())
                swap(j, j+1, lista);
}

void Poblacion::swap(int i, int j, LinkedList<Gladiator*> lista)
{
    Gladiator* tmp = lista.getElemento(i)->getData();
    lista.getElemento(i)->setData(lista.getElemento(j)->getData());
    lista.getElemento(j)->setData(tmp);
}