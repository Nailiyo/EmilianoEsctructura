#include <iostream>
#include <conio.h>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{

    int dato;
    pnodo sig;
    pnodo ant;
};

    void iniciar_lista(pnodo &lista){

        lista=NULL;
    }

    void crear_nodo(pnodo &nuevo){

        nuevo = new tnodo;
        if(nuevo != NULL){
            cout<<"digite un dato: \n";
            cin>>nuevo->dato;
            nuevo->sig=NULL;
            nuevo->ant=NULL;
            cout<<"nodo creado! \n";
        }
        else
            cout<<"memoria llena! \n";
    }

    void agregar_orden(pnodo &lista, pnodo nuevo){

        crear_nodo(nuevo);
        pnodo aux=lista;

        if(lista == NULL){

            lista=nuevo;
            lista->sig=lista;
            lista->ant=lista;
        }
        else if(lista->sig == lista && lista->ant == lista){

            if(lista->dato > nuevo->dato){

                lista->ant=nuevo;
                lista->sig=nuevo;
                nuevo->sig=lista;
                nuevo->ant=lista;
                lista=nuevo;
            }
            else{

                lista->sig=nuevo;
                lista->ant=nuevo;
                nuevo->sig=lista;
                nuevo->ant=lista;
            }
        }
        else if(lista->dato > nuevo->dato){
            for(aux=lista;aux->sig != lista;aux=aux->sig);

            nuevo->sig=lista;
            lista->ant=nuevo;
            lista=nuevo;
            lista->ant=aux;
            aux->sig=lista;
        }
        else{
            for(aux=lista;(aux->sig)->dato < nuevo->dato && aux->sig != lista;aux=aux->sig);

            if(aux->sig == lista){

                aux->sig=nuevo;
                nuevo->ant=aux;
                nuevo->sig=lista;
                lista->ant=nuevo;
            }
            else{
                nuevo->sig=aux->sig;
                nuevo->ant=aux;
                (aux->sig)->ant=nuevo;
                aux->sig=nuevo;
            }
        }
    }

    void quitar_valor(pnodo &lista){

        int quitar;
        pnodo aux;
        cout<<"digite el valor a quitar: \n";
        cin>>quitar;

        if(lista == NULL)
            cout<<"lista vacia! \n";

        else if(lista->sig == lista && lista->ant == lista){

            if(lista->dato == quitar){
                delete lista;
                lista=NULL;
            }
            else 
                cout<<"dato no existente! \n";
        }
        else if(lista->dato == quitar){

            pnodo p=lista;
            for(aux=lista;aux->sig != lista;aux=aux->sig);

            lista=lista->sig;
            lista->ant=aux;
            aux->sig=lista;
            p->sig=NULL;
            p->ant=NULL;
            delete p;
        }
        else{
            for(aux=lista;(aux->sig)->dato != quitar && aux->sig != lista;aux=aux->sig);

                if(aux->sig == lista)
                    cout<<"dato no encontrado! \n";

                else{
                    pnodo p=aux->sig;
                    aux->sig=(aux->sig)->sig;
                    (aux->sig)->ant=aux;
                    p->sig=NULL;
                    p->ant=NULL;
                    delete p;
                }    
        }
    }

    void mostrar_valor(pnodo lista, pnodo aux1, int buscar){

        if(lista == NULL)
            cout<<"lista vacia! \n";

        else if(lista->sig == lista && lista->ant==lista){

            if(lista->dato == buscar)
                cout<<"dato encontrado!, es: "<<buscar<<endl;
            else
                cout<<"dato no encontrado! "<<endl;
        }
        else if(aux1->dato == buscar)
            cout<<"dato encontrado!, es:  "<<buscar<<endl;

        else if(aux1->sig == lista)
            cout<<"dato no encontrado! \n";
        else
            mostrar_valor(lista,aux1->sig,buscar);
            
    }

    void mostrar_lista(pnodo lista,pnodo aux1){

        if(aux1 == NULL)
            cout<<"lista vacia! \n";
        
        else if(aux1->sig == lista)
            cout<<aux1->dato<<endl;
        
        else{
            cout<<aux1->dato<<endl;
            mostrar_lista(lista, aux1->sig);
        }
    }

int main(){

pnodo lista;
pnodo nuevo;
int opcion,buscar;
    do{
        system("cls");
        pnodo aux1=lista;
        cout<<"1-iniciar lista \n"
            <<"2-agregar orden \n"
            <<"3-quitar valor \n"
            <<"4-buscar valor \n"
            <<"5-mostrar lista \n"
            <<"6-salir \n";
            cin>>opcion;
        
    switch(opcion){

        case 1:
        system("cls");
            iniciar_lista(lista);
            cout<<"lista iniciada! \n";
        getch();
        break;

        case 2:
        system("cls");
            agregar_orden(lista,nuevo);
            cout<<"nodo agregado! \n";
        getch();
        break;
        
        case 3:
        system("cls");
            quitar_valor(lista);
        getch();
        break;
        
        case 4:
        system("cls");
            cout<<"digite el dato a buscar: \n";
            cin>>buscar;
            mostrar_valor(lista,aux1,buscar);
        getch();
        break;
        
        case 5:
            system("cls");
                mostrar_lista(lista,aux1);
            getch();
        break;

        case 6:
        system("cls");
            cout<<"gracias por ver! \n";
        getch();
        break;
    }
    }while(opcion != 6);

    return 0;
}