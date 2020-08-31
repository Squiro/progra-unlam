#include "lista_circ.h"

/** Implementanciones de Pila Circular */

void crearPila(t_lista *pl)
{
    *pl = NULL;
}

int pilaLlena(const t_lista *pl)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    free(nuevo);

    return nuevo == NULL;

}

int pilaVacia(const t_lista *pl)
{
    return *pl == NULL;
}

int verTopePila(const t_lista *pl, t_dato *d)
{
    if (!(*pl))
        return PILA_VACIA;

    *d = (*pl)->dato;

    return SUCCESS;
}

int apilar(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->dato = *d;

    if (!(*pl))
        nuevo->sig = nuevo;
    else
    {
        nuevo->sig = (*pl)->sig;
        (*pl)->sig = nuevo;
    }

    *pl = nuevo;

    return SUCCESS;
}

int desapilar(t_lista *pl, t_dato *d)
{
    t_nodo * aux;
    t_lista * pIni = pl;

    if (!(*pl))
        return PILA_VACIA;

    //pl apunta al ultimo elemento agregado, lo guardamos en un aux
    aux = *pl;
    //Guardamos su dato
    *d = aux->dato;

    //Recorremos la "pila" hasta que el siguiente sea diferente de aux
    while ((*pl)->sig != aux)
        pl = &(*pl)->sig;

    //Indicamos cual es el primer elemento de la lista circular (primero en ser agregado en la pila, ultimo en ser desapilado)
    if (aux->sig == *pl)
        *pl = NULL;
    else
        (*pl)->sig = aux->sig;
    //Indicamos cual es el nuevo ultimo de la lista
    *pIni = *pl;
    //Liberamos memoria
    free(aux);

    return SUCCESS;
}

void vaciarPila(t_lista *pl)
{
    t_nodo * aux;

    while ((*pl)->sig != *pl)
    {
        aux = (*pl)->sig;
        (*pl)->sig = aux->sig;
        printf("AUX: %d PL: %d\n", aux->dato, (*pl)->dato);

        free(aux);
    }
    free(*pl);
    *pl = NULL;
}
