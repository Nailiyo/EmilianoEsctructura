#include <iostream>
#include <conio.h>
using namespace std;
typedef struct tnodo *pnodo;
typedef struct tnodo{

    int dato;
    pnodo sig;
    pnodo ant;
};

typedef struct tlista{

    pnodo inicio;
    pnodo final;
};

    void iniciar_lista(tlista &lista){

        lista.inicio = NULL;
        lista.final = NULL;
    }

    void crear_nodo(pnodo &nuevo){

        nuevo = new tnodo;
        if(nuevo != NULL){

            cout<<"digite un dato: \n";
            cin>>nuevo->dato;
            nuevo->sig=NULL;
            nuevo->ant=NULL;
        }
        else
            cout<<"memoria llena! \n";
    }

    void aniadir_inicio(tlista &lista, pnodo nuevo){

        if(lista.inicio == NULL && lista.final == NULL){

            lista.inicio=nuevo;
            lista.final=nuevo;
        }
        else {

            lista.inicio->ant=nuevo;
            nuevo->sig=lista.inicio;
            lista.inicio=nuevo;
        }
        
    }

    void aniadir_final(tlista &lista, pnodo nuevo){

        if(lista.final == NULL && lista.inicio == NULL){

            lista.inicio=nuevo;
            lista.final=nuevo;
        }
        else{
            lista.final->sig=nuevo;
            nuevo->ant=lista.final;
            lista.final=nuevo;
        }
    }

    void agregar_orden(tlista &lista, pnodo nuevo){

        pnodo aux;

        if(lista.inicio == NULL && lista.final == NULL){

            lista.inicio=nuevo;
            lista.final=nuevo;
        }
        else if(lista.inicio->dato > nuevo->dato){

            lista.inicio->ant=nuevo;
            nuevo->sig=lista.inicio;
            lista.inicio=nuevo;
        }
        else if(lista.final->dato < nuevo->dato){

            lista.final->sig=nuevo;
            nuevo->ant=lista.final;
            lista.final=nuevo;
        }
        else{
            for(aux=lista.inicio;(aux->sig)->dato < nuevo->dato;aux=aux->sig);
                nuevo->ant=aux;
                nuevo->sig=aux->sig;
                aux->sig=nuevo;

        }
    }

    void quitar_inicio(tlista &lista){
        if(lista.inicio == NULL && lista.final == NULL)
            cout<<"lista vacia \n";

        else if(lista.inicio == lista.final){
            delete lista.inicio;
            delete lista.final;
            lista.inicio=NULL;
            lista.final=NULL;
        }
        else{
            pnodo p=lista.inicio;
            lista.inicio=lista.inicio->sig;
            lista.inicio->ant=NULL;
            p->sig=NULL;
            delete p;
        }
    }

    void quitar_final(tlista &lista){

        if(lista.inicio == NULL && lista.final == NULL)
            cout<<"lista vacia! \n";
        
        else if(lista.inicio == lista.final){

            delete lista.inicio;
            delete lista.final;
            lista.inicio=NULL;
            lista.final=NULL;
        }
        else{
            pnodo p=lista.final;
            lista.final=lista.final->ant;
            lista.final->sig=NULL;
            p->ant=NULL;
            delete p;
        }
    }

    void quitar_valor(tlista &lista){

        pnodo aux; int quitar;
            cout<<"digite un dato a quitar: \n";
            cin>>quitar;

        if(lista.inicio == NULL && lista.final == NULL)
            cout<<"lista vacia! \n";
        
        else if(lista.inicio == lista.final){
            
            if(lista.inicio->dato == quitar && lista.final->dato == quitar){
                delete lista.inicio;
                delete lista.final;
                lista.inicio=NULL;
                lista.final=NULL;
            }
        }
        else if(lista.inicio->dato == quitar){

            aux=lista.inicio;
            lista.inicio=lista.inicio->sig;
            lista.inicio->ant=NULL;
            aux->sig=NULL;
            delete aux;
        }
        else if (lista.final->dato == quitar){

            aux=lista.final;
            lista.final=lista.final->ant;
            lista.final->sig=NULL;
            aux->sig=NULL;
            delete aux;
        }
        else{
            for(aux=lista.inicio;(aux->sig)->dato != quitar && aux->sig != NULL;aux=aux->sig);
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

    void mostrar_valor(tlista lista){

        pnodo aux; int buscar;
        cout<<"digite el valor a buscar: \n";
        cin>>buscar;

        if(lista.inicio == NULL && lista.final ==NULL)
            cout<<"lista vacia! \n";
        
        else if(lista.inicio->dato == buscar)
            cout<<"dato encontrado!, es: "<<buscar<<endl;
        
        else if(lista.final->dato == buscar)
            cout<<"dato encontrado!, es: "<<buscar<<endl;
        
        else{
            for(aux=lista.inicio; (aux->sig)->dato != buscar && aux->sig != NULL;aux=aux->sig);
            if(aux->sig == NULL)
                cout<<"dato no encontrado! \n";
            else 
                cout<<"dato encontrado!,,, es: "<<buscar<<endl;
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

    void mostrar_lista2(pnodo aux){

        if(aux==NULL)
            cout<<"lista vacia! \n";

        else if(aux->ant == NULL)
            cout<<aux->dato<<endl;

        else{
            cout<<aux->dato<<endl;
            mostrar_lista2(aux->ant);
        }
        
    }

int main(){
pnodo nuevo;
tlista lista;
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
            getch();
            break;

            case 2:
            system("cls");
                crear_nodo (nuevo);
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
            getch();
            break;

            case 6:
            system("cls");
                quitar_inicio(lista);
            getch();
            break;

            case 7:
            system("cls");
            quitar_final(lista);
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
                mostrar_lista(lista.inicio);
                cout<<"--------------- \n";
                mostrar_lista2(lista.final);
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