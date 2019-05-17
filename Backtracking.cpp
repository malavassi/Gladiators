//
// Created by malavassi on 29/04/19.
//

#include "Backtracking.h"
#include <iostream>
using namespace std;
LinkedList<int> Backtracking::fila(LinkedList<LinkedList<int>> matriz, int num) {
    switch(num){
        case 0:
            return matriz.getElemento(0)->getData();
        case 1:
            return matriz.getElemento(1)->getData();
        case 2:
            return matriz.getElemento(2)->getData();
        case 3:
            return matriz.getElemento(3)->getData();
        case 4:
            return matriz.getElemento(4)->getData();
        case 5:
            return matriz.getElemento(5)->getData();
        case 6:
            return matriz.getElemento(6)->getData();
        case 7:
            return matriz.getElemento(7)->getData();
        case 8:
            return matriz.getElemento(8)->getData();
        case 9:
            return matriz.getElemento(9)->getData();


    }
}

bool Backtracking::isVisited(int x, int y){
    int c = 0;
    Node<int> *aux_x = visited.posx.getHead();
    Node<int> *aux_y = visited.posy.getHead();
    bool booleano = false;
    while(c < this->visited.posx.getSize()){
        if(aux_x->getData() == x && aux_y->getData() == y){
            booleano = true;
            break;
        }
        if(aux_x == visited.posx.getTail() && aux_y == visited.posy.getTail()){
            break;
        }
        aux_x = aux_x->getNext();
        aux_y = aux_y->getNext();
        c++;
    }
    return booleano;
}
Backtracking::posiciones Backtracking::encontrarRuta(int salida) {
    this->visited.posx.clearList();
    this->visited.posy.clearList();
    this->path.posx.clearList();
    this->path.posy.clearList();
    this->inicio.posx = salida/10;
    this->inicio.posy = salida%10;
    this->fin.posx = 9;
    this->fin.posy = 9;
    path.posx.push_front(inicio.posx);
    path.posy.push_front(inicio.posy);
    visited.posx.push_front(inicio.posx);
    visited.posy.push_front(inicio.posy);
    currentPoint = inicio;
    //
    int cont = 1;
    //
    if(path.posx.getHead() != NULL){
    while ((path.posx.getHead()->getData() != 9 || path.posy.getHead()->getData() != 9) &&
           (path.posx.getSize() != 0 && path.posy.getSize() != 0)) {
        cout << "Entre al while del encontrarRuta, cont: " << cont << endl;
        this->retornarVecino(currentPoint, *matrix);
        cout << "Ya finalice retornarVecino" << endl;
        cont++;
    }
    cout << "Sali del while de encontrarRuta" << endl;
    }
    posiciones aux;

    if(path.posx.getSize() != 0){
        aux.posx = path.posx;
        aux.posy = path.posy;
    }
    //----------------------------------------------------//
    int i = 0;
    cout << "---------------------------------" << endl;
    cout << "La ruta en x es: " << endl;
    while (i < aux.posx.getSize()) {
    cout << i << ": " << aux.posx.getElemento(i)->getData() << endl;
    i++;
    }
    int c = 0;
    cout << "---------------------------------" << endl;
    cout << "La ruta en y es: " << endl;
    while (c < aux.posx.getSize()) {
        cout << c << ": " << aux.posy.getElemento(c)->getData() << endl;
        c++;
    }
    cout << "---------------------------------" << endl;
    //----------------------------------------------------//
    posiciones aux_aux;
    int numero = aux.posx.getSize();
    for(int i = 0; i<c; i++){
        aux_aux.posx.push_back(aux.posx.pop_front()->getData());
        aux_aux.posy.push_back(aux.posy.pop_front()->getData());
    }
    return aux_aux;
}

LinkedList<int> Backtracking::final_path() {
    LinkedList<int> auxiliar;
    int a = path.posx.getSize();
    int num = 0;
    for(int i = 0; i < a; i++){
        num = 10*path.posx.pop_front()->getData()+path.posy.pop_front()->getData();
        auxiliar.push_front(num);
        cout << "final_path inserta: " << num << endl;
    }
    return auxiliar;
}

/*
int Backtracking::codificar(int x, int y) {
    int coord = (int)((char)x+(char)y);
    return coord;
}

string Backtracking::codificar_string(int x, int y) {
    string coord = reinterpret_cast<char *>((char) x + (char) y);
    return coord;
}

Backtracking::casilla Backtracking::decodificar(int x) {
    string aux = (char*)x;
    int coordy = (int)aux.back();
    aux.pop_back();
    int coordx = (int)aux.back();
    casilla decodificado;
    decodificado.posx = coordx;
    decodificado.posy = coordy;
    return decodificado;
}
 */

void Backtracking::verificarDisponible(LinkedList<LinkedList<int>> matriz, int x, int y){
    cout << "Estoy verificando si x:" << x << ", y:" << y << " esta disponible" << endl;
    if(matriz.getElemento(y)->getData().getElemento(x)->getData() == 0 && isVisited(x,y) == false){
        cout << "La casilla esta disponible" << endl;
        casilla aux;
        aux.posx = x;
        aux.posy = y;
        this->vecinos.push_front(aux);
        cout << "Acabo de agregar x:" << x << ", y:" << y << " a la lista de vecinos" << endl;
        cout << "Ahora, vecinos tiene un tamano de: " << this->vecinos.getSize() << endl;
    }else{
        cout << "La casilla no esta disponible" << endl;
    }
}


void Backtracking::retornarVecino(Backtracking::casilla x, LinkedList<LinkedList<int>> matriz) {
    vecinos.clearList();
    switch(x.posx){
    case 9:
        if(x.posy == 0){
            verificarDisponible(matriz, 8, 0);
            verificarDisponible(matriz, 8, 1);
            verificarDisponible(matriz, 9, 1);
        }else if(x.posy == 8) {
            verificarDisponible(matriz, 9, 9);
        }else{
                verificarDisponible(matriz, x.posx-1, x.posy);
                verificarDisponible(matriz, x.posx, x.posy+1);
                verificarDisponible(matriz, x.posx, x.posy-1);
                verificarDisponible(matriz, x.posx-1, x.posy+1);
                verificarDisponible(matriz, x.posx-1, x.posy-1);
            }

        break;

    case 0:
        if(x.posy == 0){
            verificarDisponible(matriz, 1, 0);
            verificarDisponible(matriz, 0, 1);
            verificarDisponible(matriz, 1, 1);
        }else if(x.posy == 9){
            verificarDisponible(matriz, 0, 8);
            verificarDisponible(matriz, 1, 8);
            verificarDisponible(matriz, 1, 9);
        }else{
            verificarDisponible(matriz, x.posx+1, x.posy);
            verificarDisponible(matriz, x.posx, x.posy+1);
            verificarDisponible(matriz, x.posx, x.posy-1);
            verificarDisponible(matriz, x.posx+1, x.posy+1);
            verificarDisponible(matriz, x.posx+1, x.posy-1);
        }
        break;
    default:
        if((x.posx == 8)&&(x.posy == 8 || x.posy == 9)){
            verificarDisponible(matriz, 9, 9);
        }else{
            if (x.posy == 0) {
                verificarDisponible(matriz, x.posx - 1, x.posy);
                verificarDisponible(matriz, x.posx + 1, x.posy);
                verificarDisponible(matriz, x.posx, x.posy + 1);
                verificarDisponible(matriz, x.posx - 1, x.posy + 1);
                verificarDisponible(matriz, x.posx + 1, x.posy + 1);
            } else if (x.posy == 9) {
                verificarDisponible(matriz, x.posx - 1, x.posy);
                verificarDisponible(matriz, x.posx + 1, x.posy);
                verificarDisponible(matriz, x.posx, x.posy - 1);
                verificarDisponible(matriz, x.posx - 1, x.posy - 1);
                verificarDisponible(matriz, x.posx + 1, x.posy - 1);
            } else {
                verificarDisponible(matriz, x.posx - 1, x.posy);
                verificarDisponible(matriz, x.posx + 1, x.posy);
                verificarDisponible(matriz, x.posx, x.posy - 1);
                verificarDisponible(matriz, x.posx, x.posy + 1);
                verificarDisponible(matriz, x.posx + 1, x.posy + 1);
                verificarDisponible(matriz, x.posx - 1, x.posy + 1);
                verificarDisponible(matriz, x.posx + 1, x.posy - 1);
                verificarDisponible(matriz, x.posx - 1, x.posy - 1);
            }
        }
        break;
}
casilla sig;
///cout << "El verdadero tamano de la lista de vecinos antes de entrar al if es de: " << vecinos.getSize() << endl;
if(vecinos.getSize()!=0) {
    cout << "El tamano de la lista de vecinos es diferente de cero" << endl;
    srand(time(NULL));
    int num = rand() % vecinos.getSize();
    sig = vecinos.getElemento(num)->getData();
    cout << "La posicion aleatoria elegida de la lista es: " << num << endl;
    this->visited.posx.push_front(sig.posx);
    this->visited.posy.push_front(sig.posy);
    this->path.posx.push_front(sig.posx);
    this->path.posy.push_front(sig.posy);
    this->currentPoint = sig;
    cout << " Me movi, ahora currentPoint es x: " << this->currentPoint.posx << ", y: " << this->currentPoint.posy << endl;
}else {
    cout << "El tamano de la lista de vecinos es igual a cero" << endl;
    this->visited.posx.push_front(this->currentPoint.posx);
    this->visited.posy.push_front(this->currentPoint.posy);
    cout << "Estoy sacando de la lista path a x: " << this->visited.posx.getHead()->getData() << ", y: "
         << this->visited.posy.getHead()->getData() << endl;
    this->path.posx.pop_front();
    this->path.posy.pop_front();
    if (path.posx.getSize() != 0) {
    sig.posx = path.posx.getHead()->getData();
    sig.posy = path.posy.getHead()->getData();
    this->currentPoint = sig;
    }
    cout << " Retrocedi, ahora currentPoint es x: " << this->currentPoint.posx << ", y: " << this->currentPoint.posy << endl;
}

}

LinkedList<LinkedList<int>> *Backtracking::getMatrix() const {
    return matrix;
}

void Backtracking::setMatrix(LinkedList<LinkedList<int>> *matrix) {
    Backtracking::matrix = matrix;
}

Backtracking::posiciones &Backtracking::getPath(){
    return path;
}

void Backtracking::setPath(const Backtracking::posiciones &path) {
    Backtracking::path = path;
}

const Backtracking::posiciones &Backtracking::getVisited() const {
    return visited;
}

void Backtracking::setVisited(const Backtracking::posiciones &visited) {
    Backtracking::visited = visited;
}

const Backtracking::casilla &Backtracking::getInicio() const {
    return inicio;
}

void Backtracking::setInicio(const Backtracking::casilla &inicio) {
    Backtracking::inicio = inicio;
}

const Backtracking::casilla &Backtracking::getFin() const {
    return fin;
}

void Backtracking::setFin(const Backtracking::casilla &fin) {
    Backtracking::fin = fin;
}

const Backtracking::casilla &Backtracking::getCurrentPoint() const {
    return currentPoint;
}

void Backtracking::setCurrentPoint(const Backtracking::casilla &currentPoint) {
    Backtracking::currentPoint = currentPoint;
}

const LinkedList<Backtracking::casilla> &Backtracking::getVecinos() const {
    return vecinos;
}

void Backtracking::setVecinos(const LinkedList<Backtracking::casilla> &vecinos) {
    Backtracking::vecinos = vecinos;
}
