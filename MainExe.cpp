//
// Created by kevin on 05/05/19.
//

#include "MainExe.h"

MainExe::MainExe(int game_size) {  // Ya creo la oleada inicial
    cout<<"Creando oleadas iniciales\n";
    this->poblacionA = new Poblacion('A');
    this->poblacionB = new Poblacion('B');
    cout<<"Oleadas iniciales generadas\n";
    cout<<"Los elegidos son: gladiador "<<poblacionA->getElegido()->getIdUnico()<<" de la poblacion A con "<<
        poblacionA->getElegido()->getProbabilidadSupervivencia()<<"% y gladiador "<<
        poblacionB->getElegido()->getIdUnico()<<" de la poblacion B con "<<poblacionB->getElegido()->getProbabilidadSupervivencia()
        <<"% que Noguera bendiga su sacrificio\n";

    //Arma los algoritmos de busqueda con sus parametros necesarios
    createMap(game_size);
    AStar* aStar = new AStar(game_size, game_size-1, game_size-1);
    aStar->setMapMatrix(map_matrix);
    Backtracking* backtracking = new Backtracking();
    backtracking->setMatrix(map_matrix);
    iteration_ctr=0;
    matrix_size=game_size;
    tower_ctr=0;
}

MainExe::~MainExe() {
}

void MainExe::iniciar() {
    bool terminar = false;
    server = Server();
    server.run();
    while(terminar == false){
        server.sendToClient("inicie");
        server.readFromClient();
        while(server.buffer == "Listo");
        cout<<"\n";
        cout<<"Introduzca un comando:\n 1: Reproducir\n0: Finalizar\n";
        int seleccion;
        cin>>seleccion;

        switch(seleccion){
            case 1:

                siguienteIteracion();
                break;
            case 0:
                terminar = true;
                break;
        }
    }
}

void MainExe::siguienteIteracion() {
    iteration_ctr++;
    cout<<"Los gladiadores han vuelto de sus combates, no comieron ceviche\n";
    poblacionA->reproduccion();
    poblacionB->reproduccion();
    cout<<"Veinte annos han pasado y es hora de hacer tribulaciones a Noguera, quienes seran los elegidos?\n";
    poblacionA->fitness_local();
    poblacionB->fitness_local();
    cout<<"Llego la hora de hacer libaciones a Noguera\n";
    cout<<"  Seleccionando en la poblacion A\n";
    poblacionA->seleccion();
    cout<<"  Seleccionando en la poblacion B\n";
    poblacionB->seleccion();
    cout<<"Los elegidos son: gladiador "<<poblacionA->getElegido()->getIdUnico()<<" de la poblacion A con "<<
    poblacionA->getElegido()->getProbabilidadSupervivencia()<<"% y gladiador "<<
        poblacionB->getElegido()->getIdUnico()<<" de la poblacion B con "<<poblacionB->getElegido()->getProbabilidadSupervivencia()
        <<"% que Noguera bendiga su sacrificio\n";
    if(tower_ctr<(matrix_size*matrix_size-matrix_size)){
        for(int i=0; i<3; i++){
            int type = (int) (rand()%3);
            int pos_x = (int) (rand()%(matrix_size-1));
            int pos_y = (int) (rand()%(matrix_size-1));
            while(map_matrix->getElemento(pos_x)->getData().getElemento(pos_y)->getData()!=0){
                pos_x = (int) (rand()%(matrix_size-1));
                pos_y = (int) (rand()%(matrix_size-1));
            }
            addTower(type, pos_x, pos_y);
            tower_ctr++;
        }
    }
    checkAvailability();
}

void MainExe::createMap(int size) {
    LinkedList<LinkedList<int>>* matrix = new LinkedList<LinkedList<int>>();
    for(int i=0; i<size; i++){
        LinkedList<int>* column = new LinkedList<int>();
        for(int j=0; j<size; j++){
            column->push_back(0);
        }
        matrix->push_back(*column);
    }
    map_matrix=matrix;
}

void MainExe::addTower(int type, int pos_x, int pos_y) {
    map_matrix->getElemento(pos_x)->getData().getElemento(pos_y)->setData(type);
}

void MainExe::rearrangeTowers(){
    Node<LinkedList<int>>* tmp = map_matrix->getHead();
    for(int i=0; i<matrix_size; i++){
        tmp->getData().randomize();
        tmp=tmp->getNext();
    }
    map_matrix->randomize();
}

void MainExe::checkAvailability() {
    while(!aStar->aStarSearch(0, 0)){
        rearrangeTowers();
    }
}

void MainExe::moveTowers() {
    for(int i=0; i<matrix_size; i++){
        for(int j=0; j<matrix_size; j++){
            if(map_matrix->getElemento(i)->getData().getElemento(j)->getData()!=(0 and 4)){
                int dir = (int) (rand()%4);     //direccion en la cual se va a mover 0=Arriba, 1=Abajo, 2=Izquierda, 3=Derecha
                int tower_type = map_matrix->getElemento(i)->getData().getElemento(j)->getData();
                switch(dir){
                    case 0:
                        if(j-1>0 and map_matrix->getElemento(i)->getData().getElemento(j-1)->getData()==0){
                            map_matrix->getElemento(i)->getData().getElemento(j)->setData(0);
                            map_matrix->getElemento(i)->getData().getElemento(j-1)->setData(tower_type);
                        }
                    case 1:
                        if(j+1<matrix_size and map_matrix->getElemento(i)->getData().getElemento(j+1)->getData()==0){
                            map_matrix->getElemento(i)->getData().getElemento(j)->setData(0);
                            map_matrix->getElemento(i)->getData().getElemento(j+1)->setData(tower_type);
                        }
                    case 2:
                        if(i-1>0 and map_matrix->getElemento(i-1)->getData().getElemento(j)->getData()==0){
                            map_matrix->getElemento(i)->getData().getElemento(j)->setData(0);
                            map_matrix->getElemento(i-1)->getData().getElemento(j)->setData(tower_type);
                        }
                    case 3:
                        if(i+1<matrix_size and map_matrix->getElemento(i+1)->getData().getElemento(j)->getData()==0){
                            map_matrix->getElemento(i)->getData().getElemento(j)->setData(0);
                            map_matrix->getElemento(i+1)->getData().getElemento(j)->setData(tower_type);
                        }
                }
            }
        }
    }
}