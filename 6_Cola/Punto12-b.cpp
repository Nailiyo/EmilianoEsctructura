//Emiliano Aramayo, Juan Gaspar 2do Informatica.

#include <iostream>
#include <conio.h>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
    int datos;
    pnodo sig;
};

typedef struct tcola{

    pnodo frente;
    pnodo final;
    int cont;
};

void iniciar_cola(tcola &cola){
    //declaramos los punteros y contador
    cola.frente=NULL;
    cola.final=NULL;
    cola.cont=0;
    cout<<"cola iniciada! \n";
}

void crear_nodo(pnodo &nuevo){
    //creamos el nodo ._.
    nuevo=new tnodo;
    if(nuevo!=NULL){
        cout<<"digite un dato-> ";
        cin>>nuevo->datos;
        nuevo->sig=NULL;
        cout<<"nodo creado! \n";
    }
        else
            cout<<"Memoria llena! \n";
}

void agregar_cola(tcola &cola,pnodo nuevo){

    
    if(cola.cont==10){
        cout<<"cola llena! \n";
    }
    else {
        short int opcion2;
        //2 opciones la primera opcion agregamos el nodo en el frente de la cola
        cout<<"digite 1 para agregar al frente:\n"
            <<"digite 2 para agregar al final: \n";
            cin>>opcion2;
        if(opcion2==1){
        if(cola.frente==NULL && cola.final== NULL){
        nuevo->sig=cola.frente;
        cola.frente=nuevo;
        cola.final=nuevo;
        cola.cont++;
        }
        else{
            nuevo->sig=cola.frente;
            cola.frente=nuevo;
            cola.cont++;
        }
        cout<<"dato agregado! \n";
    }
    //opcion 2: agregamos el nodo al final de la cola
    else if(opcion2==2){
        if(cola.frente==NULL && cola.final==NULL){
            nuevo->sig=cola.final;
            cola.frente=nuevo;
            cola.final=nuevo;
            cola.cont++;
        }
        else{
            cola.final->sig=nuevo;
            cola.final=nuevo;
            cola.cont++;
        }
        cout<<"dato agregado! \n";
    }
    }
}

void quitar_cola(tcola &cola){
    pnodo quitar;
    if(cola.cont==0)
        cout<<"cola vacia! \n";
        else{
            //quitamos el frente de la cola
            if(cola.frente == cola.final){

                quitar=cola.frente;
                cola.frente=NULL;
                cola.final=NULL;
                cola.cont--;
                delete quitar;
            }
            else{
                quitar=cola.frente;
                cola.frente=cola.frente->sig;
                cola.cont--;
                delete quitar;
            }
            cout<<"dato quitado!\n";
        }
}

void mostrar_frente(tcola cola){
    if(cola.cont==0)
        cout<<"cola vacia! \n";
        else
    cout<<"el frente es->"<<cola.frente->datos;
}

void mostrar_final(tcola cola){
    if(cola.cont==0)
        cout<<"cola vacia! \n";
        else
    cout<<"el final es ->"<<cola.final->datos;
}

int main(){
    pnodo nuevo;
    tcola cola;
    short int opcion;
    do{

        // menu de opciones
            system("cls");
            cout<<"1-iniciar cola \n"
            <<"2- crear nodo\n"
            <<"3-agregar elemento a la cola \n"
            <<"4-quitar elemento a la cola \n"
            <<"5-mostrar frente de la cola \n"
            <<"6-mostrar final de la cola \n"
            <<"7- salir\n";
            
            cin>>opcion;
        
    switch(opcion){
        //logica del menu.
        case 1:
            iniciar_cola(cola);
            cout<<"cola iniciada! \n";
        break;

        case 2:
            crear_nodo(nuevo);
            getch();
        break;

        case 3:
            agregar_cola(cola,nuevo);
            getch();
        break;

        case 4:
            quitar_cola(cola);
            getch();
        break;

        case 5:
            mostrar_frente(cola);
            getch();
        break;

        case 6:
            mostrar_final(cola);
            getch();
        break;

        case 7:
            cout<<"gracias por ver :D";
        break;

    }
    }while(opcion!=7);
    return 0;
}