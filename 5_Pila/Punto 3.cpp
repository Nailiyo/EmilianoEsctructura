//Emiliano Aramayo, Juan Gaspar... 2do Informatica. PUNTO 3
#include <iostream>
#include <conio.h>
using namespace std;
const int MAX=20;
typedef float contenedor[MAX];
typedef struct tpila{

    contenedor datos;
    int cima;
};
    //inciar pila :D
    void iniciar_pila(tpila &pila){

        pila.cima=-1;
        cout<<"PILA INICIADA! \n";
    }
    // como la cima en la 2da y ultima pila es la posicion 10, solo preguntamos
    bool pila_llena(tpila pila){

        return pila.cima == 10;
    }
    //modulo booleano para saber si la pila esta vacia
    bool pila_vacia(tpila pila){

        return pila.cima == -1;
    }

    void agregar_cima(tpila &pila){

        if(pila_llena(pila) == true)
            cout<<"PILA LLENA! \n";
        //añadimos datos de la pila 1 de la posicion menor a la mayor
        else if(pila.cima < 9){

            cout<<"PILA 1 \n INGRESE UN NUMERO -> ";
                pila.cima++;
                cin>>pila.datos[pila.cima];
                cout<<" CIMA CARGADA! \n";
        }

        else {
            // sumamos 11 para que la 2da pila ahora sus datos se añadan de la posicion mayor a la posicion menor.
            if(pila.cima == 9){

                cout<<"PILA 1 LLENA...REDIRIGIENDO A LA PILA 2, ESPERE POR FAVOR... \n";
                pila.cima=pila.cima+11;
                pila.cima--;
                cout<<"PILA 2 \n INGRESE UN NUMERO-> ";
                cin>>pila.datos[pila.cima];
                cout<<" CIMA CARGADA! \n";
            }
            else{

                cout<<"PILA 2 \n INGRESE UN NUMERO-> ";
                pila.cima--;
                cin>>pila.datos[pila.cima];
                cout<<" CIMA CARGADA! \n";
            }
        }

    }

    void quitar_cima(tpila &pila, float aux){

        if(pila_vacia(pila) == true)
            cout<<"PILA VACIA! \n";
            //quitamos la cima de la pila 1 mientras sea menor a 9
        else if (pila.cima <= 9){

            aux=pila.datos[pila.cima];
            pila.cima--;
            cout<<"CIMA PILA 1...QUITADA! \n";
        }
        // si la cima es igual a 19 restamos 10 para volver a la primera pila
        else if(pila.cima == 19){

            aux=pila.datos[pila.cima];
            pila.cima=pila.cima-10;
            cout<<"CIMA PILA 2... QUITADA! \n";
        }
        else{

            aux=pila.datos[pila.cima];
            pila.cima++;
            cout<<"CIMA PILA 2... QUITADA! \n";
        }
    }

    void consultar_cima(tpila pila){
        //consultamos la cima en las 2 pilas 
        if(pila_vacia(pila) == true)
            cout<<"no hay datos! \n";
        else if(pila.cima <=9)
            cout<<"la cima de la pila 1 es ->"<<pila.datos[pila.cima];
        else
            cout<<"la cima de la pila 2 es ->"<<pila.datos[pila.cima];
    }

int main(){
    
    tpila pila;
    int opcion; float aux;
    do{
        // menu de opciones
            system("cls");
            cout<<"1-iniciar pila \n"
            <<"2-Agregar elemento a la pila \n"
            <<"3- quitar elemento de la pila \n"
            <<"4-consultar cima \n"
            <<"5- salir\n";
            cin>>opcion;
        
    switch(opcion){
        //logica del menu.
        case 1:
            iniciar_pila(pila);
            getch();
        break;

        case 2:
            agregar_cima(pila);
            getch();
        break;

        case 3:
            quitar_cima(pila, aux);
            getch();
        break;

        case 4:
            consultar_cima(pila);
            getch();
        break;

        case 5:
            cout<<"gracias por ver :D";
        break;

    }
    }
    while(opcion!= 5);
    return 0;
}