#include <iostream>
#include <conio.h>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo
{

    float dato;
    pnodo sig;
};

void iniciar_lista(pnodo &lista)
{

    lista == NULL;
    cout << "lista iniciada! \n";
}

void crear_nodo(pnodo &nodo)
{

    nodo = new tnodo;

    if (nodo != NULL)
    {
        cout << "ingrese un dato: \n";
        cin >> nodo->dato;
        nodo->sig = NULL;
        cout << "nodo creado! \n";
    }
    else
        cout << " memoria llena!" << endl;
}

void agregar_inicio(pnodo &lista, pnodo nodo)
{

    nodo->sig = lista;
    lista = nodo;
    cout << "inicio agregado! \n";
}

void quitar_final(pnodo &lista)
{

    pnodo aux = lista;

    if (aux == NULL)
        cout << "lista vacia \n";

    else if (aux->sig == NULL)
    {
        delete aux;
        cout << "final quitado! \n";
    }
    else
    {

        while ((aux->sig)->sig != NULL)
        {
            aux = aux->sig;
        }

        delete aux->sig;
        aux->sig = NULL;
        cout << "final quitado! \n";
    }
}

void mostrar_lista(pnodo aux)
{

    if (aux == NULL)
        cout << "no existe la lista \n";

    else if (aux->sig == NULL)
        cout << aux->dato << endl;

    else
    {
        cout << aux->dato << endl;
        mostrar_lista(aux->sig);
    }
}
int main()
{
    short int opcion;
    pnodo lista, nodo;
    do
    {
        cout << "1-(inicializar) una lista vacia. \n"
             << "2-crear nodo. \n"
             << "3-agregar un nuevo nodo al inicio de la lista.\n"
             << "4-quitar un nodo al final de la lista.\n"
             << "5- mostrar lista \n"
             << "6- salir\n";
        cin >> opcion;

        switch (opcion)
        {

        case 1:
            system("cls");
            iniciar_lista(lista);
            getch();
            break;

        case 2:
            system("cls");
            crear_nodo(nodo);
            getch();
            break;

        case 3:
            system("cls");
            agregar_inicio(lista, nodo);
            getch();
            break;

        case 4:
            system("cls");
            quitar_final(lista);
            getch();
            break;

        case 5:
            system("cls");
            mostrar_lista(lista);
            getch();
            break;

        case 6:
            cout << "gracias por ver :D" << endl;
            break;
        }
    } while (opcion != 6);
    return 0;
}