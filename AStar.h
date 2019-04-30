//
// Created by cvaz on 28/04/19.
//

#ifndef GLADIATORS_ASTAR_H
#define GLADIATORS_ASTAR_H

#include "LinkedList.h"
#include <cmath>

using namespace std;

class AStar {
    struct quadrant{
        int parent_x, parent_y;
        double f, g, h;
    };
public:
    AStar(int _size, int destiny_x, int destiny_y){
        size=_size;
        goal_x=destiny_x;
        goal_y=destiny_y;
    };
    void createMap();       //Crea el mapa de referencia (0=vacio, 1=torre normal, 2=torre fuego, 3=torre explosiva y 4=jugador)

    bool isValid(int pos_x, int pos_y);     //Determina si cierta posición en la matriz mapa es válida y está desocupada

    void addTower(int type, int pos_x, int pos_y);      //Añade un valor de torre a una posición específica de la matriz mapa (1=normal, 2=fuego, 3=explosivos)

    bool isUnblocked(int pos_x, int pos_y);     //Determina si hay un espacio libre en determinado cuadrante

    bool isGoal(int pos_x, int pos_y);      //Determina si llegó al objetivo

    double calcH(int pos_x, int pos_y);     //Calcula el Heuristics

    void aStarSearch(int ref_x, int ref_y);     //Busca el camina

    const LinkedList<LinkedList<int>> &getMapMatrix() const;

private:
    int goal_x;
    int goal_y;
    int size;
    LinkedList<LinkedList<int>> map_matrix;
};


#endif //GLADIATORS_ASTAR_H
