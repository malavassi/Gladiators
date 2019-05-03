//
// Created by fabian152195 on 29/04/19.
//

#include "GeneradorOleadas.h"

GeneradorOleadas::GeneradorOleadas() {

    this->poolGladiadores = nullptr;
    this->fuerzaTSuperiorRandom=0;
    this->fuerzaTInferiorRandom=0;
    this->iQemocionalRandom=0;
    this->condicionFisicaRandom=0;
    this->contadorGladiador=1;
    this->limiteGladiadorPorOleada=5;

}

LinkedList<Gladiator> GeneradorOleadas::generarOleadaInicial() {

    LinkedList<Gladiator> *OleadaTemporal = new LinkedList<Gladiator>();

    //pruebas
    LinkedList<Gladiator> *OleadaTemporal2 = new LinkedList<Gladiator>();
    LinkedList<Gladiator> *OleadaTemporal3 = new LinkedList<Gladiator>();


    srand(time(NULL));
    cout <<"Numero inicial aleatorio prueba: " << (rand() %10) + 1 << endl;

    int contadorOleada =0;

    while(contadorOleada<limiteGladiadorPorOleada){

        this->condicionFisicaRandom = (rand() %20) + 1;
        this->fuerzaTInferiorRandom = (rand() %20) + 1;
        this->fuerzaTSuperiorRandom = (rand() %20) + 1;

        //CREA GLADIADOR Y AGREGA A LISTA
        OleadaTemporal->push_front(new Gladiator());

        //MODIFICA ATRIBUTOS 'FIJOS'
        OleadaTemporal->front()->setEdad(25);
        OleadaTemporal->front()->setGeneracionesEsperadas(4);

        //MODIFICA ARIBUTOS VARIABLES O RANDOM
        OleadaTemporal->front()->setIdUnico(this->contadorGladiador);
        OleadaTemporal->front()->setCondicionFisica(condicionFisicaRandom);
        OleadaTemporal->front()->setFuerzaTInferior(fuerzaTInferiorRandom);
        OleadaTemporal->front()->setFuerzaTSuperior(fuerzaTSuperiorRandom);

        //FUNCION FITNESS
        OleadaTemporal->front()->setIQemocional(0); // falta
        OleadaTemporal->front()->setResistencia(0); // falta

        //CALCULA PROBABILIDAD DE SUPERVIVENCIA
        OleadaTemporal->front()->setProbabilidadSupervivencia(0); //falta

        contadorGladiador+=1;
        contadorOleada+=1;
    }

    contadorOleada =0;

    while(contadorOleada<limiteGladiadorPorOleada){

        this->condicionFisicaRandom = (rand() %20) + 1;
        this->fuerzaTInferiorRandom = (rand() %20) + 1;
        this->fuerzaTSuperiorRandom = (rand() %20) + 1;

        //CREA GLADIADOR Y AGREGA A LISTA
        OleadaTemporal2->push_front(new Gladiator());

        //MODIFICA ATRIBUTOS 'FIJOS'
        OleadaTemporal2->front()->setEdad(25);
        OleadaTemporal2->front()->setGeneracionesEsperadas(4);

        //MODIFICA ARIBUTOS VARIABLES O RANDOM
        OleadaTemporal2->front()->setIdUnico(this->contadorGladiador);
        OleadaTemporal2->front()->setCondicionFisica(condicionFisicaRandom);
        OleadaTemporal2->front()->setFuerzaTInferior(fuerzaTInferiorRandom);
        OleadaTemporal2->front()->setFuerzaTSuperior(fuerzaTSuperiorRandom);

        //FUNCION FITNESS
        OleadaTemporal2->front()->setIQemocional(0); // falta
        OleadaTemporal2->front()->setResistencia(0); // falta

        //CALCULA PROBABILIDAD DE SUPERVIVENCIA
        OleadaTemporal2->front()->setProbabilidadSupervivencia(0); //falta

        contadorGladiador+=1;
        contadorOleada+=1;
    }

    contadorOleada = 0;

    while(contadorOleada<limiteGladiadorPorOleada){

        this->condicionFisicaRandom = (rand() %20) + 1;
        this->fuerzaTInferiorRandom = (rand() %20) + 1;
        this->fuerzaTSuperiorRandom = (rand() %20) + 1;

        //CREA GLADIADOR Y AGREGA A LISTA
        OleadaTemporal3->push_front(new Gladiator());

        //MODIFICA ATRIBUTOS 'FIJOS'
        OleadaTemporal3->front()->setEdad(25);
        OleadaTemporal3->front()->setGeneracionesEsperadas(4);

        //MODIFICA ARIBUTOS VARIABLES O RANDOM
        OleadaTemporal3->front()->setIdUnico(this->contadorGladiador);
        OleadaTemporal3->front()->setCondicionFisica(condicionFisicaRandom);
        OleadaTemporal3->front()->setFuerzaTInferior(fuerzaTInferiorRandom);
        OleadaTemporal3->front()->setFuerzaTSuperior(fuerzaTSuperiorRandom);

        //FUNCION FITNESS
        OleadaTemporal3->front()->setIQemocional(0); // falta
        OleadaTemporal3->front()->setResistencia(0); // falta

        //CALCULA PROBABILIDAD DE SUPERVIVENCIA
        OleadaTemporal3->front()->setProbabilidadSupervivencia(0); //falta
        contadorGladiador+=1;
        contadorOleada+=1;
    }


    poolGladiadores->getPoolGladiadores()->push_front(OleadaTemporal);

    poolGladiadores->getPoolGladiadores()->push_back(OleadaTemporal3);

    poolGladiadores->recorrerPool();
    free(OleadaTemporal);



    //

}

int GeneradorOleadas::getContadorGladiador() const {
    return contadorGladiador;
}

void GeneradorOleadas::setContadorGladiador(int contadorGladiador) {
    GeneradorOleadas::contadorGladiador = contadorGladiador;
}

int GeneradorOleadas::getIQemocionalRandom() const {
    return iQemocionalRandom;
}

void GeneradorOleadas::setIQemocionalRandom(int iQemocionalRandom) {
    GeneradorOleadas::iQemocionalRandom = iQemocionalRandom;
}

int GeneradorOleadas::getCondicionFisicaRandom() const {
    return condicionFisicaRandom;
}

void GeneradorOleadas::setCondicionFisicaRandom(int condicionFisicaRandom) {
    GeneradorOleadas::condicionFisicaRandom = condicionFisicaRandom;
}

int GeneradorOleadas::getFuerzaTSuperiorRandom() const {
    return fuerzaTSuperiorRandom;
}

void GeneradorOleadas::setFuerzaTSuperiorRandom(int fuerzaTSuperiorRandom) {
    GeneradorOleadas::fuerzaTSuperiorRandom = fuerzaTSuperiorRandom;
}

int GeneradorOleadas::getFuerzaTInferiorRandom() const {
    return fuerzaTInferiorRandom;
}

void GeneradorOleadas::setFuerzaTInferiorRandom(int fuerzaTInferiorRandom) {
    GeneradorOleadas::fuerzaTInferiorRandom = fuerzaTInferiorRandom;
}

PoolGladiadores *GeneradorOleadas::getPoolGladiadores() const {
    return poolGladiadores;
}

void GeneradorOleadas::setPoolGladiadores(PoolGladiadores *poolGladiadores) {
    GeneradorOleadas::poolGladiadores = poolGladiadores;
}

int GeneradorOleadas::getLimiteGladiadorPorOleada() const {
    return limiteGladiadorPorOleada;
}

void GeneradorOleadas::setLimiteGladiadorPorOleada(int limiteGladiadorPorOleada) {
    GeneradorOleadas::limiteGladiadorPorOleada = limiteGladiadorPorOleada;
}