//
// Created by fabian152195 on 29/04/19.
//

#include "Gladiator.h"
int Gladiator::cont = 0;
int Gladiator::getIdUnico() const {
    return id;
}

void Gladiator::setIdUnico(int idUnico) {
    idUnico = idUnico;
}

int Gladiator::getEdad() const {
    return edad;
}

void Gladiator::setEdad(int edad) {
    Gladiator::edad = edad;
}

double Gladiator::getProbabilidadSupervivencia() const {
    return probabilidadSupervivencia;
}

void Gladiator::setProbabilidadSupervivencia(double probabilidadSupervivencia) {
    Gladiator::probabilidadSupervivencia = probabilidadSupervivencia;
}

int Gladiator::getGeneracionesEsperadas() const {
    return generacionesEsperadas;
}

void Gladiator::setGeneracionesEsperadas(int generacionesEsperadas) {
    Gladiator::generacionesEsperadas = generacionesEsperadas;
}

int Gladiator::getIQemocional() const {
    return iQemocional;
}

void Gladiator::setIQemocional(int iQemocional) {
    Gladiator::iQemocional = iQemocional;
}

int Gladiator::getCondicionFisica() const {
    return condicionFisica;
}

void Gladiator::setCondicionFisica(int condicionFisica) {
    Gladiator::condicionFisica = condicionFisica;
}

int Gladiator::getFuerzaTSuperior() const {
    return fuerzaTSuperior;
}

void Gladiator::setFuerzaTSuperior(int fuerzaTSuperior) {
    Gladiator::fuerzaTSuperior = fuerzaTSuperior;
}

int Gladiator::getFuerzaTInferior() const {
    return fuerzaTInferior;
}

void Gladiator::setFuerzaTInferior(int fuerzaTInferior) {
    Gladiator::fuerzaTInferior = fuerzaTInferior;
}

int Gladiator::getResistencia() const {
    return resistencia;
}

void Gladiator::setResistencia(int resistencia) {
    Gladiator::resistencia = resistencia;
}

Gladiator::Gladiator() {

    this->condicionFisica = 0;
    this->edad = 0;
    this->fuerzaTInferior = 0;
    this->fuerzaTSuperior = 0;
    this->iQemocional=0;
    this->probabilidadSupervivencia=0;
    this->resistencia=0;
    this->generacionesEsperadas = 4;
    padre1 = nullptr;
    padre2 = nullptr;
    for(int i=0;i<4;i++){
        arr_atributos_mod_mutacion[i] = 0;
        arr_atributos_mod_inversion[i] = 0;
    }

    // ID
    id = Gladiator::cont;
    Gladiator::cont++;
}

Gladiator::Gladiator(int iq, int cf, int fs, int fi) {  // Este constructor solo deberia usarse en la primera generacion
    // ID
    id = Gladiator::cont;
    Gladiator::cont++;
    cout<<"      Creando el gladiador " << id<<endl;
    // Inicializando valores dados
    iQemocional = iq;
    condicionFisica = cf;
    fuerzaTInferior = fi;
    fuerzaTSuperior = fs;
    cout<<"        Con atributos: IQ:"<<iQemocional<<", CF:"<<condicionFisica<<", FTI:"<<fuerzaTInferior<<", FTS:"<<fuerzaTSuperior<<endl;

    // Inicializando en nulos
    generacionesEsperadas = 4;
    probabilidadSupervivencia = 0.f;
    edad = 0;
    resistencia = 0;
    padre1 = nullptr;
    padre2 = nullptr;
    for(int i=0;i<4;i++){
        arr_atributos_mod_mutacion[i] = 0;
        arr_atributos_mod_inversion[i] = 0;
    }

    // Inicializando los arrays de atributos;
    arr_atributos_i[0] = iq;
    arr_atributos_i[1] = fs;
    arr_atributos_i[2] = fi;
    arr_atributos_i[3] = cf;
    arr_atributos_f[0] = iq;
    arr_atributos_f[1] = fs;
    arr_atributos_f[2] = fi;
    arr_atributos_f[3] = cf;

}

void Gladiator::setAtributes(int iq, int cf, int fs, int fi, bool firstborn) {

    // Setting atributes
    iQemocional=iq;
    fuerzaTInferior=fi;
    fuerzaTSuperior=fs;
    condicionFisica=cf;
    if(!firstborn) {  // Si no es recien nacido
        //Setting array de atributos final
        arr_atributos_f[0] = iq;
        arr_atributos_f[1] = fs;
        arr_atributos_f[2] = fi;
        arr_atributos_f[3] = cf;
    }else{  // Si si
        // Setting array de atributos inicial
        arr_atributos_i[0] = iq;
        arr_atributos_i[1] = fs;
        arr_atributos_i[2] = fi;
        arr_atributos_i[3] = cf;
    }

}

int Gladiator::getAttr(int attr) {
    return arr_atributos_f[attr];
}

void Gladiator::setAtributesI(int arrAttr[4]) {
    for(int i = 0;i<4;i++){
        arr_atributos_i[i] = arrAttr[i];
    }
    iQemocional = arrAttr[0];
    fuerzaTSuperior = arrAttr[1];
    fuerzaTInferior = arrAttr[2];
    condicionFisica = arrAttr[3];
    setAtributesF(arrAttr);

}

void Gladiator::setAtributesM(int *arrAttr) {
    for(int i = 0;i<4;i++){
        arr_atributos_mod_mutacion[i] = arrAttr[i];
    }
    iQemocional = arrAttr[0];
    fuerzaTSuperior = arrAttr[1];
    fuerzaTInferior = arrAttr[2];
    condicionFisica = arrAttr[3];
    setAtributesF(arrAttr);
}

void Gladiator::setAtributesF(int *arrAttr) {
    for(int i = 0;i<4;i++){
        arr_atributos_f[i] = arrAttr[i];
    }
    iQemocional = arrAttr[0];
    fuerzaTSuperior = arrAttr[1];
    fuerzaTInferior = arrAttr[2];
    condicionFisica = arrAttr[3];
}

void Gladiator::avanzarEdad() {
    edad+=20;
    generacionesEsperadas--;

}

Gladiator *Gladiator::getPadre1() const {
    return padre1;
}

Gladiator *Gladiator::getPadre2() const {
    return padre2;
}

