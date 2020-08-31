#include "lista.h"

void crearLista(t_lista *pl)
{
    *pl = NULL;
}

int insertarOrdenado(t_lista *pl, const t_dato *d, t_cmp comparar)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    while (*pl && comparar(&(*pl)->dato, d) > 0)
        pl = &(*pl)->sig;

    nuevo->dato = *d;
    nuevo->sig = *pl;

    *pl = nuevo;

    return SUCCESS;
}

int insertarPrincipio(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->dato = *d;
    nuevo->sig = *pl;
    *pl = nuevo;

    return SUCCESS;
}

int insertarFinal(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    while (*pl)
        pl = &(*pl)->sig;

    nuevo->dato = *d;
    nuevo->sig = NULL;
    *pl = nuevo;

    return SUCCESS;
}

int quitarPrimero(t_lista *pl, t_dato *d)
{
    t_nodo * aux = *pl;

    if (!aux)
        return LISTA_VACIA;

    *d = (*pl)->dato;
    *pl = (*pl)->sig;
    free(aux);

    return SUCCESS;
}

int quitarUltimo(t_lista *pl, t_dato *d)
{
    while ((*pl)->sig)
        pl = &(*pl)->sig;

    *d = (*pl)->dato;
    free(*pl);
    *pl = NULL;

    return SUCCESS;
}

int quitarClave(t_lista *pl, t_dato *d, t_cmp comparar)
{
    t_nodo * aux;

    while (*pl && comparar(&(*pl)->dato, d) != 0)
        pl = &(*pl)->sig;

    if (!(*pl))
        return NO_ENCONTRADO;

    aux = *pl;
    *pl = aux->sig;
    free(aux);

    return SUCCESS;
}

int quitarDuplicados(t_lista *pl, t_dato *d, t_cmp comparar)
{
    t_lista * pLec = &(*pl)->sig;
    t_nodo * aux;

    if (!(*pl))
        return LISTA_VACIA;

    while (*pl)
    {
        while (*pLec)
        {
            if (comparar(&(*pLec)->dato, &(*pl)->dato) == 0)
            {
                aux = *pLec;
                *pLec = (*pLec)->sig;
                free(aux);
            }
            else
                pLec = &(*pLec)->sig;
        }

        //Avanzo al siguiente elemento de la lista
        pl = &(*pl)->sig;
        //Situamos al pLec como el que le siguie al PL que seteamos en la linea anterior
        pLec = &(*pl)->sig;
    }

    return SUCCESS;
}

int quitarTodosDuplicados(t_lista *pl, t_dato *d, t_cmp comparar)
{
    t_lista * pLec = &(*pl)->sig;
    t_nodo * aux;
    int duplicado = 0;

    if (!(*pl))
        return LISTA_VACIA;

    while (*pl)
    {
        while (*pLec)
        {
            if (comparar(&(*pLec)->dato, &(*pl)->dato) == 0)
            {
                aux = *pLec;
                *pLec = (*pLec)->sig;
                free(aux);
                duplicado = 1;
            }
            else
                pLec = &(*pLec)->sig;
        }

        if (duplicado)
        {
            duplicado = 0;
            aux = *pl;
            printf("SIG: %p", (*pl)->sig);
            *pl = (*pl)->sig;
            free(aux);
        }

        if (*pl)
        {
            pl = &(*pl)->sig;
            pLec = &(*pl)->sig;
        }
        else
            *pl = NULL;
    }

    return SUCCESS;
}

int ordenarLista(t_lista *pl, t_cmp comparar)
{
    t_lista * menor;
    t_nodo * aux, * menSig;

    while (*pl)
    {
        menor = hallarMenor(pl, comparar);

        if (menor != pl)
        {
            aux = *pl;
            *pl = *menor;
            menSig = (*menor)->sig;

            if (aux->sig == *menor)
                (*pl)->sig = aux;
            else
                (*pl)->sig = aux->sig;

            *menor = aux;
            (*menor)->sig = menSig;
        }
        pl = &(*pl)->sig;
    }

    return SUCCESS;
}

t_lista * hallarMenor(t_lista *pl, t_cmp comparar)
{
    t_lista * min = pl;

    while (*pl)
    {
        if (comparar(&(*pl)->dato, &(*min)->dato) < 0)
            min = pl;
        pl = &(*pl)->sig;

    }

    return min;
}


void recorrerLista(t_lista *pl)
{
    while (*pl)
    {
        printf("NUM: %d\n", (*pl)->dato);
        pl = &(*pl)->sig;
    }
}

int compararEnteros(const void *arg1, const void *arg2)
{
    int * dato1 = (int *) arg1, * dato2 = (int *) arg2;

    return *dato1-*dato2;
}

