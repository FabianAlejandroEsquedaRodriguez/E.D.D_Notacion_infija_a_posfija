#ifndef CONVERTIR_H
#define CONVERTIR_H

#include<iostream>
#include "pila.h"

using namespace std;

class Convertir{
    public:
    Convertir(){
        posfija = "";
    }
    string inf_a_pos(Pila<char> pila, string infija);

    private:
    string posfija;
};

#endif