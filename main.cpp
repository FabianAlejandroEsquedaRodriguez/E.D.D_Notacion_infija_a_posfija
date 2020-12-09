#include <iostream>
#include "convertir.h"

using namespace std;

int main(){
    size_t opc;
    string inf, pos;
    Pila<char> p;
    Convertir c;

    cout << "La expresion en infija solo debe contener:" << endl;
    cout << "1 -> Caracteres alfabeticos individuales entre los operadores" << endl;
    cout << "2 -> Operadores aritmeticos basicos: + - * /" << endl;
    cout << "3) Parentesis, pueden ser con anidamientos" << endl;

    do{

    cout <<"\nEXPRESION INFIJA: "<<endl;
    getline(cin, inf); 
    
    cout<<endl<<"CADENA EN NOTACION INFIJA: "<<inf<<endl;

    pos = c.inf_a_pos(p, inf);

    cout<<endl<<"CADENA EN NOTACION POSFIJA: "<<pos<<endl<<endl;

    cout<<endl<<endl<<"Deseas hacer otra conversion (0/1): ";
    cin>>opc;
    cin.ignore();
    cout<<endl;

    }while(opc != 0);


    return 0;
}