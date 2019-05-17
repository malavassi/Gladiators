//
// Created by kevin on 05/05/19.
//

#include "MainExe.h"
#include <stdio.h>
#include "Sendable.h"
#include <string>
#include <string.h>
#include <iostream>
#include "mainwindow.h"
#include "Simulacion.h"

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
    aStar = new AStar(game_size, game_size-1, game_size-1);
    aStar->setMapMatrix(map_matrix);
    backtracking = new Backtracking();
    backtracking->setMatrix(map_matrix);
    iteration_ctr=0;
    matrix_size=game_size;
    tower_ctr=0;
}

MainExe::~MainExe() {
}

void MainExe::iniciar() {
    bool terminar = false;
    //Sendable paquete = Sendable();
    //server = Server();
    //server.run();
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
    while (!terminar) {
        showRutas(getRutasAlgoritmos());
        //siguienteIteracion();
        /*Sendable sendable = Sendable();
        LinkedList<LinkedList<int>> enviar = LinkedList<LinkedList<int>>();  // Lista a enviar, 000, tipo,x,y
        LinkedList<int> list2 = LinkedList<int>();
        list2.push_back(0);
        list2.push_back(0);
        for (int i = 0; i < map_matrix->getSize(); i++) {
            for (int j = 0; j < map_matrix->getElemento(i)->getData().getSize(); j++) {
                int elemento = map_matrix->getElemento(i)->getData().getElemento(j)->getData();
                if (elemento == 1 || elemento == 2 || elemento == 3) {
                    list2.push_back(elemento * 100 + i * 10 + j);
                }
            }
        }*/
        print();
       // enviar.push_back(list2);
       // sendable.setMovimientos(enviar);
        //cout<<sendable.toJson()<<flush;
       // server.sendToClient(sendable.toJson());
        //server.readFromClient();  // Espera a que el cliente este listo
            // Envia los spawns

            // Envia los movimientos
            sendable = Sendable();
            int *arr = atributeArray(poblacionA->getElegido(), 0);
            sendable.setGlad1(arr);     //PoblacionA = A* = 0 & PoblacionB = Backtracking = 1
            sendable.setGlad2(atributeArray(poblacionB->getElegido(), 1));
            sendable.setMovimientos(formatMovements(iteration_ctr));/*
            /*server.sendToClient(sendable.toJson());
            server.readFromClient();
            if(strcmp(server.buffer, "nueva")==0){
                siguienteIteracion();
            }*/


            cout << sendable.toJson();
            cout << "\n";
            cout << "Introduzca un comando:\n 1: Reproducir\n0: Finalizar\n";

             int seleccion;
            cin >> seleccion;
            switch (seleccion) {
                case 1:
                    siguienteIteracion();
                    break;
                case 0:
                    terminar = true;
                    break;
            }
        }
    }

void MainExe::print() {
    cout<<" _ _ _ _ _ _ _ _ _ _\n"<<flush;
    for (int i = 0; i < map_matrix->getSize(); i++) {
        for (int j = 0; j < map_matrix->getElemento(i)->getData().getSize(); j++) {
            switch (map_matrix->getElemento(i)->getData().getElemento(j)->getData()) {
                case 0:
                    cout<<" v"<<flush;
                    break;
                case 1:
                    cout<<" n"<<flush;
                    break;
                case 2:
                    cout<<" f"<<flush;
                    break;
                case 3:
                    cout<<" e"<<flush;
                    break;
                case 4:
                    cout<<" p"<<flush;
                    break;
                default:
                    cout<<" l"<<flush;
            }
        }
        if(i!=9){
            cout<<endl;
        }else{
            cout<<endl;
        }

    }
    string a;
    cout<<"La matriz es:";
    cin>>a;

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
    print();
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
    map_matrix->getElemento(pos_x)->getData().getElemento(pos_y)->setData(type+1);
    print();
}

void MainExe::rearrangeTowers(){
    Node<LinkedList<int>>* tmp = map_matrix->getHead();
    for(int i=0; i<matrix_size; i++){
        tmp->getData().randomize();
        tmp=tmp->getNext();
    }
    map_matrix->randomize();
    print();
}

void MainExe::checkAvailability() {
    while(!aStar->aStarSearch(0, 0)){
        rearrangeTowers();
    }
}

LinkedList<int> MainExe::moveTowers() {
    LinkedList<int> movimientos = LinkedList<int>();
    for(int i=0; i<matrix_size; i++){
        for(int j=0; j<matrix_size; j++){
            if(map_matrix->getElemento(i)->getData().getElemento(j)->getData()!=0 and map_matrix->getElemento(i)->getData().getElemento(j)->getData()!=4){
                int dir = (int) (rand()%4);     //direccion en la cual se va a mover 0=Arriba, 1=Abajo, 2=Izquierda, 3=Derecha
                int tower_type = map_matrix->getElemento(i)->getData().getElemento(j)->getData();
                switch(dir){
                    case 0:
                        if(j-1>=0 and map_matrix->getElemento(i)->getData().getElemento(j-1)->getData()==0){
                            map_matrix->getElemento(i)->getData().getElemento(j)->setData(0);
                            map_matrix->getElemento(i)->getData().getElemento(j-1)->setData(tower_type);
                            movimientos.push_back((i*1000)+(j*100)+(i*10)+(j-1));
                        }
                    case 1:
                        if(j+1<matrix_size and map_matrix->getElemento(i)->getData().getElemento(j+1)->getData()==0){
                            map_matrix->getElemento(i)->getData().getElemento(j)->setData(0);
                            map_matrix->getElemento(i)->getData().getElemento(j+1)->setData(tower_type);
                            movimientos.push_back((i*1000)+(j*100)+(i*10)+(j+1));
                        }
                    case 2:
                        if(i-1>=0 and map_matrix->getElemento(i-1)->getData().getElemento(j)->getData()==0){
                            map_matrix->getElemento(i)->getData().getElemento(j)->setData(0);
                            map_matrix->getElemento(i-1)->getData().getElemento(j)->setData(tower_type);
                            movimientos.push_back((i*1000)+(j*100)+((i-1)*10)+(j));
                        }
                    case 3:
                        if(i+1<matrix_size and map_matrix->getElemento(i+1)->getData().getElemento(j)->getData()==0){
                            map_matrix->getElemento(i)->getData().getElemento(j)->setData(0);
                            map_matrix->getElemento(i+1)->getData().getElemento(j)->setData(tower_type);
                            movimientos.push_back((i*1000)+(j*100)+((i+1)*10)+(j));
                        }
                }
            }
        }
    }
    print();
    return movimientos;
}

int main(int argc, char *argv[]){
    MainExe* mainExe = new MainExe(10);
    mainExe->iniciar();

    Sendable sendable = Sendable();
    sendable.setMovimientos(mainExe->formatMovements(0));
    cout<<sendable.toJson()<<endl;

    //---------------------------------------------------------- NO BORRAR
   // MainExe juego = MainExe(10);
   // juego.iniciar();

   /* comento
    qDebug() << QT_VERSION_STR;
    QApplication a(argc, argv);
    MainWindow A,B;
    for(int i = 0; i < juego.getPoblacionA()->getGeneraciones().getSize(); i++){
        A.addPoint(i,juego.getPoblacionA()->getGeneraciones().getElemento(i)->getData()->getPromedioSupervivencia());
        cout << "Promedio de supervivencia de "<< i <<"A: " << juego.getPoblacionA()->getGeneraciones().getElemento(i)->getData()->getPromedioSupervivencia() << endl;
    }
    for(int i = 0; i < juego.getPoblacionB()->getGeneraciones().getSize(); i++){
        B.addPoint(i,juego.getPoblacionB()->getGeneraciones().getElemento(i)->getData()->getPromedioSupervivencia());
        cout << "Promedio de supervivencia de "<< i <<"B: " << juego.getPoblacionB()->getGeneraciones().getElemento(i)->getData()->getPromedioSupervivencia() << endl;
    }
    A.show();
    B.show();
    */
    //return a.exec();
    //---------------------------------------------------------- NO BORRAR



}

int *MainExe::atributeArray(Gladiator *glad, int poblacion){
 int *result = new int[10];
 result[0] = glad->getIdUnico();
 result[1] = glad->getEdad();
 result[2] = glad->getProbabilidadSupervivencia();
 result[3] = glad->getGeneracionesEsperadas();
 result[4] = glad->getIQemocional();
 result[5] = glad->getCondicionFisica();
 result[6] = glad->getFuerzaTSuperior();
 result[7] = glad->getFuerzaTInferior();
 result[8] = glad->getResistencia();
 result[9] = poblacion;
 return result;
}

LinkedList<LinkedList<int>> MainExe::formatMovements(int counter) {
 LinkedList<LinkedList<int>> result = LinkedList<LinkedList<int>>();
 int a_star_current = 0;
 int backtracking_current = 0;
 int a_star_next = 0;
 int backtracking_next = 0;
 if(counter%3==0 && counter!=0){       //Si se trata de la tercer iteración relativa
     while(a_star_current!=99 && backtracking_current!=99){
         LinkedList<int> tmp_movements = LinkedList<int>();

         //Astar movements
         aStar->aStarSearch(a_star_current/10, a_star_current%10);
         a_star_next = aStar->getGeneratedPath().getHead()->getData();
         moveGladiator(a_star_current/10, a_star_current%10, a_star_next/10, a_star_next%10);
         tmp_movements.push_back(a_star_current*100+a_star_next);

         //Backtracking movements
         backtracking->encontrarRuta(backtracking_current);
         backtracking_current = backtracking->getPath().posx.front()*10 + backtracking->getPath().posy.front();
         backtracking_next = backtracking->getPath().posx.getElemento(1)->getData()*10 + backtracking->getPath().posy.getElemento(1)->getData();
         moveGladiator(backtracking_current/10, backtracking_current%10, backtracking_next/10, backtracking_next%10);
         tmp_movements.push_back(backtracking_current*100 + backtracking_next);

         //Tower movements
         LinkedList<int> tower_movements = moveTowers();
         while(tower_movements.getSize()>0){
             tmp_movements.push_back(tower_movements.getHead()->getData());
             tower_movements.pop_front();
         }
         a_star_current = a_star_next;
         backtracking_current = backtracking_next;
         result.push_back(tmp_movements);
     }
 }
 else{
     bool rutasCalculadas = false;
     while(!rutasCalculadas){
         LinkedList<int> astar_movements = LinkedList<int>();
         aStar->aStarSearch(0, 0);  // Realiza la busqueda del camino
         LinkedList<int> aStarPath = aStar->getGeneratedPath();
         LinkedList<int> backtracking_movements = LinkedList<int>();
         backtracking->encontrarRuta(0);
         LinkedList<int> backtracking_path = backtracking->final_path();
         if(aStar->aStarSearch(0,0)){
             while(a_star_current != 99){
                 a_star_next = aStarPath.getHead()->getData();  // Asigno la primera
                 aStarPath.pop_front();  // La quito
                 while(a_star_next!=99) {
                     astar_movements.push_back(a_star_current * 100 + a_star_next);
                     a_star_current = a_star_next;
                     a_star_next = aStarPath.getHead()->getData();
                     aStarPath.pop_front();
                 }
                 astar_movements.push_back(a_star_current*100+a_star_next);  // Asigno la ultima
                 a_star_current = a_star_next;
                 result.push_back(astar_movements);
             }
             while(backtracking_current!=99){
                 backtracking_next = backtracking_path.pop_front()->getData();
                 while(backtracking_next != 99){
                     backtracking_movements.push_back(backtracking_current*100 + backtracking_next);
                     backtracking_current = backtracking_next;
                     backtracking_next = backtracking_path.getHead()->getData();
                     backtracking_path.pop_front();
                 }
                 backtracking_movements.push_back(backtracking_current*100 + backtracking_next);
                 backtracking_current=backtracking_next;
                 result.push_back(backtracking_movements);
             }
             rutasCalculadas=true;
         }
         else{
             rearrangeTowers();
         }

     }

 }
 return result;
}

LinkedList<LinkedList<int>> *MainExe::getMapMatrix() const {
 return map_matrix;
}

LinkedList<LinkedList<int>> MainExe::getRutasAlgoritmos(){
    LinkedList<LinkedList<int>> result = LinkedList<LinkedList<int>>();
    int a_star_current = 0;
    int backtracking_current = 0;
    int a_star_next = 0;
    int backtracking_next = 0;
    if(iteration_ctr%3==0 && iteration_ctr!=0){       //Si se trata de la tercer iteración relativa
        LinkedList<int> a_star_movements = LinkedList<int>();
        a_star_movements.push_back(0);
        LinkedList<int> backtracking_movements = LinkedList<int>();
        backtracking_movements.push_back(backtracking_next);
        while(a_star_current!=99 && backtracking_current!=99){

            //Astar movements
            aStar->aStarSearch(a_star_current/10, a_star_current%10);
            a_star_next = aStar->getGeneratedPath().getHead()->getData();
            moveGladiator(a_star_current/10, a_star_current%10, a_star_next/10, a_star_next%10);
            a_star_movements.push_back(a_star_next);

            //Backtracking movements
            backtracking->encontrarRuta(backtracking_current);
            backtracking_current = backtracking->getPath().posx.front()*10 + backtracking->getPath().posy.front();
            backtracking_next = backtracking->getPath().posx.getElemento(1)->getData()*10 + backtracking->getPath().posy.getElemento(1)->getData();
            moveGladiator(backtracking_current/10, backtracking_current%10, backtracking_next/10, backtracking_next%10);
            backtracking_movements.push_back(backtracking_next);

            //Tower movements
            rearrangeTowers();

            a_star_current = a_star_next;
            backtracking_current = backtracking_next;
        }
        result.push_back(a_star_movements);
        result.push_back(backtracking_movements);
        return result;
    }
    else{
        bool rutasCalculadas = false;
        while(!rutasCalculadas){
            LinkedList<int> astar_movements = LinkedList<int>();
            aStar->aStarSearch(0, 0);  // Realiza la busqueda del camino
            LinkedList<int> aStarPath = aStar->getGeneratedPath();
            LinkedList<int> backtracking_movements = LinkedList<int>();
            backtracking->encontrarRuta(0);
            LinkedList<int> backtracking_path = backtracking->final_path();
            if(aStar->aStarSearch(0,0)){
                result.push_back(aStarPath);
                result.push_back(backtracking_path);
                rutasCalculadas=true;
            }
            else{
                rearrangeTowers();
            }

        }

    }
}

void MainExe::showRutas(LinkedList<LinkedList<int>> Rutas) {
    cout << "A star: ";
    for (int i = 0; i < Rutas.getHead()->getData().getSize(); i++) {
        cout << Rutas.getHead()->getData().pop_front()->getData();
    }
    cout << endl;
    Rutas.pop_front();
    cout << "Backtracking: ";
    for (int i = 0; i < Rutas.getHead()->getData().getSize(); i++) {
        cout << Rutas.getHead()->getData().pop_front()->getData();
    }
}
void MainExe::moveGladiator(int x_i, int y_i, int x_f, int y_f) {
    map_matrix->getElemento(x_i)->getData().getElemento(y_i)->setData(0);
    map_matrix->getElemento(x_f)->getData().getElemento(y_f)->setData(4);
    print();
}
