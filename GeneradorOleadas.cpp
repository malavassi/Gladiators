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
    this->contadorGeneracion=1;

}

void GeneradorOleadas::generarOleadaInicial() {

    LinkedList<Gladiator> *OleadaTemporalA = new LinkedList<Gladiator>();

    //pruebas
    LinkedList<Gladiator> *OleadaTemporalB = new LinkedList<Gladiator>();



    srand(time(NULL));
    cout <<"Numero inicial aleatorio prueba: " << (rand() %10) + 1 << endl;

    int contadorOleada =0;

    while(contadorOleada<limiteGladiadorPorOleada){

        this->condicionFisicaRandom = (rand() %20) + 1;
        this->fuerzaTInferiorRandom = (rand() %20) + 1;
        this->fuerzaTSuperiorRandom = (rand() %20) + 1;

        //CREA GLADIADOR Y AGREGA A LISTA
        OleadaTemporalA->push_front(new Gladiator());

        //MODIFICA ATRIBUTOS 'FIJOS'
        OleadaTemporalA->front()->setEdad(25);
        OleadaTemporalA->front()->setGeneracionesEsperadas(4);

        //MODIFICA ARIBUTOS VARIABLES O RANDOM
        OleadaTemporalA->front()->setIdUnico(this->contadorGladiador);
        OleadaTemporalA->front()->setCondicionFisica(condicionFisicaRandom);
        OleadaTemporalA->front()->setFuerzaTInferior(fuerzaTInferiorRandom);
        OleadaTemporalA->front()->setFuerzaTSuperior(fuerzaTSuperiorRandom);

        //FUNCION FITNESS
        OleadaTemporalA->front()->setIQemocional(0); // falta
        OleadaTemporalA->front()->setResistencia(0); // falta

        //CALCULA PROBABILIDAD DE SUPERVIVENCIA
        OleadaTemporalA->front()->setProbabilidadSupervivencia(0); //falta

        contadorGladiador+=1;
        contadorOleada+=1;
    }

    contadorOleada =0;

    while(contadorOleada<limiteGladiadorPorOleada){

        this->condicionFisicaRandom = (rand() %20) + 1;
        this->fuerzaTInferiorRandom = (rand() %20) + 1;
        this->fuerzaTSuperiorRandom = (rand() %20) + 1;

        //CREA GLADIADOR Y AGREGA A LISTA
        OleadaTemporalB->push_front(new Gladiator());

        //MODIFICA ATRIBUTOS 'FIJOS'
        OleadaTemporalB->front()->setEdad(25);
        OleadaTemporalB->front()->setGeneracionesEsperadas(4);

        //MODIFICA ARIBUTOS VARIABLES O RANDOM
        OleadaTemporalB->front()->setIdUnico(this->contadorGladiador);
        OleadaTemporalB->front()->setCondicionFisica(condicionFisicaRandom);
        OleadaTemporalB->front()->setFuerzaTInferior(fuerzaTInferiorRandom);
        OleadaTemporalB->front()->setFuerzaTSuperior(fuerzaTSuperiorRandom);

        //FUNCION FITNESS
        OleadaTemporalB->front()->setIQemocional(0); // falta
        OleadaTemporalB->front()->setResistencia(0); // falta

        //CALCULA PROBABILIDAD DE SUPERVIVENCIA
        OleadaTemporalB->front()->setProbabilidadSupervivencia(0); //falta

        contadorGladiador+=1;
        contadorOleada+=1;
    }

    Generacion * generacion = new Generacion(); //crea nueva generacion
    poolGladiadores->getPoolGladiadores()->push_front(generacion); //la anade el pool
    poolGladiadores->getPoolGladiadores()->getElemento(0)->setId(contadorGeneracion);//le asigna el id de la generacion

    contadorGeneracion+=1; //suma uno para la asignacion de la siguiente generacion

    poolGladiadores->getPoolGladiadores()->front()->setPoblacionA(OleadaTemporalA);//anade la oleada generada como poblacionA de la primer generacion
    poolGladiadores->getPoolGladiadores()->front()->setPoblacionB(OleadaTemporalB);//ande la otra oleada generada pero como poblacionB

    poolGladiadores->recorrerPool(); //recorre el Pool
    free(OleadaTemporalA);
    free(OleadaTemporalB);
    free(generacion);

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