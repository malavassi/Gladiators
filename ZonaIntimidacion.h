//
// Created by fabian152195 on 06/05/19.
//

#ifndef GLADIATORS_ZONAINTIMIDACION_H
#define GLADIATORS_ZONAINTIMIDACION_H

#include "LinkedList.h"
#include <string>
#include <cmath>
class ZonaIntimidacion {

public:
    void createMap();       //Crea el mapa de referencia (0=vacio, 1=torre normal, 2=torre fuego, 3=torre explosiva y 4=jugador)

    bool isValid(int pos_x, int pos_y);     //Determina si cierta posición en la matriz mapa es válida y está desocupada

    void addTower(int type, int pos_x, int pos_y);      //Añade un valor de torre a una posición específica de la matriz mapa (1=normal, 2=fuego, 3=explosivos)

    bool isUnblocked(int pos_x, int pos_y);     //Determina si hay un espacio libre en determinado cuadrante

    bool isGoal(int pos_x, int pos_y);      //Determina si llegó al objetivo

    double calcH(int pos_x, int pos_y); //Calcula el Heuristics

    int emptySpaces();

    ZonaIntimidacion();

private:
    int goal_x;
    int goal_y;
    int size;
    LinkedList<LinkedList<int>> map_matrix;

};


#endif //GLADIATORS_ZONAINTIMIDACION_H
