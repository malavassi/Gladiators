//
// Created by cvaz on 30/04/19.
//

#ifndef GLADIATORS_QUADRANT_H
#define GLADIATORS_QUADRANT_H


class Quadrant {
public:
    int getParentX() const;

    void setParentX(int parentX);

    int getParentY() const;

    void setParentY(int parentY);

    double getF() const;

    void setF(double f);

    double getG() const;

    void setG(double g);

    double getH() const;

    void setH(double h);

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

private:
    int parent_x, parent_y, pos_x, pos_y;
    double f, g, h;
};


#endif //GLADIATORS_QUADRANT_H
