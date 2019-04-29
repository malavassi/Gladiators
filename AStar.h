//
// Created by cvaz on 28/04/19.
//

#ifndef GLADIATORS_ASTAR_H
#define GLADIATORS_ASTAR_H
using namespace std;

class AStar {
    struct quadrant{
        int parent_x, parent_y;
        double f, g, h;
    };
public:
    bool isValid(int pos_x, int pos_y);     //Determina si cierta posición en la matriz mapa es válida y está desocupada
    void addTower(int type, int pos_x, int pos_y);      //Añade un valor de torre a una posición específica de la matriz mapa
    //isUnblocked
    bool isGoal(int pos_x, int pos_y);      //Determina si llegó al objetivo
    double calcH(int pos_x, int pos_y);     //Calcula el Heuristics
    void aStarSearch(int ref_x, int ref_y);
private:
    int goal_x;
    int goal_y;
};


#endif //GLADIATORS_ASTAR_H
