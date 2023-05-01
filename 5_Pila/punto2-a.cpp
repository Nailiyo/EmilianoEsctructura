#include <iostream>
#include <conio.h>
using namespace std;
const int MAX=20;
typedef int contenedor[MAX];

typedef struct tpila{

    contenedor datos;
};

void iniciar_pila(tpila &pila){

    pila.datos[MAX-MAX]=-1;
}

bool pila_llena(tpila pila){

    return pila.datos[MAX-MAX]==MAX-1;
}

bool pila_vacia(tpila pila){

    return pila.datos[MAX-MAX]==-1;
}

void cargar_pila(tpila &pila){

    if(pila_llena(pila)==true)
        cout<<"pila llena! \n";

    else{
        int nuevo;
        cout<<"digite un dato-> \n";
        cin>>nuevo;
            pila.datos[MAX-MAX]++;
            pila.datos[pila.datos[MAX-MAX]]=nuevo;  
    }
}

void quitar_cima(tpila &pila){

    if(pila_vacia(pila)==true)
        cout<<"pila vacia! \n";
    
    else{
        int aux;
        aux=pila.datos[pila.datos[MAX-MAX]];
        pila.datos[MAX-MAX]--;
    }
}

void mostar_cima(tpila pila){
    cout<<pila.datos[pila.datos[MAX-MAX]];
}


int main(){
tpila pila;
        int opcion;
    do{
        system("cls");
        
        cout<<"1-iniciar pila \n"
            <<"2-Agregar elemento a la pila \n"
            <<"3- quitar elemento de la pila \n"
            <<"4-consultar cima \n"
            <<"5- salir\n";
            cin>>opcion;
            switch(opcion){

                case 1:
                    iniciar_pila(pila);
                    cout<<"pila iniciada! \n";
                    getch();

                break;

                case 2:
                    cargar_pila(pila);
                    getch();

                break;

                case 3:
                    quitar_cima(pila);
                    getch();
                break;

                case 4:
                    mostar_cima(pila);
                    getch();
                break;

                case 5:
                cout<<"gracias por ver :D";
                break;
            }
        
    }while(opcion != 5);
    return 0;
    
}