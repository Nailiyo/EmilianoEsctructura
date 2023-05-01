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
    void iniciar_lista (tlista &lista){

        lista.inicio=NULL;
        lista.final=NULL;
        cout<<"lista iniciada! \n";
    }

    void crear_nodo (pnodo &nuevo){

        nuevo= new tnodo;
        if(nuevo != NULL){
            cout<<"digite un dato: \n";
            cin>>nuevo->dato;
            nuevo->sig=NULL;
            cout<<"nodo creado! \n";
        }
        else
        cout<<"memoria llena! \n";
    }

    void aniadir_inicio (tlista &lista, pnodo nuevo){

        if(lista.inicio == NULL && lista.final == NULL){
            
            lista.inicio=nuevo;
            lista.final=nuevo;
        }

        else {

            nuevo->sig=lista.inicio;
            lista.inicio=nuevo;  
        }
    }

    void aniadir_final (tlista &lista, pnodo nuevo){

        if(lista.inicio == NULL && lista.final == NULL){

            lista.inicio=nuevo;
            lista.final=nuevo;
        }
        
        else {
            lista.final->sig=nuevo;
            lista.final=nuevo;
        }
    }
    void agregar_orden (tlista &lista, pnodo nuevo){

        pnodo auxI=lista.inicio;

        if(lista.inicio == NULL && lista.final == NULL){

            lista.final=nuevo;
            lista.final=nuevo;
        }

        else if(lista.inicio->sig == NULL && lista.final->sig == NULL){
            if(lista.inicio->dato < nuevo->dato){
                lista.inicio->sig=nuevo;
                lista.final=nuevo;
            }
            else{
                nuevo->sig=lista.inicio;
                lista.inicio=nuevo;
            }
        }

        else{
            while(nuevo->dato > (auxI->sig)->dato && auxI->sig != lista.final){
                auxI=auxI->sig;
            }
            if(auxI->sig == NULL){
                lista.final->sig=nuevo;
                lista.final=nuevo;
            }
            else{
                nuevo->sig=auxI->sig;
                auxI->sig=nuevo;
            }

        }
    }

    void quitar_inicio (tlista &lista){

        pnodo auxI=lista.inicio;
        if(lista.inicio == NULL && lista.final ==NULL)
            cout<<"lista vacia! \n";
        
        else if(lista.inicio->sig == NULL && lista.final->sig == NULL){

            delete lista.inicio;
            delete lista.final;
            lista.inicio=NULL;
            lista.final=NULL;
        }
        else{
            lista.inicio=lista.inicio->sig;
            auxI->sig=NULL;
            delete auxI;
        }
    }

    void quitar_final (tlista &lista){
        pnodo auxI;

        if(lista.inicio == NULL && lista.final == NULL)
            cout<<"lista vacia \n";

        else if(lista.inicio->sig == NULL && lista.final->sig == NULL){

            delete lista.inicio;
            delete lista.final;
            lista.inicio=NULL;
            lista.final=NULL;
        }
        else{

            for(auxI=lista.inicio;auxI->sig != lista.final;auxI=auxI->sig);
            delete auxI->sig;
            lista.final=auxI;
            lista.final->sig=NULL;
        }
    }

    void quitar_valor(tlista &lista){

        int quitar;
        pnodo aux=lista.inicio;

        if(lista.inicio == NULL && lista.final ==NULL)
            cout<<"lista vacia! \n";
        
        else {

            cout<<"ingrese el dato a quitar: \n";
            cin>>quitar;

            if(lista.inicio->dato == quitar && lista.final->dato == quitar){

            delete lista.inicio;
            delete lista.final;
            lista.inicio=NULL;
            lista.final=NULL;
        }
        else if(lista.inicio->dato == quitar){

            lista.inicio=lista.inicio->sig;
            aux->sig=NULL;
            delete aux;
        }
        else{
            for(aux=lista.inicio;(aux->sig)->dato != quitar && aux->sig != NULL; aux=aux->sig);

            if(aux->sig == NULL)
                cout<<"dato no encontrado! \n";

            else if(aux->sig == lista.final){
                
                delete aux->sig;
                lista.final=aux;
                aux->sig=NULL;
            }
            else if((aux->sig)->dato == quitar){

                pnodo p=aux->sig;
                aux->sig=(aux->sig)->sig;
                p->sig=NULL;
                delete p;
            }
            
        }
        }
    }

    void mostrar_valor(tlista lista){

        pnodo aux=lista.inicio;
        int buscar;

        if(lista.inicio == NULL && lista.final ==NULL)
            cout<<"lista vacia! \n";

        else{
            cout<<"digite un valor a mostrar: \n";
            cin>>buscar;
            if(buscar == lista.inicio->dato || buscar == lista.final->dato){

                cout<<"el valor si existe, es: "<<buscar<<endl;
            }
            else{
                while(((aux->sig)->dato != buscar) && (aux->sig !=NULL))
                aux=aux->sig;

                if(aux->sig == NULL)
                cout<<"el dato NO existe! \n";

                else if((aux->sig)->dato == buscar)
                cout<<"el valor si existe, es: "<<buscar<<endl;
            }
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