#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{

    long dato;
    pnodo sig;
};
typedef struct tlista{

    pnodo inicio;
    pnodo final;
    int cont;
};

    void perfect_square(bool &resultado1, bool &resultado2, long datoF){

        long num1, num2, num3, num4;

        if(datoF < 0){

            cout<<" valores positivos!! \n";
            return;
        }
        else{
            num1 = 5*pow(datoF,2)+4;
            num2 = 5*pow(datoF,2)-4;

            num1=sqrt(num1);
            num2=sqrt(num2);

            num3=num1*num1;
            num4=num2*num2;

            resultado1= num1 == num3;
            resultado2= num2 == num4;
            
        }
    }

    void iniciar_lista(tlista &lista){

        lista.inicio=NULL;
        lista.final=NULL;
        lista.cont=0;
    }

    void iniciar_nodo(pnodo &nuevo, long &datoF){

        nuevo= new tnodo;

        if (nuevo != NULL){
            cout<<"digite un dato: \n";
            cin>>nuevo->dato;
            nuevo->sig=NULL;
            datoF=nuevo->dato;
        }

        else{
            cout<<"memoria llena! \n";
        }
    }

    void cargar_lista(tlista &lista, pnodo nuevo, bool resultado1, bool resultado2, long datoF){

        perfect_square(resultado1,resultado2,datoF);

        if(resultado1 == true || resultado2 == true){

            pnodo aux;
            if(lista.inicio == NULL && lista.final == NULL){

                lista.inicio=nuevo;
                lista.final=nuevo;
                lista.cont++;
            }
            else if(lista.inicio == lista.final){

                if (lista.inicio->dato > nuevo->dato){

                    nuevo->sig=NULL;
                    lista.inicio->sig=nuevo;
                    lista.final=nuevo;
                    lista.cont++;
                }
                else{

                    nuevo->sig=lista.inicio;
                    lista.inicio=nuevo;
                    lista.cont++;
                }
            }
            else if(lista.inicio->dato < nuevo->dato){

                    nuevo->sig=lista.inicio;
                    lista.inicio=nuevo;
                    lista.cont++;
            }
            else if(lista.final->dato > nuevo->dato){

                    nuevo->sig=NULL;
                    lista.final->sig=nuevo;
                    lista.final=nuevo;
                    lista.cont++;
            }

            else{
                for(aux=lista.inicio;nuevo->dato < (aux->sig)->dato;aux=aux->sig);

                nuevo->sig=aux->sig;
                aux->sig=nuevo;
                lista.cont++;
            }
            cout<<"nodo cargado! \n";
        }

        else{
            cout<<"el numero no pertenece a la serie fibbonacci! \n";
        }

    }

    void buscar_nodo(tlista lista){
        long num;
        pnodo aux;
        cout<<"ingrese el dato a buscar: \n";
        cin>>num;

        if(lista.inicio == NULL && lista .final == NULL)
            cout<<"lista vacia! \n";
        
        else if(lista.inicio->dato == num)
            cout<<"dato encontrado!, es: "<<num<<endl;
        
        else if(lista.final->dato == num)
            cout<<"dato encontrado!, es: "<<num<<endl;

            else{
                for(aux=lista.inicio;(aux->sig)->dato != num && aux->sig != NULL;aux=aux->sig);

                if(aux->sig == NULL)
                    cout<<"dato no encontrado! \n";

                else if((aux->sig)->dato == num)
                    cout<<"dato encontrado!, es: "<<num<<endl;
            }
        
    }

    void quitar_nodo(tlista &lista){

        long num;
        pnodo aux;

        cout<<"digite el nodo a quitar: \n";
        cin>>num;
        if(lista.inicio == NULL && lista.final == NULL)
            cout<<"lista vacia! \n";
        
        else if(lista.inicio == lista.final){
            if(lista.inicio->dato == num){
                delete lista.inicio;
                delete lista.final;
                lista.inicio=NULL;
                lista.final=NULL;
                lista.cont--;
            }
            else
                cout<<"dato no encontrado! \n";
            
        }

        else if(lista.inicio->dato == num){

            aux=lista.inicio;
            lista.inicio=lista.inicio->sig;
            aux->sig=NULL;
            delete aux;
            lista.cont--;
        }
        else{
        for(aux=lista.inicio;(aux->sig)->dato != num && aux->sig != NULL;aux=aux->sig);

            if(aux->sig == NULL)
                cout<<"dato no encontrado! \n";

            else if(aux->sig == lista.final){
                
                delete aux->sig;
                lista.final=aux;
                aux->sig=NULL;
            }
            else if((aux->sig)->dato == num){

                pnodo p=aux->sig;
                aux->sig=(aux->sig)->sig;
                p->sig=NULL;
                delete p;
            }
        }
    }

int main(){
tlista lista;
pnodo nuevo;
short int opcion;
long datoF;
bool resultado1,resultado2;
iniciar_lista(lista);

    do{
        if(lista.cont == 15){

            cout<<"lista llena! \n"
                <<"1-quitar nodo \n"
                <<"2- salir \n";
                cin>>opcion;
                switch (opcion){

                    case 1: 
                    system("cls");
                        quitar_nodo(lista);
                    getch();
                    break;

                    case 2:
                    system("cls");
                        cout<<"gracias por ver :D";
                    return 0;
                    getch();
                    break;
                }
        }
        cout<<"1-agregar orden \n"
            <<"2-buscar valor \n"
            <<"3-quitar nodo \n"
            <<"4- salir \n";
            cin>>opcion;

            switch (opcion){

                case 1:
                system("cls");
                    iniciar_nodo(nuevo,datoF);
                    cout<<"nodo creado! \n";
                    cargar_lista(lista,nuevo,resultado1,resultado2,datoF);
                getch();
                break;

                case 2:
                system("cls");
                    buscar_nodo(lista);
                getch();
                break;

                case 3:
                system("cls");
                    quitar_nodo(lista);
                getch();
                break;

                case 4:
                system("cls");
                    cout<<"gracias por ver :D!";
                break;

            }

    }while(opcion != 4);

    return 0;
}