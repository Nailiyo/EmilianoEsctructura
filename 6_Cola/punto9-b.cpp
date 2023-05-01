//Emiliano Aramayo, Juan Gaspar 2do Informatica

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

    cola.frente=NULL;
    cola.final=NULL;
}

void crear_nodo(pnodo &nuevo,int dato){

    nuevo=new tnodo;
    if(nuevo!=NULL){
        nuevo->datos=dato;
        nuevo->sig=NULL;
    }
        else
            cout<<"Memoria llena! \n";
}
//agregamos el elemento al final de la cola. 
void agregar_cola(tcola &cola,int dato){
    pnodo nuevo;
    crear_nodo(nuevo,dato);
    if(cola.cont==10){
        cout<<"cola llena! \n";
    }
    else {
       if(cola.frente == NULL && cola.final== NULL){
            nuevo->sig=cola.frente;
            cola.final=nuevo;
            cola.frente=nuevo;
            cola.cont++;
       }
       else{
        nuevo->sig=cola.frente;
        cola.final->sig=nuevo;
        cola.final=nuevo;
        cola.cont++;
       }
    }
}
//quitamos el frente de la cola
int quitar_cola(tcola &cola){
    int quitar;
    if(cola.frente==NULL && cola.final==NULL){
        quitar=-1;
        return (quitar);
    }
        else{
            if(cola.frente == cola.final){

                quitar=cola.frente->datos;
                cola.frente=NULL;
                cola.final=NULL;
                cola.cont--;
                return (quitar);
            }
            else{
                quitar=cola.frente->datos;
                cola.frente=cola.frente->sig;
                cola.final->sig=cola.frente;
                cola.cont--;
                return (quitar);
            }
        }
}

int mostrar_frente(tcola cola){
    
    int consultar;
    if(cola.frente==NULL && cola.final==NULL)
        consultar=-1;
    else
        consultar=cola.frente->datos;
        return (consultar);
}

int fibo(int num){

    tcola cola;
    int t3,t;
    iniciar_cola(cola);
    if(num ==1 || num==2)
        t3=1;
        else{
            t=3;
            agregar_cola(cola,1);
            agregar_cola(cola,1);
            while(t<num){
                t3=quitar_cola(cola)+mostrar_frente(cola);
                agregar_cola(cola,t3);
                t++;
            }
            t3=quitar_cola(cola)+quitar_cola(cola);
        }
        return t3;
}
int main(){
    
int num;
    cout<<"ingrese un numero-> ";
    cin>>num;
        cout<<"\ntermino fibo: "<<num<<"es: "<<fibo(num);

    return 0;
}