//
// Created by malavassi on 29/04/19.
//

#ifndef GLADIATORS_BACKTRACKING_H
#define GLADIATORS_BACKTRACKING_H


#include "LinkedList.h"
#include "Matriz.h"
#include <iostream>

class Backtracking {
public:
    struct posiciones {
        LinkedList<int> posx;
        LinkedList<int> posy;
    };
    struct casilla{
        int posx;
        int posy;
    };
    Matriz matrix;
    posiciones path;
    posiciones visited;
    casilla inicio;
    casilla fin;
    casilla currentPoint;
    LinkedList<casilla> vecinos;

    posiciones encontrarRuta(LinkedList<LinkedList<int>> matriz);
    int codificar(int x, int y);
    casilla decodificar(int x);
    string codificar_string(int x, int y);
    LinkedList<int> fila(LinkedList<LinkedList<int>> matriz, int num);
    bool isVisited(int x, int y);
    void retornarVecino(casilla x, LinkedList<LinkedList<int>> matriz);

    void verificarDisponible(LinkedList<LinkedList<int>> matriz, int x, int y);
};


#endif //GLADIATORS_BACKTRACKING_H
