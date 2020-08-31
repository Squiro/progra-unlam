#include "pila.h"

void crearPila(t_pila *p)
{
    *p = NULL;
}

int pilaLlena(const t_pila *p)
{
    t_nodo * aux = (t_nodo *) malloc(sizeof(t_nodo));

    free(aux);

    return aux == NULL;
}

int pilaVacia(const t_pila *p)
{
    return *p == NULL;
}

int apilar(t_pila *p, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->sig = *p;
    nuevo->dato = *d;
    *p = nuevo;

    return SUCCESS;
}

int desapilar(t_pila *p, t_dato *d)
{
    t_nodo * aux = *p;

    if (!(aux))
        return PILA_VACIA;

    *d = aux->dato;
    *p = aux->sig;
    free(aux);

    return SUCCESS;
}

int verTope(const t_pila *p, t_dato *d)
{
    if (!(*p))
        return PILA_VACIA;

    *d = (*p)->dato;

    return SUCCESS;
}

int vaciarPila(t_pila *p)
{
    t_nodo * aux = *p;

    while (*p)
    {
        *p = aux->sig;
        free(aux);
    }
}
