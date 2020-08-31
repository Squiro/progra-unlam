#include "lista_doble.h"

/*
    Pregunto si hay lista doble
    if (*pl)
    {
        El actual apunta al nodo en el que estamos parados
        Hago un while mientras el siguiente sea diferente de nulo, y el dato sea mayor que el dato de puntAct
        Hago otro while mientras el anterior sea dif de nulo, y el dato sea menor que el dato de puntAct

        Son dos while, uno se mueve -> y el otro <-

        Despues pregunto si el dato es mayor al dato de la lista
        if (dato > datoLista)
            antAux = act;
            sigAux = act->sig;
        else
        {
            antAux = act->ant;
            sigAux = act;
        }

        Si acepta duplicados usamos mayor igual y etc
    }
    else
    {
        antAux = null;
        sigAux = null;
    }

    Luego de eso:

    1. Reservo memoria
    2. Si no mem, me voy ;)
    3. Asigno dato al nuevo.
    4. Le pongo los auxiliares al nuevo
    5. Me fijo si el auxiliar no es nulo y lo engancho. Pregunto si el siguiente del aux es nulo y lo engancho.
*/

void crearLista(t_lista *pl)
{
    *pl = NULL;
}

int insertarOrdenado(t_lista *pl, const t_dato *d, t_cmp comparar)
{
    t_nodo * actual = *pl, *antAux, * sigAux, * nuevo;
    int cmp;

    if (actual)
    {
        //Recorro para alla ->
        while (actual->sig && comparar(d, &actual->dato) > 0)
            actual = actual->sig;
        //Recorro para alla -> pero dado vuelta
        while (actual->ant && comparar(d, &actual->dato) < 0)
            actual = actual->ant;

        cmp = comparar(d, &actual->dato);
        //Si el dato es mayor...
        if (cmp > 0)
        {
            antAux = actual;
            sigAux = actual->sig;
        }
        else if (cmp < 0) //Si el dato es menor...
        {
            antAux = actual->ant;
            sigAux = actual;
        }
        else //Si son iguales...
            return DATO_DUPLICADO;
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

int eliminarClave(t_lista *pl, t_dato *d, t_cmp comparar)
{
    t_nodo * actual = *pl; //, * sigAux,  * antAux;

    if (!(*pl))
        return LISTA_VACIA;

    while (actual->sig && comparar(d, &actual->dato) > 0)
        actual = actual->sig;

    while (actual->ant && comparar(d, &actual->dato) < 0)
        actual = actual->ant;

    if (comparar(d, &actual->dato) == 0)
    {
        if (actual->sig)
        {
            actual->sig->ant = actual->ant;
            *pl = actual->sig;
        }
        if (actual->ant)
        {
            actual->ant->sig = actual->sig;
            *pl = actual->ant;
        }
        else if (!actual->sig)
            *pl = NULL;

        *d = actual->dato;
        free(actual);
    }
    else
        return NOT_FOUND;

    return SUCCESS;
}

int eliminarDuplicados(t_lista * pl, t_cmp comparar)
{
    t_nodo * actual = *pl, * sigAux, * antAux, * recorre;

    //Me muevo al primer nodo
    while (actual->ant)
        actual = actual->ant;

    recorre = actual->sig;

    while (actual->sig)
    {
        while (recorre->sig)
        {
            sigAux = recorre->sig;
            antAux = recorre->ant;

            if (comparar(&actual->dato, &recorre->dato) == 0)
            {
                //Si tenemos un siguiente, le decimos que el anterior es el antAux (el anterior del actual)
                if (sigAux)
                {
                    sigAux->ant = antAux;
                    //Dejamos a pl en el ultimo nodo "tratado"
                    *pl = sigAux;
                }

                if (antAux)
                {
                    antAux->sig = sigAux;
                    //Dejamos a pl en el ultimo nodo "tratado"
                    *pl = antAux;
                }
                else if (!sigAux) //Si no hay anterior ni siguiente...
                    *pl = NULL;

                free(recorre);
            }

            recorre = sigAux;
        }

        actual = actual->sig;
    }

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

int verActual(t_lista *pl, t_dato *d)
{
    if (!(*pl))
        return LISTA_VACIA;
    *d = (*pl)->dato;

    return SUCCESS;
}

int compararEnteros(const void *arg1, const void *arg2)
{
    return *(int *)arg1 - *(int *)arg2;
}
