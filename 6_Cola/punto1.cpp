/*#include <iostream>
#include <conio.h>
using namespace std;

const int MAX=5;
typedef int contenedor[MAX];
typedef struct tcola{

    contenedor datos;
    int frente;
    int final;
};

int siguiente(int indice){

    if(indice == MAX-1)
        return 0;
    else
        return (indice+1);
}

int anterior(int indice){
    
    if(indice==0)
        return MAX-1;
    else
        return (indice-1);
}

void iniciar_cola(tcola &cola){

    cola.frente=MAX-1;
    cola.final=MAX-1;
}

bool cola_vacia(tcola cola){
    return cola.final==cola.frente;
}

bool cola_llena(tcola cola){
    return (siguiente(cola.final))==cola.frente;
}

void agregar_cola(tcola &cola){

    if(cola_llena(cola)==true)
        cout<<"cola llena! \n";
    else{
        cout<<"ingrese un dato\n";
        int nuevo; cin>>nuevo;
        cola.final=siguiente(cola.final);
        cola.datos[cola.final]=nuevo;
    }
}

void quitar_cola(tcola &cola){

    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    else{
        int aux;
        cola.frente=siguiente(cola.frente);
        aux=cola.datos[cola.frente];
    }
}

void mostrar_frente(tcola cola){
    if(cola_vacia(cola)==true)
        cout<<"cola vacia! \n";
    else{
        cout<<cola.datos[siguiente(cola.frente)];
    }
}

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
}priorizando velocidad*/
#include <iostream>
#include <conio.h>
using namespace std;
const int MAX=5;
typedef int contenedor[MAX];
typedef struct tcola{
    contenedor datos;
    int final;
    int frente;
    int cont;
};

    void iniciar_cola(tcola &cola){
        cola.frente=MAX-1;
        cola.final=MAX-1;
        cola.cont=0;
    }

    bool cola_vacia(int indice){
        return indice==0;
    }

    bool cola_llena(int indice){
        return indice==5;
    }
    int siguiente(int indice){
        if(indice==MAX-1)
            return 0;
        else
            return indice+1;
    }

    void agregar_cola(tcola &cola){

        if(cola_llena(cola.cont)==true)
            cout<<"cola llena! \n";
        else{
            cout<<"digite un dato-> \n";
            cola.final=siguiente(cola.final);
            cin>>cola.datos[cola.final];
            cola.cont++;
        }
    }

    void quitar_cola(tcola &cola){

        if(cola_vacia(cola.cont)== true)
            cout<<"cola vacia! \n";
        else{
            int aux;
            cola.cont--;
            cola.frente=siguiente(cola.frente);
            aux=cola.datos[cola.frente];
        }
}

    void mostrar_frente(tcola cola){
        if(cola_vacia(cola.cont)==true)
            cout<<"cola vacia!\n";
        else
            cout<<cola.datos[siguiente(cola.frente)];
    }

    void mostrar_final(tcola cola){
        if(cola_vacia(cola.cont)==true)
            cout<<"cola vacia! \n";
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