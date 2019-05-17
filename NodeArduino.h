
//
// Created by fabian152195 on 15/05/19.
//

#ifndef GLADIATORS_NODEARDUINO_H
#define GLADIATORS_NODEARDUINO_H
#include <string>

using namespace std;

class NodeArduino {

private:
    int data;
    string info;
    int cont;
public:
    int getData() const;

    void setData(int data);

    const string &getInfo() const;

    void setInfo(const string &info);

    int getCont() const;

    void setCont(int cont);

    NodeArduino();

    NodeArduino(int data, string info);

};


#endif //GLADIATORS_NODEARDUINO_H
