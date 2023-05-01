#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

void crear_poligono(int poligono[]){

    do{
        cout<<"ingrese cuantos lados tiene el poligono: "<<endl;
        cin>>poligono[0];
        cout<<"ingrese el radio del poligono: "<<endl;
        cin>>poligono[1];

    }while(poligono[0]<0 && poligono[1]<0);

    
}

void calcular_lado(int poligono[],float &ang, float &lado){

    float a=0;
    a=(2 * M_PI)/poligono[0];
    ang=a/2;
    lado=2*poligono[1]*sin(ang);
    cout<<"el lado es: "<<lado<<endl;
    
}

float calcular_perimetro(int poligono[], float lado){

    return poligono[0]*lado;
    
}

float calcular_area(int poligono[],float lado, float ang){

    float apotema;
        apotema=poligono[1]*cos(ang);
        return (lado*poligono[0]*apotema)/2;
        
}

int main(){

    int poligono[2];
    short int opcion=0;
    float ang=0,lado=0;
do
{
    system("cls");
    cout<<"1-crear poligono \n"
        <<"2-calcular longitud del lado \n"
        <<"3-calcular perimetro \n"
        <<"4-calcular area \n"
        <<"5-salir \n";
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            system("cls");
            crear_poligono(poligono);
            getch();
            break;
        case 2: 
            system("cls");
            calcular_lado(poligono,ang,lado);
            getch();
            break;

        case 3:
            system("cls");
            cout<<"el perimetro es: "<<calcular_perimetro(poligono,lado)<<endl;
            getch();
            break;

        case 4:
            system("cls");
            cout<<"la superficie es: "<<calcular_area(poligono,lado,ang)<<endl;
            getch();
            break;

        case 5:
        break;

        default:
            system("cls");
            cout<<"opcion incorrecta! \n";
            getch();
            break;
        }
    } while (opcion!=5);
return 0;
}