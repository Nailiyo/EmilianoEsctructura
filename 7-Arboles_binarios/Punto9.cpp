#include <iostream>
#include <conio.h>
using namespace std;

typedef struct tnodo *pnodo;
struct tnodo
{

    int dato;
    pnodo izq;
    pnodo der;
};

void iniciar(pnodo &arbol)
{

    arbol = NULL;
}

void cargar(pnodo &nuevo)
{

    nuevo = new tnodo;
    
        cout << "ingrese el dato-> \n";
        cin >> nuevo->dato;
        nuevo->der = NULL;
        nuevo->izq = NULL;
}

bool Esprimo(int num)
{
    if (num == 2 || num == 3 || num == 4 || num == 5 || num == 7)
        return false;
    else
    {
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0)
                return false;      
        }
    }
    return true;
}

void insertar(pnodo &arbol, pnodo nuevo)
{
        if (arbol == NULL)
            arbol = nuevo;
        else
        {
            if (nuevo->dato < arbol->dato)
                insertar(arbol->izq, nuevo);
            else
                insertar(arbol->der, nuevo);
        }
}

void mostrar(pnodo arbol)
{
	if(arbol!=NULL){
	
    mostrar(arbol->der);
    cout << arbol->dato <<endl;
    mostrar(arbol->izq);
	}
}

int main()
{
    pnodo arbol, nuevo;
    short int opcion = 0;
    iniciar(arbol);
        cout << "arbol iniciado! \n";
    do
    {
        system("cls");
        cout << "1-cargar nodo\n"
             << "2-aniadir nodo\n"
             << "3-mostar nodo\n"
             << "4-salir\n";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cargar(nuevo);
            cout << "nodo cargado! \n";
            getch();
            break;
        case 2:
			if (Esprimo(nuevo->dato) == false)
    		{
			cout << "no es primo! \n";
        	delete nuevo;
    		}
    		else{	
            insertar(arbol, nuevo);
            cout << "dato insertado! \n";
        }
				getch();
            break;
        case 3:
            mostrar(arbol);
            getch();
            break;
    }
    } while (opcion != 4);
    return 0;
}