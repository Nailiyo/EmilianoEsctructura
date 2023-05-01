#include <iostream>
#include <conio.h>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{

    int dato;
    pnodo sig;
};

typedef struct tlista{

    pnodo inicio;
    pnodo final;
    int cont;
};

    void iniciar_lista(tlista &lista){

        lista.inicio=NULL;
        lista.final=NULL;
        lista.cont=0;
    }

    void crear_nodo(pnodo &nuevo){

        nuevo = new tnodo;

        if( nuevo != NULL){
            cout<<"digite un dato: \n";
            cin>>nuevo->dato;
            nuevo->sig=NULL;
        }
        else
        cout<<"memoria llena! \n";
    }

    void agregar_nodo(tlista &lista, pnodo nuevo){
        
        pnodo aux=lista.inicio;

        if(lista.inicio == NULL && lista.final == NULL){

            lista.inicio=nuevo;
            lista.final=nuevo;
            lista.final->sig=lista.inicio;
            lista.cont++;
        }
        
        else if(lista.inicio->dato > nuevo->dato){

            nuevo->sig=lista.inicio;
            lista.inicio=nuevo;
            lista.final->sig=nuevo;
            lista.cont++;
        }
        else if (lista.final->dato < nuevo->dato){

            lista.final->sig=nuevo;
            lista.final=nuevo;
            lista.final->sig=lista.inicio;
            lista.cont++;
        }

        else{

            for(aux=lista.inicio;nuevo->dato > (aux->sig)->dato; aux=aux->sig);

                nuevo->sig=aux->sig;
                aux->sig=nuevo;
                lista.cont++;
            
           
        }
    }

    void quitar_mayor(tlista &lista){

        if(lista.inicio == NULL && lista.final == NULL)
        cout<<"lista vacia! \n";

        else if(lista.inicio->sig == lista.inicio){
            delete lista.inicio;
            delete lista.final;
            lista.cont--;
            lista.inicio=NULL;
            lista.final=NULL;
            
        }
        else{
        pnodo aux;
            for(aux=lista.inicio; aux->sig != lista.final;aux=aux->sig);

            delete lista.final;
            aux->sig=lista.inicio;
            lista.final=aux;
            lista.cont--;
        }
    }

    void mostrar_lista(pnodo aux,pnodo aux1){

        if(aux == NULL)
        cout<<"lista vacia! \n";
        else if(aux->sig == aux1)
        cout<<aux->dato<<endl;
        else{
            cout<<aux->dato<<endl;
            mostrar_lista(aux->sig,aux1);
        }
    }

int main(){

tlista lista;
pnodo nuevo;
int opcion;

    do{
        pnodo aux1=lista.inicio;
        system("cls");

        if(lista.cont==15){
            cout<<"espacio lleno libere! \n"
                <<"1-quitar final \n"
                <<"2-salir \n";
                cin>>opcion;
                switch (opcion)
                {
                case 1:
                system("cls");
                    quitar_mayor(lista);
                    cout<<"mayor quitado! \n";
                getch();
                    break;
                
                case 2:
                    cout<<"gracias por ver :D! \n";
                    return 0;
                    break;
                }
        }

        cout<<"1-iniciar_lista \n"
            <<"2-agregar_orden \n"
            <<"3-quitar_mayor \n"
            <<"4-mostrar_lista. \n"
            <<"5-salir \n";
            cin>>opcion;

    switch(opcion){

        case 1:
        system("cls");
            iniciar_lista(lista);
            cout<<"lista creada! \n";
        getch();
        break;

        case 2:
        system("cls");
            crear_nodo(nuevo);
            cout<<"nodo creado! \n";
            agregar_nodo(lista,nuevo);
            cout<<"nodo en lista! \n";
        getch();
        break;

        case 3:
        system("cls");
            quitar_mayor(lista);
            cout<<"mayor quitado! \n";
        getch();
        break;

        case 4:
        system("cls");
            mostrar_lista(lista.inicio,aux1);
        getch();
        break;

        case 5:
        system("cls");
        cout<<"gracias por ver :D! \n";
        getch();
        break;
    }
    }while(opcion != 5);
    return 0;
}