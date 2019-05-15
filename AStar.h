//
// Created by cvaz on 28/04/19.
//

#ifndef GLADIATORS_ASTAR_H
#define GLADIATORS_ASTAR_H

#include "LinkedList.h"
#include "TuplaCuadrante.h"
#include "Quadrant.h"
#include <string>
#include <cmath>

using namespace std;

class AStar {
public:
    AStar(int _size, int destiny_x, int destiny_y){
        size=_size;
        goal_x=destiny_x;
        goal_y=destiny_y;
    };

    bool isValid(int pos_x, int pos_y);     //Determina si cierta posición en la matriz mapa es válida y está desocupada

    bool isUnblocked(int pos_x, int pos_y);     //Determina si hay un espacio libre en determinado cuadrante

    bool isGoal(int pos_x, int pos_y);      //Determina si llegó al objetivo

    double calcH(int pos_x, int pos_y);     //Calcula el Heuristics

    LinkedList<Quadrant*> generatePath(LinkedList<LinkedList<Quadrant*>>* search_matrix, int goalx, int goaly);

    bool aStarSearch(int ref_x, int ref_y);     //Busca el camino

    LinkedList<LinkedList<int>>* &getMapMatrix();

    void setMapMatrix(LinkedList<LinkedList<int>> *mapMatrix);

    const LinkedList<int> &getGeneratedPath() const;

private:
    int goal_x;
    int goal_y;
    int size;
    LinkedList<LinkedList<int>>* map_matrix;
    LinkedList<int> generated_path;
};


#endif //GLADIATORS_ASTAR_H
