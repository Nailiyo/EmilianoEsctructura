#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int MAX=5;
typedef string contenedor[MAX];
typedef struct tpila{
    contenedor datos;
    int cima;
};

void inciar_pila(tpila &pila){
    pila.cima=-1;
}

bool pila_llena(tpila pila){
    return pila.cima==MAX-1;
}

bool pila_vacia(tpila pila){
    return pila.cima==-1;
}

void recorrer_cadena(string &nuevo){
    
    for(int i=0;'\000'!=nuevo[i];i++){
        if(nuevo[i]== '+' || nuevo[i] == '-'){

        }

    }
}

void agregar_pila(tpila &pila){

    if(pila_llena(pila)==true)
        cout<<"pila_llena! \n";
    else{
        string nuevo;
        cout<<"digite la cadena de caracteres-> \n";
        cin>>nuevo;
        
    }
}



int main(){
    
    
    return 0;
}