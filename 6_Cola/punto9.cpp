//Emiliano Aramayo, Juan Gaspar 2do Informatica
//en conclusion: si se puede hacer el mismo algoritmo para cola con listas o con arreglos


#include <iostream>
#include <conio.h>
using namespace std;
const int MAX=10;
typedef int contenedor[MAX];
typedef struct tcola{

    contenedor datos;
    int frente;
    int final;
};

//funcion muy importante para determinar el siguiente de los 2 punteros.
int siguiente(int indice){
    //indicamos si el indice esta en el ultimo elemento retornamos a cero para hacer circular.
    if(indice == MAX-1)
        return 0;
    
    //si el indice no esta en el ultimo elemento simplemente sumamos 1.
    else
        return (indice+1);
    
}

//booleano para saber si la cola esta vacia
bool cola_vacia(tcola cola){

    return cola.frente==cola.final;
}

//booleano para returnar si la cola esta llena
bool cola_llena(tcola cola){

    return (siguiente(cola.final)==cola.frente);
}

//iniciamos la cola(podriamos hacer esto directamente desde el struct pero bueno)
//quien soy yo para discutir al jefe de catedra
void iniciar_cola(tcola &cola){

    cola.frente=MAX-1;
    cola.final=MAX-1;    
}
//agregamos la cola en el final porque utilizamos el sistema FIFO. 
void agregar_cola(tcola &cola, int nuevo){

    if(cola_llena(cola)==true)
        cout<<"cola llena!\n";
        else{
            cola.final=siguiente(cola.final);
            cola.datos[cola.final]=nuevo;
        }
}

//retornamos el valor de el frente de la cola porque utilizamos el sistema FIFO. asi lo quitamos de la cola
int quitar_cola(tcola &cola){
    int aux;
    if(cola_vacia(cola)==true)
        aux=-1;
    else{
        cola.frente=siguiente(cola.frente);
        aux=cola.datos[cola.frente];
    }
    return (aux);
}
//mostramos el frente de la cola
int mostrar_frente(tcola cola){
    int consultar;
    if(cola_vacia(cola)==true)
        consultar=-1;
    else
        consultar=cola.datos[siguiente(cola.frente)];
        return (consultar);
}

//algoritmo para calcular la serie fibonacci
int fibo(int num){

    tcola cola;
    int t3,t;
    iniciar_cola(cola);
    // si el num es 1 o 2 directamente colocamos 1
    if(num ==1 || num==2)
        t3=1;
        else{

            t=3;
            //agregamos los primeros valores de la serie fib 1 1
            agregar_cola(cola,1);
            agregar_cola(cola,1);
            //mientras t<num asignamos a t3=frente de la cola + 
            while(t<num){
                t3=quitar_cola(cola)+mostrar_frente(cola);
                agregar_cola(cola,t3);
                t++;
            }
            t3=quitar_cola(cola)+quitar_cola(cola);
        }
        return t3;
}

int main(){

    int num;
    cout<<"ingrese un numero-> ";
    cin>>num;
        cout<<"\ntermino fibo: "<<num<<"es: "<<fibo(num);

    return 0;
}