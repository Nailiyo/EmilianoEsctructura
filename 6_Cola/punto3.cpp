#include <iostream>
#include <conio.h>
using namespace std;

const int MAX=10;

typedef int contenedor[MAX];
typedef struct tcola{

    contenedor datos1;
    contenedor datos2;
};

void iniciar_cola(tcola &cola){

    cola.datos1[0]=12;
    cola.datos1[1]=12;
}

int siguiente(int indice){

    if(indice==2*MAX-1)
        return 2;      
    else
        return (indice+1);
}

bool cola_vacia(tcola cola){
    return cola.datos1[0]==cola.datos1[1];
}

bool cola_llena(tcola cola){
    return cola.datos1[0]==siguiente(cola.datos1[1]);
}

void agregar_cola(tcola &cola){

    if(cola_llena(cola)==true)
        cout<<"cola llena! \n";

        else{
            cout<<"digite un dato-> \n";
                cola.datos1[1]=siguiente(cola.datos1[1]);

            if(cola.datos1[1] < MAX)
                cin>>cola.datos1[cola.datos1[1]];

            else
                cin>>cola.datos2[cola.datos1[1]-MAX];          
        }
}
void quitar_cola(tcola &cola){

    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    
    else{
        int aux;
        cola.datos1[0]=siguiente(cola.datos1[0]);

        if(cola.datos1[0] < MAX)
            aux=cola.datos1[cola.datos1[0]];
        else
            aux=cola.datos2[cola.datos1[0]-MAX];
}
}

void mostrar_frente(tcola cola){

    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    else
        {
            cola.datos1[0]=siguiente(cola.datos1[0]);

            if(cola.datos1[0] < MAX)
                cout<<cola.datos1[cola.datos1[0]];
            else
                cout<<cola.datos2[cola.datos1[0]-MAX];
        }
}

void mostrar_final(tcola cola){

    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    else
        {
            if(cola.datos1[1] < MAX)
                cout<<cola.datos1[cola.datos1[1]];
            else
                cout<<cola.datos2[cola.datos1[1]-MAX];
        }
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