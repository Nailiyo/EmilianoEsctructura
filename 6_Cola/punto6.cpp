#include <iostream>
#include <conio.h>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{

    int dato;
    pnodo sig;
    pnodo ant;
};

typedef struct tcola{

    pnodo frente;
    pnodo final;
    int cont;
};

void iniciar_cola(tcola &cola){

    cola.final=NULL;
    cola.frente=NULL;
    cola.cont=0;
}

bool cola_llena(tcola cola){
    return cola.cont==20;
}

bool cola_vacia(tcola cola){
    return cola.cont==0;
}

void crear_nodo(pnodo &nuevo){

    nuevo=new tnodo;
        if(nuevo != NULL){
            cout<<"digite un dato-> \n";
            cin>>nuevo->dato;
            nuevo->sig=NULL;
            nuevo->ant=NULL;
        }
        else 
            cout<<"MEMORIA LLENA! \n";
}

void agregar_cola(tcola &cola){
    pnodo nuevo;
    crear_nodo(nuevo);
    if(cola_llena(cola)==true)
        cout<<"cola llena! \n";
    else{
            if(cola.cont==0){
                cola.frente=nuevo;
                cola.final=nuevo;
                cola.cont++;
            }
            else{
                cola.final->sig=nuevo;
                nuevo->ant=cola.final;
                cola.final=nuevo;
                cola.cont++;
            }
    }
}

void quitar_cola(tcola &cola){

    pnodo aux;

    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";

    else{
        if(cola.cont==1){
            aux=cola.frente;
            cola.frente=NULL;
            cola.final=NULL;
            cola.cont--;
        }
        else{
            aux=cola.frente;
            cola.frente=cola.frente->sig;
            cola.frente->ant=NULL;
            cola.cont--;
        }
        delete aux;
    }
}

void mostrar_frente(tcola cola){

    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";

        else
            cout<<cola.frente->dato;
}

void mostrar_final(tcola cola){
    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    else
        cout<<cola.final->dato;
}

int main(){

tcola cola;
short int opcion;
    do{

        // menu de opciones
            system("cls");
            cout<<"1-iniciar cola \n"
            <<"2-agregar elemento a la cola \n"
            <<"3-quitar elemento a la cola \n"
            <<"4-mostrar frente de la cola \n"
            <<"5-mostrar final de la cola \n"
            <<"6- salir\n";
            
            cin>>opcion;
        
    switch(opcion){
        //logica del menu.
        case 1:
            iniciar_cola(cola);
            cout<<"cola iniciada! \n";
        break;

        case 2:
            agregar_cola(cola);
            cout<<"dato agregado! \n";
            getch();
        break;

        case 3:
            quitar_cola(cola);
            cout<<"dato quitado! \n";
            getch();
        break;

        case 4:
            mostrar_frente(cola);
            getch();
        break;

        case 5:
            mostrar_final(cola);
            getch();
        break;

        case 6:
            cout<<"gracias por ver :D";
        break;

    }
    }while(opcion!=6);

    return 0;
}