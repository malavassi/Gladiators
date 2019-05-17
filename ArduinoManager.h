//
// Created by fabian152195 on 15/05/19.
//

#ifndef GLADIATORS_ARDUINOMANAGER_H
#define GLADIATORS_ARDUINOMANAGER_H

#include "SerialStream.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <fcntl.h>
#include <fcntl.h>
#include <cstring>
#include "Poblacion.h"
#include "Gladiator.h"
#include "LinkedList.h"
#include "NodeArduino.h"

using namespace std;

class ArduinoManager {


public:
    struct termios tty;
    struct termios tty_old;
    int USB = open("/dev/ttyACM0", O_RDWR| O_NOCTTY);
    int n = 0,
            spot = 0;
    char buf = '\0';
    void escribir(unsigned char cmd[], int size);
    char leer();
    void inicializar();
    void enviar_palabra(string cadena);
    bool entrada();
    void verificar(string palabra);
    void enviarEstadoGladiador(Gladiator * gladiator, int id);
    void activarLED(int numLED, int num);
    string numToString(int num);
};


#endif //GLADIATORS_ARDUINOMANAGER_H
