//
// Created by kevin on 05/05/19.
//

#include <cstdlib>
#include <tgmath.h>
#include "Poblacion.h"
#include <fstream>
#include <string>
using namespace std;
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

void Poblacion::generarTXT_gladiadortop(Gladiator gladiador) {
    fstream salida;
    string nombreArchivo = "TopGladiador - Generacion";
    string num = to_string(this->generacion_c);
    for(int i = 0; i < num.size(); i++){
        nombreArchivo.push_back(num[i]);
    }
    nombreArchivo.push_back(this->id);
    salida.open(nombreArchivo, ios::out);
    salida.trunc;
    if(this->generacion_c != 1) {
        cout << "El fichero esta abierto: " << salida.is_open() << endl;
        salida << "                     MEJOR GLADIADOR                       " << endl;
        salida << "-----------------------------------------------------------" << endl;
        salida << "-----------------------  GLADIADOR  -----------------------" << endl;
        salida << "-----------------------------------------------------------" << endl << endl;
        salida << "Identificador unico: " << gladiador.getIdUnico() << endl << endl;
        salida << "Edad: " << gladiador.getEdad() << endl << endl;
        salida << "Probabilidad de supervivencia: " << gladiador.getProbabilidadSupervivencia() << endl << endl;
        salida << "Generaciones esperadas de supervivencia: " << gladiador.getGeneracionesEsperadas() << endl << endl;
        salida << "Inteligencia emocional: " << gladiador.getIQemocional() << endl << endl;
        salida << "Condicion fisica: " << gladiador.getCondicionFisica() << endl << endl;
        salida << "Fuerza en tronco superior: " << gladiador.getFuerzaTSuperior() << endl << endl;
        salida << "Fuerza en tronco inferior: " << gladiador.getFuerzaTInferior() << endl << endl;
        salida << "Resistencia: " << gladiador.getResistencia() << endl << endl;
        salida << "Padre 1: " << gladiador.getPadre1()->getIdUnico() << endl << endl;
        salida << "Padre 2: " << gladiador.getPadre2()->getIdUnico() << endl << endl;
        salida << "-----------------------------------------------------------" << endl;
    }else{
        cout << "El fichero esta abierto: " << salida.is_open() << endl;
        salida << "                     MEJOR GLADIADOR                       " << endl;
        salida << "-----------------------------------------------------------" << endl;
        salida << "-----------------------  GLADIADOR  -----------------------" << endl;
        salida << "-----------------------------------------------------------" << endl << endl;
        salida << "Identificador unico: " << gladiador.getIdUnico() << endl << endl;
        salida << "Edad: " << gladiador.getEdad() << endl << endl;
        salida << "Probabilidad de supervivencia: " << gladiador.getProbabilidadSupervivencia() << endl << endl;
        salida << "Generaciones esperadas de supervivencia: " << gladiador.getGeneracionesEsperadas() << endl << endl;
        salida << "Inteligencia emocional: " << gladiador.getIQemocional() << endl << endl;
        salida << "Condicion fisica: " << gladiador.getCondicionFisica() << endl << endl;
        salida << "Fuerza en tronco superior: " << gladiador.getFuerzaTSuperior() << endl << endl;
        salida << "Fuerza en tronco inferior: " << gladiador.getFuerzaTInferior() << endl << endl;
        salida << "Resistencia: " << gladiador.getResistencia() << endl << endl;
        salida << "Padre 1: " << "No posee" << endl << endl;
        salida << "Padre 2: " << "No posee" << endl << endl;
        salida << "-----------------------------------------------------------" << endl;
    }
    salida.close();
}

void Poblacion::generarTXT_top10(LinkedList<Gladiator*> lista) {
    fstream salida1;
    string nombreArchivo = "Top10 - Generacion";
    string num = to_string(this->generacion_c);
    for(int i = 0; i < num.size(); i++){
        nombreArchivo.push_back(num[i]);
    }
    nombreArchivo.push_back(this->id);
    salida1.open(nombreArchivo, ios::out);
    salida1.trunc;
    cout << "El fichero esta abierto: " << salida1.is_open() << endl;
    salida1 << "                     TOP 10 GLADIADORES" << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 1 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(0)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(0)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 2 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(1)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(1)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 3 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(2)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(2)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 4 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(3)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(3)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 5 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(4)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(4)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 6 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(5)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(5)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 7 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(6)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(6)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 8 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(7)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(7)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 9 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(8)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(8)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1 << "----------------------- GLADIADOR 10 -----------------------" << endl;
    salida1 << "-----------------------------------------------------------" << endl << endl;
    salida1 << "Identificador unico: " << lista.getElemento(9)->getData()->getIdUnico() << endl << endl;
    salida1 << "Resistencia: " << lista.getElemento(9)->getData()->getResistencia() << endl << endl;
    salida1 << "-----------------------------------------------------------" << endl;
    salida1.close();
}

void Poblacion::fitness_local() {
    for(int generacion_ca=0;generacion_ca<generaciones.getSize();generacion_ca++){ // Iterador de generaciones
        Generacion* genActual = generaciones.getElemento(generacion_ca)->getData(); // Generacion actual sobre la que se trabaja
        genActual->avanzarEdad(); // Avanza la edad de todas las generaciones, menos de las recien nacidas
        /*if(genActual->getEdad()>=100){
            cout<<"Rezamos porque "<<generacion_c<<" vaya con Noguera\n";
             (generaciones.pop_element(generacion_c));
        }*/

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
                cout << "      Su FTI pasa de: " << gladiador->getFuerzaTInferior();
                int nuevFI = gladiador->getFuerzaTInferior() - gladiador->getFuerzaTInferior() * reduce / 100;
                cout<<" a "<<nuevFI<<endl;
                // Settea nuevos atributos
                gladiador->setAtributes(gladiador->getIQemocional(), nuevCF, nuevFS, nuevFI,
                                        false);  // Siempre que se ejecute el fitness los gladiadores no van a ser recien nacidos, por eso es false
            }else{
                cout<<"      Los atributos quedan intactos"<<endl;
            }

            //Segundo, sumo la nueva resistencia
            int nuevRes = gladiador->getIQemocional()*1+gladiador->getFuerzaTInferior()*2+ gladiador->getFuerzaTSuperior()*2+
                    gladiador->getCondicionFisica()*3;  // Agregar porcentajes si es necesario
            gladiador->setResistencia(nuevRes);  // Setteo la res
            cout<<"    Basado en sus atributos, el gladiador "<<gladiador->getIdUnico()<<" posee una resistencia de:"<<gladiador->getResistencia()<<endl;

            if(genActual->getEdad()==20){
                genActual->addProm(nuevRes);
            }
        }
    }
}

void Poblacion::seleccion() {
    LinkedList<Gladiator*>* gladiadores = new LinkedList<Gladiator*>();
    for(int ge_c=0;ge_c<generaciones.getSize();ge_c++){  // Populando lista
        Generacion* actualG = generaciones.getElemento(ge_c)->getData();
        for(int g_c=0;g_c<actualG->getGladiadores().getSize();g_c++){
            gladiadores->push_front(actualG->getGladiadores().getElemento(g_c)->getData());
        }
    }
    reproducibles = LinkedList<Gladiator*>();
    for(int c = 0;c < 10;c++){
        reproducibles.push_back(bestG(gladiadores));
    }
    //Aqui generar txt 10 mejores con la lista reproducibles
    cout<<"    Gladiador "<<reproducibles.getElemento(0)->getData()->getIdUnico()<<" se ha coronado campeon, es el elegido por Dios Noguera para entrar a la zona de intimidacion, que su sacrificio no sea en vano\n";
    elegido = reproducibles.getElemento(0)->getData();  // Setteo al mejor como el elegido
    //Aqui generar txt del mejor de cada poblacion
    generarTXT_top10(reproducibles);
    generarTXT_gladiadortop(*elegido);
}

Gladiator *Poblacion::getElegido() {
    return elegido;
}

void Poblacion::reproduccion() {
    cout << "  Inicia la reproduccion de la poblacion " << id << endl;
    // Crea la nueva generacion
    LinkedList<Gladiator *> nuevos = LinkedList<Gladiator *>();

    // CROSSOVER
    LinkedList<Gladiator *> to_reproduce = reproducibles;  // Lista en la que se va a guardar a los menes que hay que reproducir
    cout << "  Las parejas son las siguientes:\n";
    for (int i = 0; i < to_reproduce.getSize(); i += 2) {
        if (i + 1 < to_reproduce.getSize()) {
            cout << "    Gladiador " << to_reproduce.getElemento(i)->getData()->getResistencia() << " con gladiador "
                 << to_reproduce.getElemento(i + 1)->getData()->getIdUnico() << endl;
        } else {
            cout << "      Gladiador " << to_reproduce.getElemento(i)->getData()->getResistencia()
                 << " no tiene pareja";
        }
    }

    while (to_reproduce.getSize() > 0) { // Se mantiene siempre que hayan elementos en la lista

        // Elijo dos padres (esta asegurado que sera random porque la lista se aleatoriza cada vez que corre la funcion)
        Node<Gladiator *> *p1 = to_reproduce.pop_front();
        Node<Gladiator *> *p2 = to_reproduce.pop_front();

        if (p1 &&
            p2) {  // Revisa que ambos existan, si no existe uno o ambos, no reproduce, esto porque algunas veces puede que no hayan parejas
            Gladiator *padre1 = to_reproduce.pop_front()->getData();
            Gladiator *padre2 = to_reproduce.pop_front()->getData();

            Gladiator *nuevo1 = new Gladiator(); // Creo un nuevo gladiador en blanco
            Gladiator *nuevo2 = new Gladiator();
            //cout << "      El bebe gladiador es: " << nuevo1->getIdUnico() << endl;
            // Genero dos numeros random que van a ser los atributos que el primer padre va a pasar al hijo 1
            int veces = 0;
            int attr_pasar1[] = {-1, -1, -1, -1}; // Inicializo en -1 para indicar que no se han asignado
            int attr_pasar2[] = {-1, -1, -1, -1}; // Inicializo en -1 para indicar que no se han asignado
            int pasado = -1; // Aqui guardo el atributo que ya asigno para que no asigne el mismo de nuevo
            while (veces != 2) {  // Termina cuando se ejecuta dos veces

                int attr = rand() % 4; // Numero random del 0 al 4
                while (pasado == attr) {  // Se fija que no sea el mismo numero que el pasado, si lo es, cambia
                    attr = rand() % 4;  // Recalculo
                }

                //Asigno los dos atributos que no fueron asignados antes
                for (int i = 0; i < 4; i++) {
                    if (attr_pasar1[i] == -1) {  // Si el atributo i es -1 (no fue asignado)
                        attr_pasar1[i] = padre2->getAttr(i);  // Le asigna el atributo i del padre2
                        attr_pasar2[i] = padre1->getAttr(i);
                    }
                }

                // Setteo los atributos al bebe
                nuevo1->setAtributesI(attr_pasar1); // Setteo los atributos iniciales
                nuevo2->setAtributesI(attr_pasar2);
                nuevo1->setPadre1(padre1);
                nuevo1->setPadre2(padre2);
                nuevo2->setPadre1(padre1);
                nuevo2->setPadre2(padre2);


                // FIN CROSSOVER

                // MUTACION 1

                int mutacion = rand() % 100 + 1; // tira los dados del destino
                int inversion = rand() % 100 + 1;
                if (mutacion <= 20) { // 10% de probabilidades de mutar
                    cout << "       El bebe tuvo suerte, sucedera mutacion\n";
                    mutar(nuevo1);  // Muto
                    cout << "      Fin de mutacion\n";
                }
                if (inversion <= 10) {  // 5% de probabilidades de inversion
                    cout << "      El bebe tuvo suerte, sucedera inversion\n";
                    invertir(nuevo1); // Invierto
                    cout << "      Fin de inversion\n";
                }
/*            cout << "        Atributos finales del bebe:" << " IQ:" << nuevo->getIQemocional() << " FS:"
                 << nuevo1->getFuerzaTSuperior() <<
                 " FI:" << nuevo1->getFuerzaTInferior() << " CF:" << nuevo->getCondicionFisica() << endl;*/

                nuevos.push_front(nuevo1);  // Agrega a la lista de la nueva generacion

                // MUTACION 2

                mutacion = rand() % 100 + 1; // tira los dados del destino
                inversion = rand() % 100 + 1;
                if (mutacion <= 20) { // 10% de probabilidades de mutar
                    cout << "       El bebe tuvo suerte, sucedera mutacion\n";
                    mutar(nuevo2);  // Muto
                    cout << "      Fin de mutacion\n";
                }

            }  // Repite

            generaciones.push_front(new Generacion(nuevos,
                                                   generacion_c));  // Crea la nueva generacion y la agrega a la lista de generaciones
            cout << "Nacio una bella nueva generacion de: " << generaciones.front()->getGladiadores().getSize()
                 << " bebes!\n";
            generacion_c++;

            generaciones.push_back(new Generacion(nuevos,
                                                  generacion_c));  // Crea la nueva generacion y la agrega a la lista de generaciones
            cout << "Nacio una bella nueva generacion de: " << generaciones.front()->getGladiadores().getSize()
                 << " bebes!\n";
            generacion_c++;

        }
    }
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

Gladiator *Poblacion::bestG(LinkedList<Gladiator*>* lista) {
    Gladiator* best = nullptr;  // Puntero que apunta al mejor gladiador
    int best_pos = -1;
        for(int gladiador_c=0;gladiador_c<lista->getSize();gladiador_c++){ // Iterador de gladiadores
            // Logica de seleccion starts
            Gladiator* gladiador = lista->getElemento(gladiador_c)->getData(); // Gladiador en el que voy a trabajar
            if(best == nullptr){  // Si no hay un best aun
                //cout<<"    Debido a que no existe un campeon, gladiador "<<gladiador->getIdUnico()<<" tomara la vacante, con una probabilidad de supervivencia de:"
              //  <<gladiador->getProbabilidadSupervivencia()<<endl;
                best = gladiador;
                best_pos = gladiador_c;
            }else{
                if(gladiador->getProbabilidadSupervivencia()>best->getProbabilidadSupervivencia()){  // Si la probabilidad de superviviencia del actual es mejor que la del mejor, reemplace
                  //  cout<<"    Gladiador "<<gladiador->getIdUnico()<<" con su probabilidad de supervivencia de: "<<gladiador->getProbabilidadSupervivencia()<<
                   // " ha mejorado al previo campeon, gladiador "<<best->getIdUnico()<< "de probabilidad de supervivencia de:"<<best->getProbabilidadSupervivencia()
                    //<<" tenemos nuevo campeon.\n";
                    best = gladiador;
                    best_pos = gladiador_c;
                }// Si no pues no hace nada
            }
        }
        return lista->pop_element(best_pos)->getData();
}

const LinkedList<Generacion *> &Poblacion::getGeneraciones() const {
    return generaciones;
}

