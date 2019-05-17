//
// Created by cvaz on 29/04/19.
//

#include "TuplaCuadrante.h"

int TuplaCuadrante::getPosX() const {
    return pos_x;
}

void TuplaCuadrante::setPosX(int posX) {
    pos_x = posX;
}

int TuplaCuadrante::getPosY() const {
    return pos_y;
}

void TuplaCuadrante::setPosY(int posY) {
    pos_y = posY;
}

double TuplaCuadrante::getFValue() const {
    return f_value;
}

void TuplaCuadrante::setFValue(double fValue) {
    f_value = fValue;
}
