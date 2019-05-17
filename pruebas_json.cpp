//
// Created by cvaz on 15/05/19.
//
#include "Sendable.h"
#include "Gladiator.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;
int amain(){
    Sendable prueba = Sendable();
    LinkedList<LinkedList<int>> pl= LinkedList<LinkedList<int>>();
    LinkedList<int> pp = LinkedList<int>();
    pp.push_back(1234);
    pp.push_back(4567);
    pl.push_back(pp);
    pp = LinkedList<int>();
    pp.push_back(7890);
    pl.push_back(pp);
    prueba.setMovimientos(pl);
    int arrr[10] = {1,2,3,4,5,6,7,8,9,10};
    prueba.setGlad1(arrr);
    cout<<prueba.toJson();
    Sendable gladiador = Sendable::toObj("{glad1:[ 1,2,3,4,5,6,7,8,9,10 ], glad2:[ 0,0,0,0,0,0,0,0,0,0 ], mensaje:\"Hola\", movimientos:[[]]}");

    cout<<gladiador.toJson();
    return 0;
}