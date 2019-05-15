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
    }
    for(int i = 0; i < juego.getPoblacionB()->getGeneraciones().getSize(); i++){
        B.addPoint(i,juego.getPoblacionB()->getGeneraciones().getElemento(i)->getData()->getPromedioSupervivencia());
    }
    A.show();
    B.show();
    return a.exec();
    //---------------------------------------------------------- NO BORRAR
}

