#include <iostream>
#include <conio.h>
using namespace std;

typedef struct tpila *pnodo;

typedef struct tpila{

    pnodo sig;
    pnodo ant;
    int dato;
};

typedef struct tlista{

    pnodo cima;
};

void iniciar_pila(tlista &lista){

    lista.cima=NULL;
}

void crear_dato(pnodo &nuevo){

    nuevo=new tpila;
    if(nuevo == NULL)
        cout<<"memoria llena! \n";
        else{
            cout<<"digite un dato -> ";
                cin>>nuevo->dato;
                nuevo->sig=NULL;
                nuevo->ant=NULL;
        }
}

bool pila_vacia(tlista lista){

    return lista.cima == NULL;
}

void agregar_cima(pnodo nuevo, tlista &lista){
    crear_dato(nuevo);

    if(lista.cima == NULL){
        lista.cima=nuevo;
    }
    else{
        lista.cima->sig=nuevo;
        nuevo->ant=lista.cima;
        lista.cima=nuevo;
    }
    cout<<"cima agregada! \n";
}

    void quitar_cima(tlista &lista){
        pnodo aux;

        if(pila_vacia(lista) == true)
            cout<<"PILA VACIA! \n";

        else if(lista.cima->ant == NULL){
            aux=lista.cima;
            lista.cima=NULL;
            delete aux;
            cout<<"cima quitada! \n";
        }
        else{
            aux=lista.cima;
            lista.cima=lista.cima->ant;
            lista.cima->sig=NULL;
            delete aux;
            cout<<"CIMA QUITADA! \n";
        }
    }

    void mostrar_cima(tlista lista){
        if(lista.cima == NULL)
            cout<<"pila vacia! \n";
        else
        cout<<"la cima es ->"<<lista.cima->dato;

    }

int main(){

    tpila pila; pnodo nuevo; tlista lista;
    int opcion;
    do{
        // menu de opciones
            system("cls");
            cout<<"1-iniciar pila \n"
            <<"2-Agregar elemento a la pila \n"
            <<"3- quitar elemento de la pila \n"
            <<"4-consultar cima \n"
            <<"5- salir\n";
            cin>>opcion;
        
    switch(opcion){
        //logica del menu.
        case 1:
            iniciar_pila(lista);
            getch();
        break;

        case 2:
            agregar_cima(nuevo, lista);
            getch();
        break;

        case 3:
            quitar_cima(lista);
            getch();
        break;

        case 4:
            mostrar_cima(lista);
            getch();
        break;

        case 5:
            cout<<"gracias por ver :D";
        break;

    }
    }
    while(opcion!= 5);
    return 0;
}
