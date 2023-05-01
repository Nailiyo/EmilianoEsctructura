# Punto 2-a
## Emiliano Aramayo, Juan Gaspar.
---
### Recorrido Pre-orden

> 45,39,12,10,34,32,56,54,78,67,89.

### Recorrido En-orden

> 10,12,32,34,39,45,54,56,67,78,89.

### Recorrido Pos-orden

> 10,32,34,12,39,54,67,89,78,56,45.

# Punto 2-b

### Recorrido Pre-Orden
> 50, 35, 15,43,38, 46, 44, 75, 69, 70, 90, 81.

```c++
    void pre_orden(pnodo a){
        if(a!=NULL){
            cout<<a->dato;
            pre_orden(a->izq);
            pre_orden(a->der);
        }
    }

```

### En-Orden
> 15, 35, 38, 43, 44, 46, 50, 69, 70, 75, 81, 90.
```c++
    void En_Orden(pnodo a){
        if(a!=NULL){
            En_Orden(a->izq);
            cout<<a->dato;
            En_Orden(a->der);
        }
    }
```
### Pos-Orden
> 15, 38, 44, 46, 43, 35, 70, 69, 81, 90, 75, 50.

```c++
    void Pos_Orden(pnodo a){
        if(a!=NULL){
            Pos_Orden(a->izq);
            Pos_Orden(a->der);
            cout<<a->dato;
        }
    }
```

# Punto 2-c

### Recorrido Pre-Orden
> 8, 6, 5, 4, 1, 3, 7, 10, 9, 12, 11, 14, 13, 15
``` c++
    void PreOrden(pnodo a){
        if(a!=NULL){
            cout<<a->dato;
            PreOrden(a->izq);
            PreOrden(a->der);
        }
    }
```
### Recorrido En-Orden
> 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15.
``` c++
    void EnOrden(pnodo a){
        if(a!=NULL){
            EnOrden(a->izq);
            cout<<a->dato;
            EnOrden(a->der);
        }
    }
```
### Recorrido Pos-Orden
> 1,3,4,5,7,6, 9,11,13,15,14,12,10,8.
```c++
void PosOrden(pnodo a){
    if(a!=NULL){
        PosOrden(a->izq);
        PosOrden(a->der);
        cout<<a->dato;
    }
}
```
---