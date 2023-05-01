#include <iostream>
#include <conio.h>
using namespace std;

const int MAX=5;

typedef int contenedor[MAX];

typedef struct tpila{
    contenedor datos1;
    contenedor datos2;
    contenedor datos3;
    int cima;

};

void iniciar_pila(tpila &pila){

    pila.cima=0;
}

bool pila_llena(tpila pila){

    return (pila.cima-2*MAX)-1==MAX-1;
}

bool pila_vacia(tpila pila){

    return pila.cima==0;
}

void cargar_pila(tpila &pila){

    if(pila_llena(pila)==true)
        cout<<"pila llena! \n";

    else{
        int nuevo;
        cout<<"digite un dato! \n";
        cin>>nuevo;

        if(pila.cima<MAX){
            pila.datos1[pila.cima]=nuevo;
            pila.cima++;
        }
        
        else if(pila.cima>=MAX && pila.cima<2*MAX){
            pila.datos2[pila.cima-MAX]=nuevo;
            pila.cima++;
        }
        
        else{
            pila.datos3[pila.cima-2*MAX]=nuevo;
            pila.cima++;
        }
    }
}
void quitar_cima(tpila &pila){

    if(pila_vacia(pila)==true)
        cout<<"pila vacia! \n";

    else{
        int aux;
        if(pila.cima<5){
            pila.cima--;
            aux=pila.datos1[pila.cima];
        }
        else if(pila.cima>=5 && pila.cima<10){
            pila.cima--;  
            aux=pila.datos2[pila.cima-MAX];
        }
        else{
            pila.cima--;
            aux=pila.datos3[pila.cima-2*MAX];
        }
        cout<<"pila quitada! \n";
    }
}

void mostar_cima(tpila pila){

    if(pila.cima<5)
        cout<<pila.datos1[pila.cima-1];

    else if(pila.cima>=5 && pila.cima<10)
        cout<<pila.datos2[pila.cima-MAX-1];

    else
        cout<<pila.datos3[pila.cima-2*MAX-1];
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