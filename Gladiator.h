//
// Created by fabian152195 on 29/04/19.
//

#ifndef GLADIATORS_GLADIATOR_H
#define GLADIATORS_GLADIATOR_H


class Gladiator {

private:
    int idUnico;
    int edad;
    double probabilidadSupervivencia;
    int generacionesEsperadas;
    int iQemocional;
    int condicionFisica;
    int fuerzaTSuperior;
    int fuerzaTInferior;
    int resistencia;

public:

    //CONSTRUCTOR

    Gladiator();

    //GETTERS

    int getIdUnico() const;

    int getEdad() const;

    double getProbabilidadSupervivencia() const;

    int getGeneracionesEsperadas() const;

    int getIQemocional() const;

    int getCondicionFisica() const;

    int getFuerzaTSuperior() const;

    int getFuerzaTInferior() const;

    int getResistencia() const;

    //SETTERS

    void setIdUnico(int idUnico);

    void setEdad(int edad);

    void setProbabilidadSupervivencia(double probabilidadSupervivencia);

    void setGeneracionesEsperadas(int generacionesEsperadas);

    void setIQemocional(int iQemocional);

    void setCondicionFisica(int condicionFisica);

    void setFuerzaTSuperior(int fuerzaTSuperior);

    void setFuerzaTInferior(int fuerzaTInferior);

    void setResistencia(int resistencia);
};


#endif //GLADIATORS_GLADIATOR_H
