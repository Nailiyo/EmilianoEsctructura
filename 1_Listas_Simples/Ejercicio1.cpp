#include <iostream>
#include <conio.h>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo
{

	int dato;
	pnodo sig;
};

typedef struct tlista
{

	pnodo inicio;
	int cont;
};

void iniciar_lista(tlista &lista)
{

	lista.inicio = NULL;
	lista.cont = 0;
}

void cargar_nodo(pnodo &nuevo)
{

	nuevo = new tnodo;

	if (nuevo != NULL)
	{
		cout << "ingrese un numero: \n";
		cin >> nuevo->dato;
		nuevo->sig = NULL;
	}

	else
		cout << "memoria llena! \n";
}
void agregar_inicio(tlista &lista, pnodo nuevo)
{

	nuevo->sig = lista.inicio;
	lista.inicio = nuevo;
	lista.cont++;
}
void agregar_final(pnodo nuevo, tlista &lista)
{

	pnodo aux = lista.inicio;

	while (aux->sig != NULL)
	{

		aux = aux->sig;
	}

	aux->sig = nuevo;
	lista.cont++;
}

void agregar_orden(pnodo &aux, pnodo nuevo)
{

	if (aux->dato > nuevo->dato)
	{

		nuevo->sig = aux;
		aux = nuevo;
	}
	while (aux->dato < nuevo->dato)
	{

		aux = aux->sig;
	}

	nuevo->sig = aux->sig;
	aux->sig = nuevo;
}

void quitar_inicio(tlista &lista)
{

	pnodo aux = lista.inicio;
	lista.inicio = lista.inicio->sig;
	delete aux;
	lista.cont--;
}

void quitar_final(tlista &lista)
{

	pnodo aux = lista.inicio;

	while ((aux->sig)->sig != NULL)
	{
		aux = aux->sig;
	}
	delete aux->sig;
	lista.cont--;
	aux->sig = NULL;
}

void quitar_valor(tlista &lista)
{

	system("cls");
	pnodo aux = lista.inicio;
	int quitar;

	cout << "ingrese el valor a quitar: " << endl;
	cin >> quitar;

	if (lista.inicio == NULL)
	{
		cout << "lista vacia!" << endl;
	}

	else if (lista.inicio->dato == quitar)
	{

		lista.inicio = lista.inicio->sig;
		delete aux;
		lista.cont--;
	}
	else
	{
		for (aux = lista.inicio; ((aux->sig)->dato != quitar) && (aux->sig != NULL); aux = aux->sig)
			;

		if (aux->sig == NULL)
		{
			cout << "Dato no econtrado! \n";
		}

		else if ((aux->sig)->dato == quitar)
		{

			pnodo p = aux->sig;
			aux->sig = (aux->sig)->sig;
			p->sig = NULL;
			delete p;
		}
	}
}

void mostrar_valor(tlista lista)
{

	pnodo i = lista.inicio;
	int numero;

	if (i == NULL)
		cout << "lista vacia \n";

	else if (i->dato == numero)
	{

		cout << "el numero existe, es: " << numero << endl;
	}
	else
	{
		for (i = lista.inicio; (i->sig != NULL) && (((i->sig)->dato) != numero); i = i->sig)
			;

		if (i->sig == NULL)
			cout << "el dato no existe! " << endl;

		else if ((i->sig)->dato == numero)
			cout << "si existe el dato!, es: " << numero << endl;
	}
}

void mostrar_lista(pnodo aux)
{

	if (aux == NULL)
		cout << "Lista Vacia" << endl;

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

	tlista lista;
	pnodo nuevo;
	int opcion = 0;
	do
	{
		cout << "1-(inicializar) una lista vacia. \n"
			 << "2-crear nodo. \n"
			 << "3-agregar un nuevo nodo al inicio de la lista.\n"
			 << "4-agregar un nuevo nodo al final de la lista.\n"
			 << "5-agregar, en orden, un nuevo nodo a la lista.\n"
			 << "6-extraer un nodo del inicio de la lista.\n"
			 << "7-extraer un nodo del final de la lista.\n"
			 << "8-extraer un nodo especifico (segun un valor ingresado por el usuario) de la lista.\n"
			 << "9-buscar un nodo (valor) en la lista.\n"
			 << "10-mostrar el contenido de la lista\n"
			 << "11-salir \n";

		cin >> opcion;

		switch (opcion)
		{
		case 1:
			system("cls");
			iniciar_lista(lista);
			cout << "lista iniciada! \n";
			getch();
			break;

		case 2:
			system("cls");
			cargar_nodo(nuevo);
			cout << "nodo cargado! \n";
			getch();
			break;

		case 3:
			system("cls");
			agregar_inicio(lista, nuevo);
			cout << "inicio agregado \n";
			break;

		case 4:
			system("cls");
			agregar_final(nuevo, lista);
			cout << "final agregado \n";
			getch();
			break;

		case 5:
			system("cls");
			agregar_orden(lista.inicio, nuevo);
			getch();
			break;

		case 6:
			system("cls");
			quitar_inicio(lista);

			break;

		case 7:
			quitar_final(lista);
			break;

		case 8:
			quitar_valor(lista);
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
		}
	} while (opcion != 11);

	return 0;
}