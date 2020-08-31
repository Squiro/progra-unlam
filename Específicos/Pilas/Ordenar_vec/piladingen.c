#include "piladingen.h"

void crearPila(t_pila *p, int tamElem)
{
    p->pila = NULL;
    p->tamElem = tamElem;
}

int pilaLlena(const t_pila *p)
{
    void * nuevo = malloc(sizeof(p->tamElem));

    free(nuevo);
    return !nuevo;
}

int pilaVacia(const t_pila *p)
{
    return p->pila == NULL;
}

int apilar(t_pila *p, const void *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->sig = p->pila;
    nuevo->dato = malloc(sizeof(p->tamElem));

    if (!nuevo->dato)
    {
        free(nuevo);
        return SIN_MEM;
    }

    memmove(nuevo->dato, d, p->tamElem);
    p->pila = nuevo;

    return SUCCESS;
}

int desapilar(t_pila *p, void *d)
{
    t_nodo * elim = p->pila;

    if (!p->pila)
        return PILA_VACIA;

    memmove(d, elim->dato, p->tamElem);
    p->pila = elim->sig;
    free(elim->dato);
    free(elim);

    return SUCCESS;
}

int verTope(const t_pila *p, void *d)
{
    if (!p->pila)
        return PILA_VACIA;

    memmove(d, p->pila->dato, p->tamElem);
    return SUCCESS;
}

int vaciarPila(t_pila *p)
{
    t_nodo * elim = p->pila;
    while (elim)
    {
        p->pila = elim->sig;
        free(elim->dato);
        free(elim->sig);
        elim = p->pila;
    }

    return SUCCESS;
}

int ordenarPila(t_pila *p, t_cmp comparar)
{
    int num, aux;
    t_pila pilaAux;

    crearPila(&pilaAux, sizeof(int));

    while (!pilaVacia(p))
    {
        desapilar(p, &num);
        verTope(&pilaAux, &aux);

        while (!pilaVacia(&pilaAux) && comparar(&num, &aux) > 0)
        {
            desapilar(&pilaAux, &aux);
            apilar(p, &aux);
            verTope(&pilaAux, &aux);
        }

        apilar(&pilaAux, &num);
    }

    while(!pilaVacia(&pilaAux))
    {
        desapilar(&pilaAux, &aux);
        apilar(p, &aux);
    }

    return SUCCESS;
}


/*int ordenarPila(t_pila *p, t_cmp comparar)
{
    //Declaramos dos punteros a nodos que nos van a ayudar a sortear la pila
    t_nodo * ini = p->pila, * mayor;
    //Declaramos un bloque de memoria en el cual se va a alojar el dato provisoriamente
    void * aux = malloc(sizeof(p->tamElem));

    if (!aux)
        return SIN_MEM;

    while (p->pila)
    {
        //hallarMayor nos devuelve el nodo que tenga el dato mas grande
        mayor = hallarMayor(p->pila, comparar);

        //Guardamos el dato menor en un auxiliar
        memmove(aux, p->pila->dato, p->tamElem);
        //Ponemos el dato mas grande en la posicion del menor
        memmove(p->pila->dato, mayor->dato, p->tamElem);
        //Ponemos el dato mas chico en la posicion del mas grande
        memmove(mayor->dato, aux, p->tamElem);
        //Avanzamos un nodo despues de haber hecho los cambios
        p->pila = p->pila->sig;
    }
    //Hacemos que la pila apunte a la posición inicial nuevamente
    p->pila = ini;
    free(aux);
    return SUCCESS;
}

void * hallarMayor(t_nodo *nodo, t_cmp comparar)
{
    t_nodo * mayor = nodo;

    while (nodo)
    {
        if (compararEnteros(nodo->dato, mayor->dato) > 0)
            mayor = nodo;
        nodo = nodo->sig;
    }

    return mayor;
}*/

int compararEnteros(const void *arg1, const void *arg2)
{
    int *dato1 = (int *)arg1, *dato2 = (int *)arg2;

    return *dato1-*dato2;
}
