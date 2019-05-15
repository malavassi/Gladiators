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

    posiciones encontrarRuta(LinkedList<LinkedList<int>> matriz, int salida);

    int codificar(int x, int y);

    casilla decodificar(int x);

    string codificar_string(int x, int y);

    LinkedList<int> fila(LinkedList<LinkedList<int>> matriz, int num);

    bool isVisited(int x, int y);

    void retornarVecino(casilla x, LinkedList<LinkedList<int>> matriz);

    void verificarDisponible(LinkedList<LinkedList<int>> matriz, int x, int y);

    LinkedList<LinkedList<int>> *getMatrix() const;

    void setMatrix(LinkedList<LinkedList<int>> *matrix);

    const posiciones &getPath() const;

    void setPath(const posiciones &path);

    const posiciones &getVisited() const;

    void setVisited(const posiciones &visited);

    const casilla &getInicio() const;

    void setInicio(const casilla &inicio);

    const casilla &getFin() const;

    void setFin(const casilla &fin);

    const casilla &getCurrentPoint() const;

    void setCurrentPoint(const casilla &currentPoint);

    const LinkedList<casilla> &getVecinos() const;

    void setVecinos(const LinkedList<casilla> &vecinos);

private:
    LinkedList<LinkedList<int>>* matrix;
    posiciones path;
    posiciones visited;
    casilla inicio;
    casilla fin;
    casilla currentPoint;
    LinkedList<casilla> vecinos;
};


#endif //GLADIATORS_BACKTRACKING_H
