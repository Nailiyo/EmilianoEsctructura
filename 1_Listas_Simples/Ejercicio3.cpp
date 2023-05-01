#include <iostream>
#include <conio.h>
using namespace std;

struct tfecha{
        short int dia;
        short int mes;
        short int anio;
};
struct medico{
    long int dni;
    string nombre;
    string apellido;
    short int dosis;
    tfecha fecha;
    string tipo_vacuna;
};
typedef struct tnodo *pnodo;
typedef struct tnodo{

    medico dato;
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

    void iniciar_paciente(pnodo &nuevo){

        nuevo = new tnodo;
        short int opcion;
        if(nuevo!=NULL){
            nuevo->sig=NULL;
            cout<<"ingrese el dni: "<<endl;
            cin>>nuevo->dato.dni;
            cout<<"ingrese el nombre: "<<endl;
            cin>>nuevo->dato.nombre;
            cout<<"ingrese el apellido: "<<endl;
            cin>>nuevo->dato.apellido;
            cout<<"ingrese cuantas dosis tiene: "<<endl;
            cin>>nuevo->dato.dosis;
            cout<<"ingrese la ultima fecha de vacunacion: "<<endl;
            cin>>nuevo->dato.fecha.dia;
            cin>>nuevo->dato.fecha.mes;
            cin>>nuevo->dato.fecha.anio;

            do{
            cout<<"ingrese el tipo de vacuna: \n"
                <<"1-pfizer \n"
                <<"2-sputnik \n";
                cin>>opcion;

                if(opcion == 1)
                nuevo->dato.tipo_vacuna="pfizer";

                if(opcion == 2)
                nuevo->dato.tipo_vacuna="sputnik";

            }while(!(opcion==1 || opcion ==2));
        }
        else
        cout<<"memoria llena! \n";
    }

    void agregar_paciente(tlista &lista, pnodo nuevo){

        nuevo->sig=lista.inicio;
        lista.inicio=nuevo;
        lista.cont++;
    }

    void cant_dosis(tlista lista){
        int cont=0;
        pnodo i;

        if(lista.inicio == NULL)
        cout<< "lista vacia! \n";

        else if(lista.cont == 1){
                if(lista.inicio->dato.dosis <=1){
                    cout<<i->dato.nombre<<endl;
                    cout<<i->dato.apellido<<endl;
                    cout<<i->dato.fecha.dia<<" "<<i->dato.fecha.mes<<" "<<i->dato.fecha.anio<<endl;
                    cout<<"-----------------------------------"<<endl;
                    cont++;
                }
        }

        else {
            for(i=lista.inicio;i->sig != NULL;i=i->sig){

            if(i->dato.dosis<=1){
                cout<<i->dato.nombre<<endl;
                cout<<i->dato.apellido<<endl;
                cout<<i->dato.fecha.dia<<" "<<i->dato.fecha.mes<<" "<<i->dato.fecha.anio<<endl;
                cout<<"-----------------------------------"<<endl;
                cont++;
            }
        }
    }
        cout<<"Hay: "<<cont<<" pacientes, sin segunda dosis"<<endl;
}

    void ordenar_lista(tlista &lista){

        pnodo aux=lista.inicio;
        if(lista.cont == 0){

            cout<<"lista vacia!"<<endl;
            return;
        }
    else{
        for(int i=0;i<lista.cont;i++){
            aux=lista.inicio;
            for(int j=0;j<lista.cont;j++){
                
                if(aux->dato.tipo_vacuna != "pfizer"){
                    lista.inicio=aux->sig;
                    lista.inicio->sig=aux;
                    aux->sig=(aux->sig)->sig;
                }
                aux=aux->sig;
            }
        }
        cout<<"lista ordenada! \n";
    }
}

    void mostrar_lista(tlista lista){

        pnodo aux=lista.inicio;

        if( aux == NULL)
        cout<<"lista vacia \n";
        else if (lista. cont == 1 ){

            cout<<aux->dato.nombre<<endl;
            cout<<aux->dato.apellido<<endl;
            cout<<aux->dato.dni<<endl;
            cout<<aux->dato.dosis<<endl;
            cout<<aux->dato.tipo_vacuna<<endl;
            cout<<aux->dato.fecha.dia<<" "<<aux->dato.fecha.mes<<" "<< aux->dato.fecha.anio<<endl;
            cout<<"-----------------------------------a \n";
        }
        else {
            for(pnodo i=aux;i->sig != NULL; i=i->sig){

            cout<<aux->dato.nombre<<endl;
            cout<<aux->dato.apellido<<endl;
            cout<<aux->dato.dni<<endl;
            cout<<aux->dato.dosis<<endl;
            cout<<aux->dato.tipo_vacuna<<endl;
            cout<<aux->dato.fecha.dia<<" "<<aux->dato.fecha.mes<<" "<< aux->dato.fecha.anio<<endl;
            cout<<"-----------------------------------n \n";
            }
        }
    }

int main(){

tlista lista;
pnodo nuevo;
short int opcion;
do{
    cout<<"1-cargar lista \n"
        <<"2-añadir datos del paciente \n"
        <<"3-agregar paciente \n"
        <<"4- listar la cantidad de personas y sus datos de quienes tienen que recibir 2da dosis \n"
        <<"5- ordenar lista por tipo de vacuna \n"
        <<"6-mostrar lista \n"
        <<"7- salir \n";
        cin>>opcion;

        switch (opcion){

        case 1:
        system ("cls");
            iniciar_lista(lista);
        getch();
        break;

        case 2:
        system("cls");
            iniciar_paciente(nuevo);
        getch();
        break;

        case 3:
        system("cls");
            agregar_paciente(lista,nuevo);
        getch();
        break;

        case 4:
        system("cls");
            cant_dosis(lista);
        getch();
        break;

        case 5:
        system("cls");
            ordenar_lista(lista);
        getch();
        break;

        case 6:
        system("cls");
            mostrar_lista(lista);
        getch();
        break;
        
        case 7:
            cout<<"gracias por ver :D!";
        getch();
        break;
        }

}while(opcion!=7);
    return 0;
}