//
// Created by fabian152195 on 29/04/19.
//

#include "Gladiator.h"

int Gladiator::getIdUnico() const {
    return idUnico;
}

void Gladiator::setIdUnico(int idUnico) {
    Gladiator::idUnico = idUnico;
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
    this->idUnico = 0;
    this->iQemocional=0;
    this->probabilidadSupervivencia=0;
    this->resistencia=0;
    this->generacionesEsperadas = 0;
}
