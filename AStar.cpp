//
// Created by cvaz on 28/04/19.
//

#include "AStar.h"

void AStar::createMap() {
    LinkedList<LinkedList<int>>* matrix = new LinkedList<LinkedList<int>>();
    for(int i=0; i<size; i++){
        LinkedList<int>* column = new LinkedList<int>();
        for(int j=0; j<size; j++){
            column->push_back(0);
        }
        matrix->push_back(*column);
    }
    map_matrix=*matrix;
    delete matrix;
}

void AStar::addTower(int type, int pos_x, int pos_y) {
    map_matrix.getElemento(pos_x)->getData().getElemento(pos_y)->setData(type);
}

bool AStar::isValid(int pos_x, int pos_y) {
    if(0<=pos_x<size && 0<=pos_y<size){
        return true;
    }
    else{
        return false;
    }
}

bool AStar::isUnblocked(int pos_x, int pos_y) {
    if(map_matrix.getElemento(pos_x)->getData().getElemento(pos_y)->getData()==0){
        return true;
    }
    else{
        return false;
    }
}

bool AStar::isGoal(int pos_x, int pos_y) {
    if(pos_x==goal_x && pos_y==goal_y){
        return true;
    }
    else{
        return false;
    }
}

double AStar::calcH(int pos_x, int pos_y) {
    return (sqrt(pow(2, pos_x-goal_x)+pow(2, pos_y-goal_y)));
}

void AStar::aStarSearch(int ref_x, int ref_y) {
    bool reachedDest = false;
    //Crea una matriz de struct para la búsqueda del camino
    LinkedList<LinkedList<quadrant>> search_matrix;
    for(int i = 0; i<size; i++){
        LinkedList<quadrant> tmp;
        for(int j = 0; j<size; j++){
            quadrant qdrt;
            qdrt.f=0;
            qdrt.g=0;
            qdrt.h=0;
            qdrt.parent_x=-1;
            qdrt.parent_y=-1;
            tmp.push_back(qdrt);
        }
        search_matrix.push_back(tmp);
    }
    LinkedList<quadrant> closedList;
    LinkedList<quadrant> openList;
    //Inicializa los parametros del pto de partida
    quadrant tmp = search_matrix.getElemento(ref_x)->getData().getElemento(ref_y)->getData();
    tmp.h=0;
    tmp.g=0;
    tmp.f=0;
    tmp.parent_x=ref_x;
    tmp.parent_y=ref_y;

    //Anade el pto partida a la lista abierta
    openList.push_back(search_matrix.getElemento(ref_x)->getData().getElemento(ref_y)->getData());
    while(openList.getSize()>0){
        quadrant qdrt = openList.front();
        openList.pop_front();
        //Recorre sucesores en orden N, NE, E, SE, S, SO, O, NO
        //Sucesor Norte
        if(isValid(ref_x, ref_y-1)){
            //Si la salida es el sucesor actual
            if(isGoal(ref_x, ref_y-1)){
                //Asigna posx y posy del padre
                quadrant current = search_matrix.getElemento(ref_x)->getData().getElemento(ref_y)->getData();
                current.parent_x=ref_x;
                current.parent_y=ref_y;
            }
        }
    }
}

const LinkedList<LinkedList<int>> &AStar::getMapMatrix() const {
    return map_matrix;
}

