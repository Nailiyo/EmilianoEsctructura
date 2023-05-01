#include <iostream>
#include <conio.h>
using namespace std;

const int MAX=20;
typedef int contenedor[MAX];

//estructura de la cola.
typedef struct tcola{

    contenedor datos;
    int frente;
    int final;
};

//funcion muy importante para determinar el siguiente de los 2 punteros.
int siguiente(int indice){
    //indicamos si el indice esta en el ultimo elemento retornamos a cero para hacer circular.
    if(indice == MAX-1)
        return 0;
    
    //si el indice no esta en el ultimo elemento simplemente sumamos 1.
    else
        return (indice+1);
    
}

//booleano para saber si la cola esta vacia
bool cola_vacia(tcola cola){

    return cola.frente==cola.final;
}

//booleano para returnar si la cola esta llena
bool cola_llena(tcola cola){

    return (siguiente(cola.final)==cola.frente);
}

//iniciamos la cola(podriamos hacer esto directamente desde el struct pero bueno)
//quien soy yo para discutir al jefe de catedra
void iniciar_cola(tcola &cola){

    cola.frente=MAX-1;
    cola.final=MAX-1;    
}
//agregamos la cola en el final porque utilizamos el sistema FIFO.
void agregar_cola(tcola &cola, int nuevo){

    if(cola_llena(cola)==true)
        cout<<"cola llena! \n";
        else{

            cout<<"digite un  dato-> ";
            cin>>nuevo;

            cola.final=siguiente(cola.final);
            cola.datos[cola.final]=nuevo;
        }
}

//quitar el frente de la cola porque utilizamos el sistema FIFO.
void quitar_cola(tcola &cola){
    int aux;
    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    else{

        cola.frente=siguiente(cola.frente);
        aux=cola.datos[cola.frente];

    }
}

//operaciones fundamentales para mostrar el frente de la cola.
void mostrar_frente(tcola cola){

    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    else
        cout<<cola.datos[siguiente(cola.frente)];
}

//operaciones fundamentales para mostrar el final de la cola.
void mostrar_final(tcola cola){

    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    else{
        cout<<cola.datos[cola.final];
    }
}
int main(){

tcola cola;
short int opcion;
int nuevo;
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
            agregar_cola(cola,nuevo);
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