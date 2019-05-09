//
// Created by fabian152195 on 06/05/19.
//

#include "ZonaIntimidacion.h"
#include <iostream>

using namespace std;

ZonaIntimidacion::ZonaIntimidacion() {

    goal_x = 0;
    goal_y = 0;
    size = 10;
    map_matrix;

}

void ZonaIntimidacion::createMap() {
    LinkedList<LinkedList<int>>* matrix = new LinkedList<LinkedList<int>>();
    for(int i=0; i<size; i++){
        LinkedList<int>* column = new LinkedList<int>();
        for(int j=0; j<size; j++){
            column->push_front(0);
        }
        matrix->push_front(*column);
    }
    map_matrix=*matrix;
    delete matrix;
}

void ZonaIntimidacion::addTower(int type, int pos_x, int pos_y) {
    map_matrix.getElemento(pos_x)->getData().getElemento(pos_y)->setData(type);
}

bool ZonaIntimidacion::isValid(int pos_x, int pos_y) {
    if((0<=pos_x && pos_x<size) && (0<=pos_y && pos_y<size)){
        return true;
    }
    else{
        return false;
    }
}

bool ZonaIntimidacion::isUnblocked(int pos_x, int pos_y) {
    if(map_matrix.getElemento(pos_x)->getData().getElemento(pos_y)->getData()==0){
        return true;
    }
    else{
        return false;
    }
}

bool ZonaIntimidacion::isGoal(int pos_x, int pos_y) {
    if(pos_x==goal_x && pos_y==goal_y){
        return true;
    }
    else{
        return false;
    }
}

double ZonaIntimidacion::calcH(int pos_x, int pos_y) {
    return (sqrt(pow(pos_x-goal_x, 2)+pow(pos_y-goal_y, 2)));
}

int ZonaIntimidacion::emptySpaces() {

    int emptySpaces = 0;
    for(int i = 0; i < size; i++){ //por filas

        for(int j=0 ; j<size; j++){ //por columnas de cada fila

            if(isUnblocked(i,j)){
                emptySpaces+=1;
            }
        }
    }

    return emptySpaces;

}