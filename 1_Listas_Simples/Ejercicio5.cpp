#include <iostream>
#include <conio.h>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{

    int dato;
    pnodo sig;
};

    void iniciar_lista(pnodo &lista){

        lista=NULL;
    }

    void crear_nodo(pnodo &nuevo){

        nuevo=new tnodo;

        if(nuevo != NULL){

            cout<<"digite un dato: \n";
            cin>>nuevo->dato;
            nuevo->sig=NULL;
        }
        else
        cout<<"no hay memoria \n";
    }

    void cargar_nodo(pnodo &lista, pnodo nuevo){

        pnodo aux=lista;
        short int opcion;

        cout<<"1-cargar nodo en el inicio \n"
            <<"2-cargar nodo en el final \n";
            cin>>opcion;

        if(opcion == 1){

            if(lista == NULL){
            lista=nuevo;
            cout<<"nodo cargado! \n";
            }
            else if(lista->dato > nuevo->dato){

                nuevo->sig=lista;
                lista=nuevo;
                cout<<"nodo cargado! \n";
            }
            else{
                delete nuevo;
                cout<<"nodo NO cargado! \n";
                return;
            }
            
        }

        else if (opcion == 2){

            if(lista == NULL){
            lista=nuevo;
            cout<<"nodo cargado! \n";
            }
            else {
                while(aux->sig != NULL)
                aux=aux->sig;

                    if(aux->dato < nuevo->dato){

                        aux->sig=nuevo;
                        cout<<"nodo cargado! \n";
                    }

                    else{

                        delete nuevo;
                        cout<<"nodo NO cargado! \n";
                    }
            }
        }
    }

    void quitar_nodo(pnodo &lista){

        pnodo aux=lista;
        int buscar=0,inverso=0,aux1=0;

        cout<<"ingrese un dato: \n";
        cin>>buscar;
        aux1=buscar;

        while(aux1 != 0){
            inverso=inverso*10 + aux1 % 10;
            aux1=aux1/10;
        }

        if(aux == NULL)
            cout<<"lista vacia! \n";

        else if(aux->dato == buscar || aux->dato == inverso){
            delete lista;
            lista=NULL;
        }
        
        else{

            for(aux=lista;((aux->sig)->dato != buscar) && (aux->sig != NULL);aux=aux->sig);

                if(aux->sig == NULL){
                    cout<<"dato no encontrado! \n";
                    return;
                }

                else if((aux->sig)->dato == buscar){

                    pnodo p=aux->sig;
                    aux->sig=(aux->sig)->sig;
                    p->sig=NULL;
                    delete p;
                    return;
                }
                
                for(aux=lista;((aux->sig)->dato != inverso) && (aux->sig != NULL);aux=aux->sig);

                if(aux->sig == NULL){
                    cout<<"dato no encontrado \n";
                    return;
                }
                 else if((aux->sig)->dato == inverso){

                    pnodo p=aux->sig;
                    aux->sig=(aux->sig)->sig;
                    p->sig=NULL;
                    delete p;
                    return;
                }
                

        }
    }

    void contar_nodos(pnodo lista){

    pnodo aux=lista;
    int cont=1;

        if(aux == NULL)
        cout<<"lista vacia! \n";

        else if(aux->sig == NULL)
            cout<<"hay 1 elemento en la lista! \n";
        

        else{
            for(aux=lista;aux->sig != NULL;aux=aux->sig)
            cont++;
            cout<<"hay: "<<cont<<" nodos en la lista! \n";
        }
    }

    	void mostrar_lista(pnodo aux){
		
 		if (aux==NULL)
 		cout << "Lista Vacia" << endl;

 		else if (aux->sig==NULL)
 			cout << aux->dato << endl;
 			else{ 

				 cout << aux->dato << endl;
 				 mostrar_lista(aux->sig);
 				}
				 
	}

int main(){
pnodo lista, nuevo;
int opcion;
    do
    {
        system("cls");
        cout<<"1- cargar lista \n"
            <<"2-crear y cargar modo \n"
            <<"3-eliminar nodo \n"
            <<"4- contar elementos \n";
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
                cargar_nodo(lista,nuevo);
                
            getch();
            break;

            case 3:
            system("cls");
                quitar_nodo(lista);
                cout<<"nodo quitado! \n";
            getch();
            break;

            case 4:
            system("cls");
                contar_nodos(lista);
                mostrar_lista(lista);
            getch();
            break;

            case 5:
            system("cls");
                cout<<"gracias por ver :D";
            getch();
            break;
        }
    } while ( opcion != 5 );
    
    return 0;
}