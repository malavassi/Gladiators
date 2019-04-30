//
// Created by cvaz on 29/04/19.
//

#ifndef GLADIATORS_TUPLACUADRANTE_H
#define GLADIATORS_TUPLACUADRANTE_H


class TuplaCuadrante {
public:
    TuplaCuadrante(){
        pos_x=0;
        pos_y=0;
        f_value=0;
    }

    TuplaCuadrante(int posx, int posy, double f){
        pos_x=posx;
        pos_y=posy;
        f_value=f;
    }

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    double getFValue() const;

    void setFValue(double fValue);

private:
    int pos_x;
    int pos_y;
    double f_value;
};


#endif //GLADIATORS_TUPLACUADRANTE_H
