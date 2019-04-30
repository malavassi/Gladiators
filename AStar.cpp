//
// Created by cvaz on 28/04/19.
//

#include <iostream>
#include "AStar.h"
using namespace std;

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
    if((0<=pos_x && pos_x<size) && (0<=pos_y && pos_y<size)){
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
    return (sqrt(pow(pos_x-goal_x, 2)+pow(pos_y-goal_y, 2)));
}

LinkedList<Quadrant> AStar::generatePath(LinkedList<LinkedList<Quadrant>> search_matrix, int goalx, int goaly) {
    LinkedList<Quadrant> path;
    int col = goalx;
    int line = goaly;
    cout<<"The path is"<<endl;
    while(!(search_matrix.getElemento(col)->getData().getElemento(line)->getData().getParentX() == goalx
    && search_matrix.getElemento(col)->getData().getElemento(line)->getData().getParentX() == goaly)){
        Quadrant current = search_matrix.getElemento(col)->getData().getElemento(line)->getData();
        path.push_front(current);
        current.setPosX(col);
        current.setPosY(line);
        int tmp_col = search_matrix.getElemento(col)->getData().getElemento(line)->getData().getParentX();
        int tmp_line = search_matrix.getElemento(col)->getData().getElemento(line)->getData().getParentY();
        col = tmp_col;
        line = tmp_line;
    }
    Quadrant last = search_matrix.getElemento(col)->getData().getElemento(line)->getData();
    path.push_front(last);

    LinkedList<Quadrant> tmp_path = path;
    while(tmp_path.getSize()>0){
        cout<<string(tmp_path.getHead()->getData().getPosX(), tmp_path.getHead()->getData().getPosY())<<endl;
        tmp_path.pop_front();
    }
    return path;
}

void AStar::aStarSearch(int ref_x, int ref_y) {
    bool reachedDest = false;
    //Crea una matriz de Quadrant para la búsqueda del camino
    LinkedList<LinkedList<Quadrant>> search_matrix;
    for(int i = 0; i<size; i++){
        LinkedList<Quadrant> tmp;
        for(int j = 0; j<size; j++){
            Quadrant qdrt;
            qdrt.setF(-1);
            qdrt.setG(0);
            qdrt.setH(0);
            qdrt.setParentX(-1);
            qdrt.setParentY(-1);
            tmp.push_back(qdrt);
        }
        search_matrix.push_back(tmp);
    }
    //Crea matriz de booleans para la lista cerrada
    LinkedList<LinkedList<bool>> closedList;
    for(int i=0; i<size; i++){
        LinkedList<bool> tmp_list;
        for(int j=0; j<size; j++){
            tmp_list.push_back(false);
        }
        closedList.push_back(tmp_list);
    }

    //Crea lista abierta
    LinkedList<TuplaCuadrante> openList;

    //Inicializa los parametros del pto de partida en search_matrix
    Quadrant tmp = search_matrix.getElemento(ref_x)->getData().getElemento(ref_y)->getData();
    tmp.setH(0);
    tmp.setG(0);
    tmp.setF(0);
    tmp.setParentX(ref_x);
    tmp.setParentY(ref_y);

    //Crea una tuplaCuadrante para el punto de partida
    TuplaCuadrante start;
    start.setPosX(ref_x);
    start.setPosY(ref_y);

    //Anade punto de partida a la lista abiera
    openList.push_back(start);

    //Declara valores nuevos de g, h y f
    double newg, newh, newf;
    //Comienza la busqueda mientras hayan caminos posibles
    while(openList.getSize()>0){
        TuplaCuadrante tmp = openList.front();
        openList.pop_front();
        //Establece variables para ambos ejes
        int var_x=tmp.getPosX();
        int var_y=tmp.getPosY();
        //Anade esta casilla a closedList
        closedList.getElemento(var_x)->getData().getElemento(var_y)->setData(true);

        //Recorre sucesores en orden N, NE, E, SE, S, SO, O, NO
        //Sucesor Norte
        if(isValid(var_x, var_y-1) && isUnblocked(var_x, var_y-1)){
            //Si la salida es el sucesor actual
            if(isGoal(var_x, var_y-1)){
                //Asigna posx y posy del padre
                Quadrant current = search_matrix.getElemento(var_x)->getData().getElemento(var_y-1)->getData();
                current.setParentX(var_x);
                current.setParentY(var_y);
                reachedDest=true;
                //Genera el camino final
                generatePath(search_matrix, goal_x, goal_y);
                return;
            } //Si no esta en la lista cerrada y es valido
            else if(closedList.getElemento(var_x)->getData().getElemento(var_y-1)->getData()==false && isValid(var_x, var_y-1)==true){
                //Calcula los valores del algoritmo
                newg=search_matrix.getElemento(var_x)->getData().getElemento(var_y)->getData().getG()+10;
                newh=calcH(var_x, var_y-1);
                newf=newg+newh;
                //Si no esta en lista abierta o su valor f es mayor que el del nuevo camino
                if(search_matrix.getElemento(var_x)->getData().getElemento(var_y-1)->getData().getF()==-1 || search_matrix.getElemento(var_x)->getData().getElemento(var_y-1)->getData().getF()>newf){
                    //Anade tupla actual a openList
                    TuplaCuadrante newtpl;
                    newtpl.setFValue(newf);
                    newtpl.setPosX(var_x);
                    newtpl.setPosY(var_y-1);
                    openList.push_back(newtpl);
                    //Actualiza valores quadrant
                    Quadrant update = search_matrix.getElemento(var_x)->getData().getElemento(var_y-1)->getData();
                    update.setF(newf);
                    update.setG(newg);
                    update.setH(newh);
                    update.setParentX(var_x);
                    update.setParentY(var_y);
                }
            }
        }
        //Sucesor Noreste
        if(isValid(var_x+1, var_y-1) && isUnblocked(var_x+1, var_y-1)){
            //Si la salida es el sucesor actual
            if(isGoal(var_x+1, var_y-1)){
                //Asigna posx y posy del padre
                Quadrant current = search_matrix.getElemento(var_x+1)->getData().getElemento(var_y-1)->getData();
                current.setParentX(var_x);
                current.setParentY(var_y);
                reachedDest=true;
                //Genera el camino final
                generatePath(search_matrix, goal_x, goal_y);
                return;
            } //Si no esta en la lista cerrada y es valido
            else if(closedList.getElemento(var_x+1)->getData().getElemento(var_y-1)->getData()==false && isValid(var_x+1, var_y-1)==true){
                //Calcula los valores del algoritmo
                newg=search_matrix.getElemento(var_x)->getData().getElemento(var_y)->getData().getG()+14;
                newh=calcH(var_x+1, var_y-1);
                newf=newg+newh;
                //Si no esta en lista abierta o su valor f es mayor que el del nuevo camino
                if(search_matrix.getElemento(var_x+1)->getData().getElemento(var_y-1)->getData().getF()==-1 || search_matrix.getElemento(var_x+1)->getData().getElemento(var_y-1)->getData().getF()>newf){
                    //Anade tupla actual a openList
                    TuplaCuadrante newtpl;
                    newtpl.setFValue(newf);
                    newtpl.setPosX(var_x+1);
                    newtpl.setPosY(var_y-1);
                    openList.push_back(newtpl);
                    //Actualiza valores quadrant
                    Quadrant update = search_matrix.getElemento(var_x+1)->getData().getElemento(var_y-1)->getData();
                    update.setF(newf);
                    update.setG(newg);
                    update.setH(newh);
                    update.setParentX(var_x);
                    update.setParentY(var_y);
                }
            }
        }
        //Sucesor Este
        if(isValid(var_x+1, var_y) && isUnblocked(var_x+1, var_y)){
            //Si la salida es el sucesor actual
            if(isGoal(var_x+1, var_y)){
                //Asigna posx y posy del padre
                Quadrant current = search_matrix.getElemento(var_x+1)->getData().getElemento(var_y)->getData();
                current.setParentX(var_x);
                current.setParentY(var_y);
                reachedDest=true;
                //Genera el camino final
                generatePath(search_matrix, goal_x, goal_y);
                return;
            } //Si no esta en la lista cerrada y es valido
            else if(closedList.getElemento(var_x+1)->getData().getElemento(var_y)->getData()==false && isValid(var_x+1, var_y)==true){
                //Calcula los valores del algoritmo
                newg=search_matrix.getElemento(var_x)->getData().getElemento(var_y)->getData().getG()+10;
                newh=calcH(var_x+1, var_y);
                newf=newg+newh;
                //Si no esta en lista abierta o su valor f es mayor que el del nuevo camino
                if(search_matrix.getElemento(var_x+1)->getData().getElemento(var_y)->getData().getF()==-1 || search_matrix.getElemento(var_x+1)->getData().getElemento(var_y)->getData().getF()>newf){
                    //Anade tupla actual a openList
                    TuplaCuadrante newtpl;
                    newtpl.setFValue(newf);
                    newtpl.setPosX(var_x+1);
                    newtpl.setPosY(var_y);
                    openList.push_back(newtpl);
                    //Actualiza valores quadrant
                    Quadrant update = search_matrix.getElemento(var_x+1)->getData().getElemento(var_y)->getData();
                    update.setF(newf);
                    update.setG(newg);
                    update.setH(newh);
                    update.setParentX(var_x);
                    update.setParentY(var_y);
                }
            }
        }
        //Sucesor Sureste
        if(isValid(var_x+1, var_y+1) && isUnblocked(var_x+1, var_y+1)){
            //Si la salida es el sucesor actual
            if(isGoal(var_x+1, var_y+1)){
                //Asigna posx y posy del padre
                Quadrant current = search_matrix.getElemento(var_x+1)->getData().getElemento(var_y+1)->getData();
                current.setParentX(var_x);
                current.setParentY(var_y);
                reachedDest=true;
                //Genera el camino final
                generatePath(search_matrix, goal_x, goal_y);
                return;
            } //Si no esta en la lista cerrada y es valido
            else if(closedList.getElemento(var_x+1)->getData().getElemento(var_y+1)->getData()==false && isValid(var_x+1, var_y+1)==true){
                //Calcula los valores del algoritmo
                newg=search_matrix.getElemento(var_x)->getData().getElemento(var_y)->getData().getG()+14;
                newh=calcH(var_x+1, var_y+1);
                newf=newg+newh;
                //Si no esta en lista abierta o su valor f es mayor que el del nuevo camino
                if(search_matrix.getElemento(var_x+1)->getData().getElemento(var_y+1)->getData().getF()==-1 || search_matrix.getElemento(var_x+1)->getData().getElemento(var_y+1)->getData().getF()>newf){
                    //Anade tupla actual a openList
                    TuplaCuadrante newtpl;
                    newtpl.setFValue(newf);
                    newtpl.setPosX(var_x+1);
                    newtpl.setPosY(var_y+1);
                    openList.push_back(newtpl);
                    //Actualiza valores quadrant
                    Quadrant update = search_matrix.getElemento(var_x+1)->getData().getElemento(var_y+1)->getData();
                    update.setF(newf);
                    update.setG(newg);
                    update.setH(newh);
                    update.setParentX(var_x);
                    update.setParentY(var_y);
                }
            }
        }
        //Sucesor Sur
        if(isValid(var_x, var_y+1) && isUnblocked(var_x, var_y+1)){
            //Si la salida es el sucesor actual
            if(isGoal(var_x, var_y+1)){
                //Asigna posx y posy del padre
                Quadrant current = search_matrix.getElemento(var_x)->getData().getElemento(var_y+1)->getData();
                current.setParentX(var_x);
                current.setParentY(var_y);
                reachedDest=true;
                //Genera el camino final
                generatePath(search_matrix, goal_x, goal_y);
                return;
            } //Si no esta en la lista cerrada y es valido
            else if(closedList.getElemento(var_x)->getData().getElemento(var_y+1)->getData()==false && isValid(var_x, var_y+1)==true){
                //Calcula los valores del algoritmo
                newg=search_matrix.getElemento(var_x)->getData().getElemento(var_y)->getData().getG()+10;
                newh=calcH(var_x, var_y+1);
                newf=newg+newh;
                //Si no esta en lista abierta o su valor f es mayor que el del nuevo camino
                if(search_matrix.getElemento(var_x)->getData().getElemento(var_y+1)->getData().getF()==-1 || search_matrix.getElemento(var_x)->getData().getElemento(var_y+1)->getData().getF()>newf){
                    //Anade tupla actual a openList
                    TuplaCuadrante newtpl;
                    newtpl.setFValue(newf);
                    newtpl.setPosX(var_x);
                    newtpl.setPosY(var_y+1);
                    openList.push_back(newtpl);
                    //Actualiza valores quadrant
                    Quadrant update = search_matrix.getElemento(var_x)->getData().getElemento(var_y+1)->getData();
                    update.setF(newf);
                    update.setG(newg);
                    update.setH(newh);
                    update.setParentX(var_x);
                    update.setParentY(var_y);
                }
            }
        }
        //Sucesor Suroeste
        if(isValid(var_x-1, var_y+1) && isUnblocked(var_x-1, var_y+1)){
            //Si la salida es el sucesor actual
            if(isGoal(var_x-1, var_y+1)){
                //Asigna posx y posy del padre
                Quadrant current = search_matrix.getElemento(var_x-1)->getData().getElemento(var_y+1)->getData();
                current.setParentX(var_x);
                current.setParentY(var_y);
                reachedDest=true;
                //Genera el camino final
                generatePath(search_matrix, goal_x, goal_y);
                return;
            } //Si no esta en la lista cerrada y es valido
            else if(closedList.getElemento(var_x-1)->getData().getElemento(var_y+1)->getData()==false && isValid(var_x-1, var_y+1)==true){
                //Calcula los valores del algoritmo
                newg=search_matrix.getElemento(var_x)->getData().getElemento(var_y)->getData().getG()+14;
                newh=calcH(var_x-1, var_y+1);
                newf=newg+newh;
                //Si no esta en lista abierta o su valor f es mayor que el del nuevo camino
                if(search_matrix.getElemento(var_x-1)->getData().getElemento(var_y+1)->getData().getF()==-1 || search_matrix.getElemento(var_x-1)->getData().getElemento(var_y+1)->getData().getF()>newf){
                    //Anade tupla actual a openList
                    TuplaCuadrante newtpl;
                    newtpl.setFValue(newf);
                    newtpl.setPosX(var_x-1);
                    newtpl.setPosY(var_y+1);
                    openList.push_back(newtpl);
                    //Actualiza valores quadrant
                    Quadrant update = search_matrix.getElemento(var_x-1)->getData().getElemento(var_y+1)->getData();
                    update.setF(newf);
                    update.setG(newg);
                    update.setH(newh);
                    update.setParentX(var_x);
                    update.setParentY(var_y);
                }
            }
        }
        //Sucesor Oeste
        if(isValid(var_x-1, var_y) && isUnblocked(var_x-1, var_y)){
            //Si la salida es el sucesor actual
            if(isGoal(var_x-1, var_y)){
                //Asigna posx y posy del padre
                Quadrant current = search_matrix.getElemento(var_x-1)->getData().getElemento(var_y)->getData();
                current.setParentX(var_x);
                current.setParentY(var_y);
                reachedDest=true;
                //Genera el camino final
                generatePath(search_matrix, goal_x, goal_y);
                return;
            } //Si no esta en la lista cerrada y es valido
            else if(closedList.getElemento(var_x-1)->getData().getElemento(var_y)->getData()==false && isValid(var_x-1, var_y)==true){
                //Calcula los valores del algoritmo
                newg=search_matrix.getElemento(var_x)->getData().getElemento(var_y)->getData().getG()+10;
                newh=calcH(var_x-1, var_y);
                newf=newg+newh;
                //Si no esta en lista abierta o su valor f es mayor que el del nuevo camino
                if(search_matrix.getElemento(var_x-1)->getData().getElemento(var_y)->getData().getF()==-1 || search_matrix.getElemento(var_x-1)->getData().getElemento(var_y)->getData().getF()>newf){
                    //Anade tupla actual a openList
                    TuplaCuadrante newtpl;
                    newtpl.setFValue(newf);
                    newtpl.setPosX(var_x-1);
                    newtpl.setPosY(var_y);
                    openList.push_back(newtpl);
                    //Actualiza valores quadrant
                    Quadrant update = search_matrix.getElemento(var_x-1)->getData().getElemento(var_y)->getData();
                    update.setF(newf);
                    update.setG(newg);
                    update.setH(newh);
                    update.setParentX(var_x);
                    update.setParentY(var_y);
                }
            }
        }
        //Sucesor Noroeste
        if(isValid(var_x-1, var_y-1) && isUnblocked(var_x-1, var_y-1)){
            //Si la salida es el sucesor actual
            if(isGoal(var_x-1, var_y-1)){
                //Asigna posx y posy del padre
                Quadrant current = search_matrix.getElemento(var_x-1)->getData().getElemento(var_y-1)->getData();
                current.setParentX(var_x);
                current.setParentY(var_y);
                reachedDest=true;
                //Genera el camino final
                generatePath(search_matrix, goal_x, goal_y);
                return;
            } //Si no esta en la lista cerrada y es valido
            else if(closedList.getElemento(var_x-1)->getData().getElemento(var_y-1)->getData()==false && isValid(var_x-1, var_y-1)==true){
                //Calcula los valores del algoritmo
                newg=search_matrix.getElemento(var_x)->getData().getElemento(var_y)->getData().getG()+14;
                newh=calcH(var_x-1, var_y-1);
                newf=newg+newh;
                //Si no esta en lista abierta o su valor f es mayor que el del nuevo camino
                if(search_matrix.getElemento(var_x-1)->getData().getElemento(var_y-1)->getData().getF()==-1 || search_matrix.getElemento(var_x-1)->getData().getElemento(var_y-1)->getData().getF()>newf){
                    //Anade tupla actual a openList
                    TuplaCuadrante newtpl;
                    newtpl.setFValue(newf);
                    newtpl.setPosX(var_x-1);
                    newtpl.setPosY(var_y-1);
                    openList.push_back(newtpl);
                    //Actualiza valores quadrant
                    Quadrant update = search_matrix.getElemento(var_x-1)->getData().getElemento(var_y-1)->getData();
                    update.setF(newf);
                    update.setG(newg);
                    update.setH(newh);
                    update.setParentX(var_x);
                    update.setParentY(var_y);
                }
            }
        }
    }
    if(reachedDest==false){
        std::cout<<"No hay caminos posibles"<<endl;
    }
    return;
}

const LinkedList<LinkedList<int>> &AStar::getMapMatrix() const {
    return map_matrix;
}

