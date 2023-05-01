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
};

    void iniciar_lista(tlista &lista){

        lista.inicio=NULL;
        lista.final=NULL;
    }

    void crear_nodo(pnodo &nuevo){

        nuevo = new tnodo;
        if (nuevo != NULL){
            cout<<"digite un dato!: \n";
            cin>>nuevo->dato;
            nuevo->sig=NULL;
        }
        else 
            cout<<"memoria llena! \n";
    }

    void aniadir_final (tlista &lista, pnodo nuevo,pnodo aux){

        if(lista.inicio == NULL && lista.final == NULL){

            lista.inicio=nuevo;
            lista.final=nuevo;
        }
        else if(lista.inicio == lista.final){

            lista.final->sig=nuevo;
            lista.final=nuevo;
        }
        else if(aux->sig == lista.final){

            lista.final->sig=nuevo;
            lista.final=nuevo;
        }
        else{
            aniadir_final(lista,nuevo,aux->sig);
        }
    }

    void quitar_final(tlista &lista, pnodo aux){

        if(lista.inicio == NULL && lista.final == NULL)
        cout<<"lista vacia! \n";

        else if(aux == lista.final){

            delete aux;
            lista.inicio=NULL;
            lista.final=NULL;
        }
        else if(aux->sig == lista.final){

            delete lista.final;
            lista.final=aux;
            lista.final->sig=NULL;
        }
        else
            quitar_final(lista, aux->sig);

    }

    void mostrar_lista(pnodo aux){

        if(aux  == NULL )
        cout<<"lista vacia \n";

        else if(aux->sig == NULL)
            cout<<aux->dato<<endl;
        
        else {

            cout<<aux->dato<<endl;
            mostrar_lista(aux->sig);
        }
        
    }

int main(){
    tlista lista;
    int opcion;
    pnodo nuevo;
    iniciar_lista(lista);

    do{
        system("cls");
        pnodo aux=lista.inicio;
        cout<<"1-agregar final \n"
            <<"2-quitar final \n"
            <<"3-mostrar lista \n"
            <<"4-salir \n";
            cin>>opcion;

            switch(opcion){

                case 1:
                system ("cls");
                    crear_nodo(nuevo);
                    cout<<"nodo creado! \n";
                    aniadir_final(lista,nuevo,aux);
                    cout<<"final agregado! \n";
                getch();
                break;

                case 2:
                system ("cls");
                    quitar_final(lista,aux);
                    cout<<"final quitado! \n";
                getch();
                break;

                case 3:
                system ("cls");
                    mostrar_lista(lista.inicio);
                getch();
                break;

                case 4:
                system ("cls");
                    cout<<"gracias por ver :D!";
                getch();
                break;

            }
    }while(opcion != 4);

    return 0;
}