#include "lista_doble.h"

void crearLista(t_lista *pl)
{
    *pl = NULL;
}

int insertar(t_lista *pl, const t_dato *d, t_cmp comparar)
{
    t_nodo * actual = *pl, * sigAux, * antAux, * nuevo;
    int cmp;

    if (actual)
    {
        while (actual && comparar(&actual->dato, d) < 0)
            actual = actual->sig;
        while (actual && comparar(&actual->dato, d) > 0)
            actual = actual->ant;

        cmp = comparar(&actual->dato, d);

        if (cmp < 0)
        {
            antAux = actual;
            sigAux = actual->sig;
        }
        else if (cmp > 0)
        {
            sigAux = actual;
            antAux = actual->ant;
        }
        else
            return DUPLICADO;
    }
    else
    {
        sigAux = NULL;
        antAux = NULL;
    }

    nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->dato = *d;
    nuevo->ant = antAux;
    nuevo->sig = sigAux;

    if (antAux)
        antAux->sig = nuevo;
    if (sigAux)
        sigAux->ant = nuevo;

    *pl = nuevo;

    return SUCCESS;
}

int insertarPrincipio(t_lista *pl, const t_dato *d)
{
    t_nodo * actual = *pl, * nuevo;

    if (actual)
    {
        while (actual->ant)
            actual = actual->ant;
    }
    nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;


    nuevo->dato = *d;
    nuevo->ant = NULL;
    nuevo->sig = actual;
    if (actual)
        actual->ant = nuevo;
    *pl = nuevo;

    return SUCCESS;
}

/*Esto es HORRIBLE, pero funciona. ¿Se puede mejorar? NI IDEA */
int ordenarLista(t_lista *pl, t_cmp comparar)
{
    t_nodo * actual = *pl, * menor;
    t_nodo aux;

    while (actual->ant)
        actual = actual->ant;

    while (actual)
    {
        menor = hallarMenor(actual, comparar);

        if (actual != menor)
        {
            aux = *actual;

            if (actual->sig == menor)
            {
                actual->sig = menor->sig;
                actual->ant = menor;
                menor->sig = actual;
                menor->ant = aux.ant;
            }
            else
            {

                actual->sig = menor->sig;
                actual->ant = menor->ant;
                menor->sig = aux.sig;
                menor->ant = aux.ant;
            }

            if (actual->sig)
                actual->sig->ant = actual;

            if (actual->ant)
                actual->ant->sig = actual;

            if (menor->sig)
                menor->sig->ant = menor;

            if (menor->ant)
                menor->ant->sig = menor;
        }

        actual = menor->sig;
    }

    actual = *pl;

    while (actual->ant)
        actual = actual->ant;

    *pl = actual;

    return SUCCESS;
}

t_nodo * hallarMenor(t_nodo *actual, t_cmp comparar)
{
    t_nodo * menor = actual;

    while (actual)
    {
        if (comparar(&actual->dato, &menor->dato) < 0)
            menor = actual;
        actual = actual->sig;
    }

    return menor;
}

void mostrarLista(t_lista * pl)
{
    t_nodo * actual = *pl;

    if (!(*pl))
        return;

    while (actual->ant)
        actual = actual->ant;

    while (actual)
    {
        printf("\nNum: %d", actual->dato);
        printf("\n\n");
        actual = actual->sig;
    }
}

int compararEnteros(const void *arg1, const void *arg2)
{
    int * dato1 = (int *) arg1, * dato2 = (int *) arg2;

    return *dato1-*dato2;
}
