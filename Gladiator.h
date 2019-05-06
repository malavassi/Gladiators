//
// Created by fabian152195 on 29/04/19.
//

#ifndef GLADIATORS_GLADIATOR_H
#define GLADIATORS_GLADIATOR_H

/**
 * Clase encargada de representar al gladiador
 * @author fabian
 * */
class Gladiator {

private:
    static int cont; /**Estatica para llevar el control de los ids*/
    int id;  /**Identificador del gladiador*/
    int edad;  /**Edad del gladiador, afecta los demas atributos*/
    double probabilidadSupervivencia; /**Probabilidades de este gladiador de sobrevivir*/
    int generacionesEsperadas; /**Generaciones en las que se espera que se gane la zona de intimidacion*/
    int iQemocional; /**Atributo que suma a resistencia*/
    int condicionFisica; /**Atributo que suma a resistencia*/
    int fuerzaTSuperior;/**Atributo que suma a resistencia*/
    int fuerzaTInferior;/**Atributo que suma a resistencia*/
    int resistencia; /**Resistencia del gladiador, disminuye al ser golpeado por flechas*/
    int arr_atributos_i[4]; /**Array de atributos inicial, dado al nacer, heredado de los padres sobre el que trabajaran los metodos de mutacion*/
    int arr_atributos_f[4]; /**Array de atributos final, una vez aplicadas las mutaciones, lo afecta la edad*/
    int arr_atributos_mod_mutacion[4]; /**Array de atributos despues de pasar por mutacion*/
    int arr_atributos_mod_inversion[4]; /**Array de atributos despues de invertir*/
    Gladiator* padre1;
    Gladiator* padre2;

public:
    /**
     * Fool constructor
     * @author fabian
     * */
    Gladiator();

    /**
     * Constructor con los cuatro atributos iniciales. Solo usar en la primera generacion
     * @param iq Inteligencia emocional
     * @param cf Condicion fisica
     * @param fs Fuerza en el tronco superior
     * @param fi Fuerza en el tronco inferior
     * @author elorim
     * */
     Gladiator(int iq,int cf, int fs, int fi);


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
    /**
     * Retorna el atributo numero attr del padre.
     * @param attr Atributo a retornar (0:iq, 1:FS, 2:FI, 3:Cf)
     * @returns Atributo numero attr
     * */
    int getAttr(int attr);

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

    void setAtributes(int iq, int cf, int fs, int fi, bool firstborn);

    void setAtributesI(int arrAttr[4]);
};


#endif //GLADIATORS_GLADIATOR_H
