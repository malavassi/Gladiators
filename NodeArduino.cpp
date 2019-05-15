//
// Created by fabian152195 on 15/05/19.
//

#include "NodeArduino.h"

int NodeArduino::getData() const {
    return data;
}

void NodeArduino::setData(int data) {
    NodeArduino::data = data;
}

const string &NodeArduino::getInfo() const {
    return info;
}

void NodeArduino::setInfo(const string &info) {
    NodeArduino::info = info;
}

NodeArduino::NodeArduino() {

    this->data = 0;
    this->info = "";
    this->cont=0;


}

NodeArduino::NodeArduino(int data, string info) {

    this->data = data;
    this->info = info;
    this->cont = 0;

}

int NodeArduino::getCont() const {
    return cont;
}

void NodeArduino::setCont(int cont) {
    NodeArduino::cont = cont;
}
