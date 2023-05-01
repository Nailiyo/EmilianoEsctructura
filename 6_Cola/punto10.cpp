#include <iostream>
#include <conio.h>
using namespace std;

const int MAX=15;
typedef int contenedor[MAX];
typedef struct tcola{

    contenedor datos;
    int cont;
    int frente;
    int final;

};

int siguiente(int indice){
    if(indice==15)
        return 0;
    else
        return (indice+1);
}

int anterior(int indice){
    if(indice==0)
        return 15;
    else
        return (indice-1);
}

void iniciar_cola(tcola &cola){

    cola.frente=0;
    cola.final=0;
    cola.cont=0;
}

bool cola_llena(tcola cola){
    return cola.cont==MAX;
}

bool cola_vacia(tcola cola){
    return cola.cont==0;
}

void agregar_cola(tcola &cola){
    if(cola_llena(cola)==true)
        cout<<"cola llena! \n";
    else{
        int opcion;
        cout<<"1-frente \n";
        cout<<"2-final \n";
        cin>>opcion;
        if(opcion==1){//agregar por el frente
            cin>>cola.datos[cola.frente];
            cola.frente=anterior(cola.frente);
            cola.cont++;
        }
        else{//agregar por el final
            cola.final=siguiente(cola.final);
            cin>>cola.datos[cola.final];
            cola.cont++;
        }
    }
}

void quitar_cola(tcola &cola){
    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";

    else{
        int aux;
        siguiente(cola.frente);
        aux=cola.datos[cola.frente];
        cola.cont--;
    }
}

void mostrar_frente(tcola cola){
    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    else
        cout<<cola.datos[siguiente(cola.frente)];
}

void mostrar_final(tcola cola){
    if(cola_vacia(cola)==true)
        cout<<"cola vacia!\n";
    else
        cout<<cola.datos[cola.final];
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