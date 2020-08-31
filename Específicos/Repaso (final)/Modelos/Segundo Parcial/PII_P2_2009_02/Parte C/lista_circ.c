#include "lista_circ.h"

void crearCola(t_lista *pl)
{
    *pl = NULL;
}

int colaVacia(t_lista *pl)
{
    return *pl == NULL;
}

int colaLlena(t_lista *pl)
{
    t_nodo * aux = (t_nodo *) malloc(sizeof(t_nodo));

    free(aux);

    return aux == NULL;
}
int acolar(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->dato = *d;

    if (!*pl)
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
    t_nodo * aux = *pl;
    t_lista *pIni = pl;

    if (!aux)
        return COLA_VACIA;

    *d = aux->dato;

    while ((*pl)->sig != *pIni)
        pl = &(*pl)->sig;

    if ((*pl)->sig == aux->sig)
        *pl = NULL;
    else
        (*pl)->sig = aux->sig;

    *pIni = *pl;
    free(aux);

    return SUCCESS;
}

int verTope(const t_lista *pl, t_dato *d)
{
    if (!*pl)
        return COLA_VACIA;
    *d = (*pl)->dato;

    return SUCCESS;
}

void vaciarCola(t_lista *pl)
{
    t_nodo * aux;

    while (*pl && *pl != (*pl)->sig)
    {
        aux = (*pl)->sig;
        (*pl)->sig = aux->sig;
        free(aux);
    }

    free(*pl);
    *pl = NULL;
}

int eliminarNodo(t_lista *pl, const t_dato *d, t_cmp comparar)
{
    t_nodo * curr = *pl, *prev;

    if (!*pl)
        return 0;

    while (comparar(&curr->dato, d) != 0)
    {
        if (curr->sig == *pl)
            return 0;
        prev = curr;
        curr = curr->sig;
    }

    //Nos fijamos si es el único nodo en la lista circular, o sea, el primero apuntandose a si mismo
    if (curr->sig == curr)
    {
        *pl = NULL;
        free(curr);
        return SUCCESS;
    }

    //Nos fijamos si es el primer nodo en la lista
    if (curr == *pl)
    {
        prev = *pl;
        //Nos movemos hasta hallar el nodo anterior al primer nodo. Necesitamos hacer esto porque si no
        //perderiamos el enlace entre los demas nodos de la lista
        while (prev->sig != *pl)
            prev = prev->sig;
        *pl = curr->sig;
        prev->sig = *pl;
        free(curr);
    }
    //Nos fijamos si es el último nodo de la lista (el que apunta al primero)
    else if (curr->sig == *pl)
    {
        //Al nodo previo, le indicamos que su siguiente va a ser el primer nodo de la lista
        prev->sig = *pl;
        free(curr);
    }
    //Si no es primero ni último, es un nodo intermedio, por lo que simplemente seteamos
    //al siguiente del nodo previo como el siguiente del actual nodo
    else
    {
        prev->sig = curr->sig;
        free(curr);
    }

    return SUCCESS;
}

int compararClientes(const void *arg1, const void *arg2)
{
    long * dato1 = (long *)arg1, * dato2 = (long *)arg2;

    return *dato1-*dato2;
}
