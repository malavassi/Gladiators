//
// Created by cvaz on 08/05/19.
//

#include <iostream>

#include "Sendable.h"

Sendable::Sendable()
{
    for(int i=0;i<4;i++){
        glad1[i] = 0;
    }
    for(int i=0;i<4;i++){
        glad2[i] = 0;
    }

}

string Sendable::toJson(){
    string result = "{glad1:[ "+to_string(glad1[0])+","+to_string(glad1[1])+","+to_string(glad1[2])+","+to_string(glad1[3])+" ]";
    result += ", glad2:[ "+to_string(glad2[0])+","+to_string(glad2[1])+","+to_string(glad2[2])+","+to_string(glad2[3])+" ]";
    result += ", mensaje:"+mensaje;
    result += ", movimientos:[";
    for(int i=0;i<movimientos.getSize();i++){
        result+="[";
        for(int j=0;j<movimientos.getHead()->getData().getSize();j++){
            result+=to_string(movimientos.getHead()->getData().getHead()->getData());
            if(j!=movimientos.getHead()->getData().getSize()-1){
                result+=",";
            }
        }
        result+="]";
        if(i!=movimientos.getSize()-1){
            result+=",";
        }
    }
    result+="]";
    return result;
}

Sendable Sendable::toObj(const char json[]) {
    Sendable result = Sendable();
    LinkedList<LinkedList<int>> lista1 = LinkedList<LinkedList<int>>();
    LinkedList<int> lista2 = LinkedList<int>();
    int gladA[4] = {0,0,0,0};
    int gladB[4] = {0,0,0,0};
    bool num = true;
    bool msg = false;
    bool mov= false;
    string num1 = "";
    string num2 = "";
    int c_p = 0;
    int c_i = 0;
    int c_g = 0;
    for(int i=9;i<strlen(json);i++){
        if(c_g==0) {  // Si estoy analizando numeros
            num1 = "";
            while (json[i] != ',' && json[i]!=']') {
                num1 += json[i];
                i++;
            }
            cout<<num1<<endl;
            gladA[c_p] = atoi(num1.c_str());
            if(json[i]==']'){
                num = false;
                c_i = i;
                c_g++;
            }else{
                c_p ++;
            }
        } else if(c_g == 1){
            if(num) {
                num1 = "";
                while (json[i] != ',' && json[i] != ']') {
                    num1 += json[i];
                    i++;
                }
                gladB[c_p] = atoi(num1.c_str());
                if (json[i] == ']') {
                    c_i = i;
                    c_g++;
                } else {
                    c_p++;
                }
            }else{
                i+=9;
                num = true;
                c_p = 0;
            }
        }else if(mov){
            lista2 = LinkedList<int>();
            while(json[i]!=',' && json[i]!=']'){
                num1 = "";
                while(json[i]!=',' && json[i]!=']'){
                    num1+=json[i];
                    i++;
                }
                lista2.push_back(atoi(num1.c_str()));
                i++;
            }
            lista1.push_back(lista2);
            if(json[i]==']'){
                break;  // HALT
            }
        }else {
            if(msg){
                while(json[i]!=','){
                    num1+=json[i];
                    i++;
                }
                result.setMensaje(num1);
                i+=15;
                mov = true;
            }else{
                i+=9;
                num1 ="";
                msg=true;
            }
        }
    }
    result.setGlad1(gladA);
    result.setGlad2(gladB);
    result.setMovimientos(lista1);
    return result;
}

void Sendable::setGlad1(int glad1[4]) {
    for(int i=0;i<4;i++){
        this->glad1[i] = glad1[i];
    }
}

void Sendable::setGlad2(int glad2[4]) {
    for(int i=0;i<4;i++){
        this->glad2[i] = glad2[i];
    }
}

void Sendable::clear() {

   for(int i=0;i<4;i++){
       glad1[i] = 0;
       glad2[i] = 0;
   }
   mensaje = "";
   movimientos = LinkedList<LinkedList<int>>();

};