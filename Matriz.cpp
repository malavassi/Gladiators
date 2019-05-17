//
// Created by malavassi on 29/04/19.
//

#include "Matriz.h"
Matriz::Matriz() {
    int contador = 0;
    while(contador<10){
        columna1.push_back(0);
        columna2.push_back(0);
        columna3.push_back(0);
        columna4.push_back(0);
        columna5.push_back(0);
        columna6.push_back(0);
        columna7.push_back(0);
        columna8.push_back(0);
        columna9.push_back(0);
        columna10.push_back(0);
        contador++;
    }
    matriz.push_back(columna1);
    matriz.push_back(columna2);
    matriz.push_back(columna3);
    matriz.push_back(columna4);
    matriz.push_back(columna5);
    matriz.push_back(columna6);
    matriz.push_back(columna7);
    matriz.push_back(columna8);
    matriz.push_back(columna9);
    matriz.push_back(columna10);


}