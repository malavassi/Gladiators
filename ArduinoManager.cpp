//
// Created by fabian152195 on 15/05/19.
//

#include "ArduinoManager.h"


using namespace std;
using namespace LibSerial;


void ArduinoManager::inicializar() {

    memset (&tty, 0, sizeof tty);

/* Error Handling */
    if ( tcgetattr ( USB, &tty ) != 0 ) {
        cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << endl;
    }

/* Save old tty parameters */
    tty_old = tty;

/* Set Baud Rate */
    cfsetospeed (&tty, (speed_t)B9600);
    cfsetispeed (&tty, (speed_t)B9600);

/* Setting other Port Stuff */
    tty.c_cflag     &=  ~PARENB;            // Make 8n1
    tty.c_cflag     &=  ~CSTOPB;
    tty.c_cflag     &=  ~CSIZE;
    tty.c_cflag     |=  CS8;

    tty.c_cflag     &=  ~CRTSCTS;           // no flow control
    tty.c_cc[VMIN]   =  1;                  // read doesn't block
    tty.c_cc[VTIME]  =  5;                  // 0.5 seconds read timeout
    tty.c_cflag     |=  CREAD | CLOCAL;     // turn on READ & ignore ctrl lines

/* Make raw */
    cfmakeraw(&tty);

/* Flush Port, then applies attributes */
    tcflush( USB, TCIFLUSH );
    if ( tcsetattr ( USB, TCSANOW, &tty ) != 0) {
        cout << "Error " << errno << " from tcsetattr" << endl;
    }
}

char ArduinoManager::leer() {
    spot = 0;
/*Whole response*/
    char response[500];
    memset(response, '\0', sizeof response);

    do {
        n = read( USB, &buf, 1 );
        sprintf( &response[spot], "%c", buf );
        spot += n;
    } while( buf != '.' && n > 0);
    if (n < 0) {
        cout << "Error reading: " << strerror(errno) << endl;
    }
    else if (n == 0) {
        cout << "Read nothing!" << endl;
    }
    else {
        cout << "Response: " << response << endl;
        return response[0];
    }
}

void ArduinoManager::escribir(unsigned char* cmd, int size) {
    int n_written = 0,
            spot = 0;
    usleep(1750000);
    while (spot < size) {
        n_written = write(USB, &cmd[spot], 1);
        spot += n_written;
        usleep(2000);
    }
}
void ArduinoManager::enviar_palabra(string cadena) {
    cadena += '.';
    unsigned char cadena1[cadena.size()];
    for(int i = 0; i < cadena.size();i++){
        cadena1[i] = cadena[i];
    }
    escribir(cadena1, cadena.size());
}

bool ArduinoManager::entrada() {
    char aux = this->leer();
    if (aux == '2') {
        cout << "RETORNA FALSO" << endl;
        return false;
    } else if (aux == '1') {
        cout << "RETORNA VERDADERO" << endl;
    }
}
void ArduinoManager::verificar(string palabra){
    this->inicializar();
    this->enviar_palabra(palabra);
    bool a = this->entrada();
    this->enviar_palabra(palabra);
    if(a) {
        this->enviar_palabra("ACEPTADA");
    }else{
        this->enviar_palabra("DENEGADA");
    }
}

void ArduinoManager::enviarEstadoGladiador(Gladiator *gladiator, int id) {

    LinkedList<int> *listaAtributos = new LinkedList<int>();
    listaAtributos->push_front(gladiator->getFuerzaTInferior());
    listaAtributos->push_back(gladiator->getFuerzaTSuperior());
    listaAtributos->push_back(gladiator->getCondicionFisica());

    NodeArduino *nodeArduino3 = new NodeArduino(gladiator->getCondicionFisica(), "CF");
    NodeArduino *nodeArduino = new NodeArduino(gladiator->getFuerzaTSuperior(), "FTS");
    NodeArduino *nodeArduino2 = new NodeArduino(gladiator->getFuerzaTInferior(), "FTI");

    int cont = 0;

    for (int i = 0; i<3; i++){

        if (nodeArduino->getData()<=listaAtributos->getElemento(i)->getData()){
            nodeArduino->setCont(nodeArduino->getCont()+1);
        }

        if (nodeArduino2->getData()<=listaAtributos->getElemento(i)->getData()){
            nodeArduino2->setCont(nodeArduino2->getCont()+1);
        }

        if (nodeArduino3->getData()<=listaAtributos->getElemento(i)->getData()){
            nodeArduino3->setCont(nodeArduino3->getCont()+1);
        }

    }

    if(id==1){

        activarLED(1,gladiator->getResistencia());
        activarLED(2,nodeArduino->getCont());
        activarLED(4,nodeArduino2->getCont());
        activarLED(3,nodeArduino3->getCont());
    }

    else if(id==2){
        activarLED(5,gladiator->getResistencia());
        activarLED(6,nodeArduino->getCont());
        activarLED(7,nodeArduino2->getCont());
        activarLED(8,nodeArduino3->getCont());
    }
    else{

    }
}


void ArduinoManager::activarLED(int numLED, int num) {
    string mensaje="";
    if(numLED == 1){
        mensaje+="<A";
        mensaje+=numToString(num);
        mensaje+=">";
        enviar_palabra(mensaje);
    }

    else if(numLED==2){
        mensaje+="<G";
        mensaje+="2"+to_string(4-num);
        mensaje+=">";
        enviar_palabra(mensaje);
    }

    else if(numLED==3){
        mensaje+="<G";
        mensaje+="3"+to_string(4-num);
        mensaje+=">";
        enviar_palabra(mensaje);
    }

    else if(numLED==4){
        mensaje+="<G";
        mensaje+="4"+to_string(4-num);
        mensaje+=">";
        enviar_palabra(mensaje);
    }

    if(numLED == 5){
        mensaje+="<B";
        mensaje+=numToString(num);
        mensaje+=">";
        enviar_palabra(mensaje);
    }

    else if(numLED==6){
        mensaje+="<G";
        mensaje+="6"+to_string(4-num);
        mensaje+=">";
        enviar_palabra(mensaje);
    }

    else if(numLED==7){
        mensaje+="<G";
        mensaje+="7"+to_string(4-num);
        mensaje+=">";
        enviar_palabra(mensaje);
    }

    else if(numLED==8){
        mensaje+="<G";
        mensaje+="8"+to_string(4-num);
        mensaje+=">";
        enviar_palabra(mensaje);
    }



}
string ArduinoManager::numToString(int num) {

    string numero = "";

    numero+=to_string(num/1000);
    numero+=to_string((num/100)%10);
    numero+=to_string((num/10)%10);
    numero+=to_string(num%10);

    return numero;
}