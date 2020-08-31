#include "lista_doble.h"

void crearLista(t_lista * pl)
{
    *pl = NULL;
}

int insertar(t_lista * pl, const t_dato * d, t_cmp comparar)
{
    t_nodo * actual = *pl, * antAux, * sigAux, * nuevo;
    int cmp;

    //Si existe un nodo...
    if (actual)
    {
        while (actual->sig && (cmp = comparar(&actual->dato, d)) < 0)
            actual = actual->sig;

        while (actual->ant && (cmp = comparar(&actual->dato, d)) > 0)
            actual = actual->ant;

        //Es imprescindible hacer este...
        cmp = comparar(&actual->info, d);

        if (cmp < 0)
        {
            antAux = actual;
            sigAux = actual->sig;
        }
        else if (cmp >= 0)
        {
            sigAux = actual;
            antAux = actual->ant;
        }
        else
            return DUPLICADO;
    }
    else
    {
        antAux = NULL;
        sigAux = NULL;
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

int eliminarClave(t_lista * pl, t_dato * d, t_cmp comparar)
{
    t_nodo * actual = *pl, * antAux, * sigAux;
    int cmp;

    if (!(*pl))
        return 0;

    while (actual->sig && (cmp = (comparar(&actual->dato, d) )) < 0)
        actual = actual->sig;

    while (actual->ant && (cmp = (comparar(&actual->dato, d))) > 0)
        actual = actual->ant;

    if (cmp == 0)
    {
        sigAux = actual->sig;
        antAux = actual->ant;
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

        *d = actual->dato;
        free(actual);
    }
    else
        return -1;

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

void mostrarLista(t_lista * pl)
{
    t_nodo * actual = *pl;

    while (actual->ant)
        actual = actual->ant;

    while (actual->sig)
    {
        printf("\nNombre: %s", actual->dato.apyn);
        printf("\n\n");
        actual = actual->sig;
    }
}

int compararDNI(const void * arg1, const void * arg2)
{
    t_dato * dato1 = (t_dato *) arg1, * dato2 = (t_dato *) arg2;

    return dato1->dni-dato2->dni;
}
