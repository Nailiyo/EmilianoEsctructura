#include <iostream>
#include <cstring>
using namespace std;
//pila: coleccion homogenea, sistema LIFO(el primero en entrar es el ultimo en salir).

const int MAX=20;
typedef char tcad[100];
typedef int contenedor[MAX];
typedef struct tpila{

    contenedor datos;
    int cima;
};



    void iniciar_pila(tpila &pila){

        pila.cima=-1;
    }

    bool pila_vacia(tpila pila){

        return pila.cima==-1;
    }

    bool pila_llena(tpila pila){

        return pila.cima==MAX-1;        
    }

    void agregar_pila(tpila &pila,tcad nuevo[]){

        if(pila_llena(pila)==true)
            cout<<"PILA LLENA! \n";
        else{
            cin>>pila.datos[pila.cima];
            cout<<"cima agregada! \n";
    }
    }
    int quitar_pila(tpila &pila){
            int aux;

            if(pila_vacia(pila)==true)
                return aux=100000;
            else{
            aux=pila.datos[pila.cima];
            pila.cima--;
            return aux;
            }
    }

    void mostrar_cima(tpila pila){

        if(pila_vacia(pila)==true)
            cout<<"pila vacia!";
        else
            cout<<"el ultimo dato es->"<<pila.datos[pila.cima];
    }



    bool parentizacion(tcad cadena){
    tpila p;
    bool correcta=true;
    iniciar_pila(p);
    for(int i=0;i<strlen(cadena) && correcta==true;i++){
        if(cadena[i] =='(')
            agregar_pila(p,cadena[i]);
            else{
                if(cadena[i]==')')
                    if(pila_vacia(p)==false)
                        quitar_pila(p);
                    else
                        correcta=false;
            }       
    }
    if(pila_vacia(p)==false)
        correcta=false;
        return correcta;
}

    int main(){
        tpila pila;
        int opcion;
        tcad aux;
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
                break;

                case 2:
                    agregar_pila(pila,aux);

                break;

                case 3:
                    quitar_pila(pila);
                break;

                case 4:
                    mostrar_cima(pila);
                break;

                case 5:
                cout<<"gracias por ver :D";
                break;
            }
        
    }while(opcion != 5);
    return 0;
}