#include "lista_circ.h"

/** Implementaciones de Cola Circular */

void crearCola(t_lista *pl)
{
    *pl = NULL;
}

int colaLlena(const t_lista *pl)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    free(nuevo);

    return nuevo == NULL;
}

int colaVacia(const t_lista *pl)
{
    return *pl == NULL;
}

int verTopeCola(const t_lista *pl, t_dato *d)
{
    if (!(*pl))
        return COLA_VACIA;

    *d = (*pl)->dato;

    return SUCCESS;
}

int acolar(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->dato = *d;

    if (!(*pl))
    {
        nuevo->sig = nuevo;
        *pl = nuevo;
    }
    else
    {
        nuevo->sig = (*pl)->sig;
        (*pl)->sig = nuevo;
    }

    return SUCCESS;
}

int desacolar(t_lista *pl, t_dato *d)
{
    t_nodo * aux;
    t_lista * pIni = pl;

    if (!(*pl))
        return COLA_VACIA;

    aux = *pl;
    *d = aux->dato;

    while ((*pl)->sig != *pIni)
    {
        pl = &(*pl)->sig;
    }

    if ((*pl)->sig == aux->sig)
        *pl = NULL;
    else
        (*pl)->sig = aux->sig;

    *pIni = *pl;
    free(aux);

    return SUCCESS;
}

void vaciarCola(t_lista *pl)
{
    t_nodo * aux;

    //printf("PL: %d INI: %d\n", (*pl)->dato, (*pIni)->dato);
    while (*pl != (*pl)->sig)
    {
        aux = (*pl)->sig;
        (*pl)->sig = aux->sig;
        printf("DATO: %d\n", aux->dato);
        free(aux);
    }

    free(*pl);
    *pl = NULL;
}
