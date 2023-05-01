#include <iostream>
#include <conio.h>
using namespace std;
const int MAX=8;
typedef int contenedor[MAX];

typedef struct tpila{

    contenedor datos1;
    contenedor datos2;
};

void iniciar_pila(tpila &pila){

    pila.datos1[MAX-1]=-1;
}

bool pila_llena(tpila pila){

    return pila.datos1[MAX-1]==MAX*2;
}

bool pila_vacia(tpila pila){

    return pila.datos1[MAX-1]==-1;
}

void cargar_pila(tpila &pila){

    if(pila_llena(pila)==true)
        cout<<"pila llena! \n";

    else{
        int nuevo;
        cout<<"digite un dato-> \n";
        cin>>nuevo;
        pila.datos1[MAX-1]++;

        if(pila.datos1[MAX-1] < MAX-1){

            cout<<"PILA 1 \n";
            pila.datos1[pila.datos1[MAX-1]]=nuevo;
            
        }
        else if(pila.datos1[MAX-1]==7)
            pila.datos1[MAX-1]++;
        else{
            cout<<"PILA 2 \n";
            pila.datos2[pila.datos1[MAX-1]-MAX]=nuevo;
        }
    }
}

void quitar_cima(tpila &pila){

    if(pila_vacia(pila)==true)
        cout<<"pila vacia! \n";
    else{
        int aux;
        if(pila.datos1[MAX-1] < 7){
            aux=pila.datos1[pila.datos1[MAX-1]];
            pila.datos1[MAX-1]--;
        }
        else{
            if(pila.datos1[MAX-1]== MAX-1)
                pila.datos1[MAX-1]--;
                else{
                    aux=pila.datos2[pila.datos1[MAX-1]-MAX-1];
                    pila.datos1[MAX-1]--;
                }
        }
        
    }
}
void mostrar_cima(tpila pila){

    if(pila_vacia(pila)==true)
        cout<<"pila vacia! \n";
        else{
            if(pila.datos1[MAX-1] < 7){
                cout<<pila.datos1[pila.datos1[MAX-1]];
            }
            else if(pila.datos1[MAX-1]==MAX-1)
                cout<<pila.datos1[pila.datos1[MAX-1]-1];
            else
                cout<<pila.datos2[pila.datos1[MAX-1]-MAX];
        }
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
                    mostrar_cima(pila);
                    getch();
                break;

                case 5:
                cout<<"gracias por ver :D";
                break;
            }
        
    }while(opcion != 5);
    return 0;
    
}