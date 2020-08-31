#include "lista_doble.h"

void crearLista(t_lista * pl)
{
    *pl = NULL;
}
int listaLlena(const t_lista * pl)
{
    t_nodo * aux = (t_nodo *) malloc(sizeof(t_nodo));

    free(aux);

    return aux == NULL;
}

int listaVacia(const t_lista * pl)
{
    return *pl == NULL;
}

int insertarFinal(t_lista * pl, t_dato * d)
{
    t_nodo *actual = *pl, * nuevo;

    nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    if (actual)
    {
        while (actual->sig)
            actual = actual->sig;

        actual->sig = nuevo;
    }

    nuevo->dato = *d;
    nuevo->sig = NULL;
    nuevo->ant = actual;

    *pl = nuevo;

    return SUCCESS;
}

int insertarOrdenado(t_lista * pl, t_dato * d, t_cmp comparar)
{
    t_nodo *actual = *pl, *antAux, *sigAux, *nuevo;
    int cmp;

    if (actual)
    {
        //Recorremos para alla > mientras exista un lugar para moverse, y mientras la comparacion dé menor a 0
        while (actual->sig && comparar(&actual->dato, d) < 0)
            actual = actual->sig;

        //Recorremos para alla < mientras exista un lugar para moverse, y mientras la comparacion dé mayor a 0
        while (actual->ant && comparar(&actual->dato, d) > 0)
            actual = actual->ant;

        cmp = comparar(&actual->dato, d);

        //Si la comparacion es mayor a 0, quiere decir que el elemento a a agregar es mas grande, y tiene que ir a la derecha
        if (cmp < 0)
        {
            //Seteamos que el anterior es el actual nodo en el que estamos parado
            antAux = actual;
            //El siguiente va a ser el siguiente del nodo en el que estamos parados
            sigAux = actual->sig;
        }
        //Si la comparacion es mayor a 0, quiere decir que es mas chico, entonces tenemos que agregarlo a la izquierda
        else if (cmp > 0)
        {
            antAux = actual->ant;
            sigAux = actual;
        }
        else
            return DUPLICADO;
    }
    else //Si no existe el nodo actual, quiere decir que la lista esta vacia y estamos en el caso base
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

    //Si existe un nodo anterior (i.e: si no es nulo), le decimos que el siguiente es el nuevo
    if (antAux)
        antAux->sig = nuevo;
    //Lo mismo pero con el siguiente
    if (sigAux)
        sigAux->ant = nuevo;

    //Ponemos a pl en el ult nodo tratado
    *pl = nuevo;

    return SUCCESS;
}

int ordenarLista(t_lista * pl)
{
    t_nodo * actual = *pl, * nodoMenor, * antAux, * sigAux;

    if (!actual)
        return LISTA_VACIA;

    //Nos movemos para el comienzo de la lista (extremo más izquierdo)
    while (actual->ant)
        actual = actual->ant;

    while (actual->sig)
    {
        nodoMenor = hallarMenor(actual, &actual->dato);

        if (actual != nodoMenor)
        {
            sigAux = actual->sig;
            antAux = actual->ant;

            //Necesitamos que el que le SIGUE al actual apunte al menor ahora, y no a al actual
            if (sigAux)
                sigAux->ant = nodoMenor;
            //Necesitamos que el nodo ANTERIOR al actual apunte al menor
            if (antAux)
                antAux->sig = nodoMenor;

            //Necesitamos saber si hay más de un lugar de separacion entre los nodos
            if (sigAux != nodoMenor)
            {
                //Al que está antes del nodo menor, le indicamos que su siguiente va a ser el actual
                nodoMenor->ant->sig = actual;
                //Al que le sigue al nodoMenor, le indicamos que su anterior va a ser el nodo actual
                if (nodoMenor->sig)
                    nodoMenor->sig->ant = actual;

                actual->ant = nodoMenor->ant;
                actual->sig = nodoMenor->sig;

                nodoMenor->ant = antAux;
                nodoMenor->sig = sigAux;
            }
            else
            {
                //Si hay un solo lugar de separación, intercambiamos los nodos de esta forma
                //El siguiente del actual va a ser el siguiente del menor
                actual->sig = nodoMenor->sig;
                //El anterior del actual va a ser el menor
                actual->ant = nodoMenor;
                //El siguiente del menor va a ser el actual
                nodoMenor->sig = actual;
                //El anterior del menor va a ser el anterior del actual
                nodoMenor->ant = antAux;
            }
        }

        actual = nodoMenor->sig;
    }

    return SUCCESS;
}

int cambiarNombreLocalidad(t_lista * pl, char * str)
{
    t_nodo * actual = *pl;

    //Rebobinamos hasta el comienzo de la lista
    while (actual->ant)
        actual = actual->ant;

    while (actual)
    {
        strcpy(actual->dato.loc, str);
        actual = actual->sig;
    }

    return SUCCESS;
}

void * hallarMenor(t_nodo * actual, t_dato * d)
{
    t_nodo * menor = actual;

    while (actual)
    {
        if (compararClaves(&actual->dato, &menor->dato) < 0)
            menor = actual;
        actual = actual->sig;
    }

    return menor;
}

void mostrar(t_lista * pl)
{
    while ((*pl)->ant)
    {
        pl = &(*pl)->ant;
    }

    while (*pl)
    {
        printf("Clave: %s, Localidad: %s\n", (*pl)->dato.clave, (*pl)->dato.loc);
        pl = &(*pl)->sig;
    }
}

int compararClaves(const void * arg1, const void * arg2)
{
    t_dato * dato = (t_dato *)arg1, * dato2 = (t_dato *)arg2;

    return strcmp(dato->clave, dato2->clave);
}
