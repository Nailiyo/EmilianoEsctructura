#include <iostream>
#include <conio.h>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{

    string dato;
    pnodo sig;
};

typedef struct tlista{

    pnodo inicio;
    pnodo final;
};

    void iniciar_lista(tlista &lista){

        lista.inicio=NULL;
        lista.final=NULL;
    }

    void crear_nodos(tlista &lista,pnodo nuevo,pnodo &aux){

        nuevo=new tnodo;
        lista.inicio=nuevo;
        nuevo->dato="Lunes";
        nuevo->sig=NULL;
        aux=lista.inicio;
        nuevo=new tnodo;
        nuevo->dato= "Martes";
        nuevo->sig=NULL;
        lista.inicio->sig=nuevo;
        nuevo=new tnodo;
        nuevo->dato= "Miercoles";
        nuevo->sig=NULL;
        (lista.inicio->sig)->sig=nuevo;
        nuevo=new tnodo;
        nuevo->dato= "Jueves";
        nuevo->sig=NULL;
        ((lista.inicio->sig)->sig)->sig=nuevo;
        nuevo=new tnodo;
        nuevo->dato= "Viernes";
        nuevo->sig=NULL;
        (((lista.inicio->sig)->sig)->sig)->sig=nuevo;
        nuevo=new tnodo;
        nuevo->dato= "Sabado";
        nuevo->sig=NULL;
        ((((lista.inicio->sig)->sig)->sig)->sig)->sig=nuevo;
        nuevo=new tnodo;
        nuevo->dato= "Domingo";
        (((((lista.inicio->sig)->sig)->sig)->sig)->sig)->sig=nuevo;
        lista.final=nuevo;
        nuevo->sig=lista.inicio;

    }
    void ordenar_lista(tlista &lista,pnodo &aux){

        string dia;
        cout<<"digite que dia quiere ordenar: \n";
        cin>>dia;
        while(lista.inicio->dato != dia){
            lista.inicio=lista.inicio->sig;
            lista.final=lista.final->sig;
        }

        if(lista.inicio->dato == dia)
            cout<<"lista ordenada! \n";
        
        else if(lista.inicio->sig == lista.final)
        cout<<"no existe el dia \n";
        aux=lista.inicio;
    }

    void mostrar_lista(tlista lista, pnodo aux){

        if(aux == NULL)
            cout<<"lista vacia! \n";

        else if(aux->sig == lista.inicio)
            cout<<aux->dato<<endl;

            else{
                cout<<aux->dato<<endl;
                mostrar_lista(lista,aux->sig);
            }
            
    }
    
int main(){
    int opcion;
    tlista lista;
    pnodo nuevo,aux;
    iniciar_lista(lista);
    do{
        system("cls");
        cout<<"1- crear lista \n"
            <<"2- ordenar lista a tu gusto \n"
            <<"3-mostrar lista \n"
            <<"4-salir \n";
            cin>>opcion;

            switch(opcion){

                case 1:
                system("cls");
                    crear_nodos(lista,nuevo,aux);
                    cout<<"lista creada! \n";
                getch();
                break;

                case 2:
                system("cls");
                    ordenar_lista(lista,aux);
                getch();
                break;

                case 3:
                system("cls");
                mostrar_lista( lista, aux);
                getch();
                break;
                
                case 4:
                system("cls");
                    cout<<"gracias por ver :D \n";
                getch();
                break;
            }

    }while(opcion != 4);
    return 0;
}