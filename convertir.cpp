#include <iostream>
#include "convertir.h"

using namespace std;

bool operador(char op);
int precedencia_de_operadores(char op);

string Convertir::inf_a_pos(Pila<char> pila, string infija){
    for(size_t i=0; i < infija.length(); i++){
        //En caso de que lo que haya en la cadena pertenezca al alfabeto
        if((infija[i] >= 'a' && infija[i] <= 'z') || (infija[i] >= 'A' && infija[i] <= 'Z')){
            posfija += infija[i];//Se iran copiando los caracteres de la expresion infija a la expresion posfija
        }

        else if(infija[i] == '('){
            pila.push(infija[i]);//Si lo que hay en la expresion infija es un parentesis de apertura
                                //Lo agregamos a la pila
        }

        else if(infija[i] == ')'){
            while((pila.top() != '(') && (!pila.empty())){//Mientras el tope de la pila no sea igual a un parentesis
                                                        //de apertura y la pila no este vacia
                char temp = pila.top();//Mientras las condiciones sean verdaderas, 
                                        //se iran guardando los caracteres del tope de la pila en la variable temp
                posfija += temp;//Y los caracteres que se vayan guardando en temp, deberan irse copiando a la expresion posfija
                pila.pop();//Y vamos sacando los caracteres
            }
            if(pila.top() == '('){//Si en el tope de la pila hay un parentesis de apertura
                pila.pop();//Debemos sacarlo de esta
            }
        }

        else if(operador(infija[i])){//Mandamos la expresion infija a la funcion operador para evaluarla
            if(pila.empty()){//una vez evalua la los operadores de la pila, entra a este if
                pila.push(infija[i]);//donde evalua, si la pila esta vacia, entonces debemos agregar la expresion infija a esta
            }
            else{
                //Si la precedencia de los operadores en la exp. infija es mayor a la precedencia del tope de la pila
                if(precedencia_de_operadores(infija[i]) > precedencia_de_operadores(pila.top())){
                    pila.push(infija[i]);//Si se cumple la condicion, agregamos la expresion a la pila
                }
                //Si la precedencia de lo operadores en la exp. infija es igual al tope de la pila, quiere decir
                //que tienen la misma precedencia, porque pueden tener el mismo operador o pueden ser +,-,* o /
                else if((precedencia_de_operadores(infija[i]) == precedencia_de_operadores(pila.top())) 
                && (infija[i] == '^')){//Y tambien revisa si el operador en la expresion es el de potencia
                    pila.push(infija[i]);
                }
                else{
                    //Se recorre mientras la pila no este vacia y la precedencia de los operadores en la expresion
                    //sea menor o igual a la precedencia en el tope de la pila 
                    while((!pila.empty()) && (precedencia_de_operadores(infija[i]) <= precedencia_de_operadores(pila.top()))){
                        char temp = pila.top();//Copiamos lo que hay en el tope de la pila a una variable temporal
                        posfija += temp;//y despues vamos copiando lo que hay en esta variable temporal a la exp. posfija
                        pila.pop();//Y vamos vaciando la pila
                    }
                    pila.push(infija[i]);//Una vez salga del while, cuando una condicion deje de cumplirse , debemos volver a agregar la exp. infija a la pila
                }
            }
        }
    }

    //Este while solo ira agregando elementos del tope de la pila a la exp. posfija y sacando los operadores restantes de la pila
    while(!pila.empty()){
        posfija += pila.top();
        pila.pop();
    }

    return posfija;
}

//Funcion para determinar si el caracter que tenemos en la expresion infija es un operador
bool operador(char op){
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^'){
        return true;
    }
    else{
        return false;
    }
}

//Funcion para evaluar cual de los operadores tiene mayor precedencia en la expresion infija
int precedencia_de_operadores(char op){
    if(op == '^'){//Mayor precedencia
        return 3;
    }
    else if(op == '*' || op == '/'){//Menos precedencia que el ^
        return 2;
    }
    else if(op == '+' || op == '-'){//Los que menos precedencia tienen
        return 1;
    }
    else{
        return -1;//Si tenemos un '(' ó ')'
    }
}