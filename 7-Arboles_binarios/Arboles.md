# Arboles

## Concepto de Arbol:

![IMAGE LOGO](https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fwww.lawebdelprogramador.com%2Fusr%2F206000%2F206305%2F5a9590949e3be-Arbol-binario.png&f=1&nofb=1&ipt=c5aba6b3fddd3acb35652b1ab238f67e53e723cb0e5358ab93efb7f5ee33903e&ipo=images "arbol_binario")

Es un conjunto finito de elementos, denominados **nodos**.

Es un conjunto finito de lineas dirigidas, denominadas **ramas** que conectan nodos.

**Nodos o Vertices:**
 se trata de registros compuestos por un campo de datos y punteros o enlaces.

**Aristas o Arcos:**
 enlaces que conectan los nodos.

Existe un nodo especial llamado **RAIZ**, a partir de este descienden todos los demas.
> El 60 es un nodo raiz
 
Un arbol esta vacio cuando **no** tiene nodos.

**Nodos hojas:**
 son los nodos que no tienen descendientes.

> El 2,54,72,85 son nodos hojas.

**Nodos interiores:**
 son los que tienen al menos un subarbol.

> El 42, 75, 14, 66, 73 son nodos interiores

**Padre:**
 un nodo es ascendiente (padre) de un nodo "y", si "x" tiene un puntero al nodo "y".

> El 60 es nodo padre del 42 y 75.

**Hijo:**
 un nodo "b" es descendiente (hijo) de un nodo "a" si "b" es apuntado por "a".

> El 66 es nodo hijo del 75.

**Camino:**
 conjunto de enlace entre 2 nodos.

> El 60 tiene un camino con el 75 y 42.

**Rama:**
 camino existente entre el nodo raiz y un nodo hoja.

> El 2 tiene rama entre el 14 el 42 hasta la raiz 60.

**Nivel de un nodo:** 
cantidad de aristas entre la raiz y un nodo en especifico.

> El nivel del nodo 73 es 3.

**Altura o profundidad:**
cantidad de nodos en la rama mas larga.

> La rama mas larga es el 72, su altura es 5.

**Peso del arbol:**
cantidad de nodos hojas del arbol.

> El peso del arbol es de 4.

**Grado de un arbol:**
Maximo N° de descendientes de un nodo.

> Este arbol tiene un grado 2.

**Arbol similar:**
arboles con la misma estructura.

**Arbol equivalente:**
arboles con la misma estructura de datos.

### Punto 1-a

* Nivel del Arbol: 4
* Altura: 5
* Peso: 13
* Grado: 4
* A( B( G, H( M, N(S), O, P), I), C, D, E, F( J, K( Q, R), L))

### Punto 1-b

* Nivel del Arbol: 3
* Altura: 4
* Peso: 6
* Grado: 4
* a( e(n), d, k(w,x(u),t,z) )
---