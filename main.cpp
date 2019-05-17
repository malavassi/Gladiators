//
// Created by fabian on 24/03/19.
//

#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include "Simulacion.h"
#include <QApplication>
#include <QDebug>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    //---------------------------------------------------------- NO BORRAR
    Simulacion juego = Simulacion();
    juego.iniciar();
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
    return a.exec();
    //---------------------------------------------------------- NO BORRAR
}

