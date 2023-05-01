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
    int cont;
};

    void iniciar_lista(tlista &lista){

        lista.inicio=NULL;
        lista.cont=0;        
    }

    void crear_nodo(pnodo &nuevo){

        nuevo= new tnodo;
        if(nuevo != NULL){
            cout<<"digite un dato: "<<endl;
            cin>>nuevo->dato;
            nuevo->sig=NULL;
        }
        else
        cout<<"memoria llena \n";
    }
    void agregar_orden(tlista &lista, pnodo nuevo){

        pnodo aux=lista.inicio;
        if(lista.inicio == NULL){
            
            lista.inicio=nuevo;
            nuevo->sig=lista.inicio;
            lista.cont++;
        }
        else if(lista.cont == 1){
            if(nuevo->dato < (lista.inicio)->dato){

                nuevo->sig=lista.inicio;
                lista.inicio->sig=nuevo;
                lista.inicio=nuevo;
                lista.cont++;
            }
            else{

                lista.inicio->sig=nuevo;
                nuevo->sig=lista.inicio;
                lista.cont++;
            }

        }
        else{

            while(aux->sig != lista.inicio && (aux->sig)->dato < nuevo->dato){
                aux=aux->sig;

            }
            if(aux->sig == lista.inicio){

                nuevo->sig=lista.inicio;
                aux->sig=nuevo;
                lista.cont++;
            }
            else{
                nuevo->sig=(aux->sig)->sig;
                aux->sig=nuevo;
                lista.cont++;
            }
        }

    }

    void quitar_final(tlista &lista){

        pnodo aux=lista.inicio;
        if(lista.inicio == NULL)
            cout<<"lista vacia \n";

        else if(lista.cont == 1){

            delete lista.inicio;
            lista.inicio=NULL;
            lista.cont--;
        }
        else{

        while((aux->sig)->sig != lista.inicio){
            aux=aux->sig;
        }
            pnodo p=aux->sig;
            aux->sig=lista.inicio;
            p->sig=NULL;
            delete p;
            lista.cont--;
    }
}
    void mostrar_lista(tlista lista, pnodo auxfake){

        if(auxfake == NULL){
        cout<<"lista vacia \n";
        return;
        }

        if(auxfake->sig == lista.inicio){
            cout<<auxfake->dato;
            return;
        }
        else {
            cout<<auxfake->dato<<endl;
            mostrar_lista(lista,auxfake->sig);
        }
    }

int main(){
    tlista lista;
    pnodo nuevo;
    short int opcion;

    do{
        pnodo auxfake=lista.inicio;
        system("cls");
        if(lista.cont == 15){
            
            cout<<"tienes que quitar nodos no podemos agregar mas!! \n"
                <<"3-quitar final \n"
                <<"5-salir \n";
                cin>>opcion;

                if(opcion == 3)
                quitar_final(lista);

                if(opcion == 5)
                return 0;
        }
        else{
        cout<<"1-iniciar_lista \n"
            <<"2-agregar_orden \n"
            <<"3-quitar_final \n"
            <<"4-mostrar_lista \n"
            <<"5-salir \n";
            cin>>opcion;
            switch (opcion){

                case 1:
                system("cls");
                    iniciar_lista(lista);
                    cout<<"lista iniciada! \n";
                getch();
                break;

                case 2:
                system("cls");
                    crear_nodo(nuevo);
                    cout<<"nodo creado! \n";
                    agregar_orden(lista,nuevo);
                    cout<<"nodo agregado! \n";
                getch();
                break;

                case 3:
                system("cls");
                    quitar_final(lista);
                    cout<<"final quitado! \n";
                getch();
                break;

                case 4:
                system("cls");
                    mostrar_lista(lista,auxfake);
                getch();
                break;

                case 5:
                system("cls");
                    cout<<"gracias por ver :D";
                getch();
                break;

            }
        }
    }while(opcion != 5);
    return 0;
}