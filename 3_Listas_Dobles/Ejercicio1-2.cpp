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

        nuevo= new tnodo;

        if(nuevo != NULL){
            cout<<"digite un valor: \n";
            cin>>nuevo->dato;
            nuevo->sig=NULL;
            nuevo->ant=NULL;
        }
        else
            cout<<"memoria llena! \n";
    }

    void aniadir_inicio(pnodo &lista, pnodo nuevo){

        if(lista == NULL)
            lista=nuevo;
        
        else{
            lista->ant=nuevo;
            nuevo->sig=lista;
            lista=nuevo;
        }
    }

    void aniadir_final(pnodo &lista, pnodo nuevo){

        pnodo aux;

        if(lista == NULL)
            lista=nuevo;
        
        else{
            for(aux=lista;aux->sig != NULL;aux=aux->sig);
            aux->sig=nuevo;
            nuevo->ant=aux;
        }
    }

    void agregar_orden(pnodo &lista, pnodo nuevo){

        pnodo aux;

        if(lista == NULL)
        lista=nuevo;

        else if(lista->dato > nuevo->dato){

            nuevo->sig=lista;
            lista->ant=nuevo;
            lista=nuevo;
        }
        else{
            for(aux=lista;(aux->sig)->dato < nuevo->dato && aux->sig != NULL;aux=aux->sig);

            if(aux->sig == NULL){
                
                aux->sig=nuevo;
                nuevo->ant=aux;
            }
            else{

                nuevo->ant=aux;
                nuevo->sig=aux->sig;
                aux->sig->ant=nuevo;
                aux->sig=nuevo;
            }
        }
    }

    void quitar_inicio(pnodo &lista){

        if(lista == NULL)
        cout<<"lista vacia \n";

        else if(lista->sig == NULL && lista->ant == NULL){

            delete lista;
            lista=NULL;
        }
        else{
            pnodo p=lista;
            lista=lista->sig;
            lista->ant=NULL;
            p->sig=NULL;
            p->ant=NULL;
            delete p;
        }
    }

    void quitar_final(pnodo &lista){

        pnodo aux;

        if(lista == NULL)
        cout<<"lista vacia \n";

        else if(lista->sig == NULL && lista->ant == NULL){

            delete lista;
            lista=NULL;
        }
        else{
            for(aux=lista;aux->sig != NULL;aux=aux->sig);
            pnodo p=aux;
            aux=aux->ant;
            aux->sig=NULL;
            p->sig=NULL;
            p->ant=NULL;
            delete p;
        }
    }

    void quitar_valor(pnodo &lista){

        pnodo aux; int quitar;

        cout<<"digite el dato a quitar: \n";
        cin>>quitar;

        if(lista == NULL)
        cout<<"lista vacia \n";

        else if(lista->sig == NULL){
            if(lista->dato == quitar){
                delete lista;
                lista=NULL;
                cout<<"dato eliminado! \n";
            }
            else
                cout<<"el dato no existe! \n";
        }
        else if(lista->dato == quitar){

            pnodo p=lista;
            lista=lista->sig;
            lista->ant=NULL;
            p->sig=NULL;
            delete p;
        }
        else{
            for(aux=lista;(aux->sig)->dato != quitar && aux->sig != NULL;aux=aux->sig);

            if(aux->sig == NULL)
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

    void mostrar_valor (pnodo lista){

        int mostrar; pnodo aux;

        cout<<"que valor quiere mostrar: \n";
        cin>>mostrar;

        if(lista == NULL)
        cout<<"lista vacia \n";

        else if(lista->dato == mostrar)
            cout<<"dato econtrado!, es: "<<mostrar<<endl;
        
        else{
            for(aux=lista;(aux->sig)->dato != mostrar && aux->sig != NULL;aux=aux->sig);
            if(aux->sig == NULL)
                cout<<"dato no econtrado! \n";
            else
                cout<<"dato encontrado!, es: "<<mostrar<<endl;
        }
        
    }

    void mostrar_lista(pnodo aux){

        if(aux == NULL)
            cout<<"lista vacia! \n";
        
        else if(aux->sig == NULL)
            cout<<aux->dato<<endl;
        
        else{
            cout<<aux->dato<<endl;
            mostrar_lista(aux->sig);
        }
    }

int main(){
pnodo nuevo;
pnodo lista;
int opcion=0;
    do{
        system("cls");
        cout<<"1-crear lista \n"
            <<"2-crear nodo \n"
            <<"3-aniadir nodo al inicio de la lista \n"
            <<"4-aniadir nodo al final de la lista \n"
            <<"5-aniadir nodo por orden \n"
            <<"6-extraer nodo del inicio de la lista \n"
            <<"7-extrar nodo del final de la lista \n"
            <<"8-extraer nodo segun un valor especificado por el usuario \n"
            <<"9-buscar nodo de la lista \n"
            <<"10-mostrar lista \n"
            <<"11-salir \n";
            cin>>opcion;
        switch (opcion){
            case 1:
            system("cls");
                iniciar_lista (lista);
                cout<<"lista iniciada! \n";
            getch();
            break;

            case 2:
            system("cls");
                crear_nodo (nuevo);
                cout<<"nodo creado! \n";
            getch();
            break;

            case 3:
            system("cls");
                aniadir_inicio (lista,nuevo);
                cout<<"inicio agregado! \n";
            getch();
            break;

            case 4:
            system("cls");
                aniadir_final(lista,nuevo);
                cout<<"final agregado! \n";
            getch();
            break;

            case 5:
            system("cls");
                agregar_orden(lista,nuevo);
                cout<<"nodo agregado! \n";
            getch();
            break;

            case 6:
            system("cls");
                quitar_inicio(lista);
                cout<<"inicio quitado! \n";
            getch();
            break;

            case 7:
            system("cls");
                quitar_final(lista);
                cout<<"final quitado! \n";
            getch();
            break;

            case 8:
            system("cls");
                quitar_valor(lista);
            getch();
            break;

            case 9:
            system("cls");
                mostrar_valor(lista);
            getch();
            break;

            case 10:
            system("cls");
                mostrar_lista(lista);
            getch();
            break;

            case 11:
            system("cls");
            cout<<"gracias por ver :D!";
            getch();
            break;

        }
    }while(opcion != 11);
    return 0;
}