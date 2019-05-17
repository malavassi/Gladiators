//
// Created by cvaz on 30/04/19.
//

#include "Quadrant.h"

int Quadrant::getParentX() const {
    return parent_x;
}

void Quadrant::setParentX(int parentX) {
    parent_x = parentX;
}

int Quadrant::getParentY() const {
    return parent_y;
}

void Quadrant::setParentY(int parentY) {
    parent_y = parentY;
}

double Quadrant::getF() const {
    return f;
}

void Quadrant::setF(double f) {
    Quadrant::f = f;
}

double Quadrant::getG() const {
    return g;
}

void Quadrant::setG(double g) {
    Quadrant::g = g;
}

double Quadrant::getH() const {
    return h;
}

void Quadrant::setH(double h) {
    Quadrant::h = h;
}

int Quadrant::getPosX() const {
    return pos_x;
}

void Quadrant::setPosX(int posX) {
    pos_x = posX;
}

int Quadrant::getPosY() const {
    return pos_y;
}

void Quadrant::setPosY(int posY) {
    pos_y = posY;
}
