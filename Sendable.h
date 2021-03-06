//
// Created by cvaz on 08/05/19.
//

#ifndef GLADIATORS_SENDABLE_H
#define GLADIATORS_SENDABLE_H

#include <string>
#include "Gladiator.h"
#include <iostream>
#include <cstring>
#include "LinkedList.h"

using namespace std;

/**
 * Clase paquete que se va a enviar entre el servidor y el cliente.
 * @author elorim
 * */
class Sendable {
public:
    Sendable();
    /**
     * Transforma el objeto actual a un string tipo json
     * @returns String tipo json
     * @author elorim
     * */
    string toJson();
    /**
     * Transforma el string pasado a un objeto de tipo sendable
     * @param json String en formato json a convertir
     * @returns Objeto sendable basado en el JSON.
     * @author elorim
     * */
    static Sendable toObj(const char json[]);

    /**
     * Limpia los datos que contiene la clase
     * @author elorim
     * */
     void clear();

    // Getters & Setters
    LinkedList<LinkedList<int>> getMovimientos(){return movimientos;}
    string getMensaje(){return mensaje;}
        void setMovimientos(LinkedList<LinkedList<int>> lista){movimientos=lista;}
    void setMensaje(string msj){mensaje=msj;}
    void setGlad1(int glad1[10]);
    void setGlad2(int glad2[10]);

private:

    LinkedList<LinkedList<int>> movimientos; /** La lista de movimientos a enviar con formato, 0000 : (xf)(yf)(xi)(yi)*/
    string mensaje;  /**Un mensaje*/
    int glad1[10]; /** Array de integers del gladiador 1, A**/  //1-id, 2-edad, 3-probabilidadSupervivencia, 4-generacionesEsperadas, 5-iQemocional, 6-condicionFisica, 7-fuerzaTSuperior, 8-fuerzaTInferior, 9-resistencia, 10-algoritmoBusqueda
    int glad2[10]; /**Array de integers del gladiador 2, Backtracking*/
};


#endif //GLADIATORS_SENDABLE_H
