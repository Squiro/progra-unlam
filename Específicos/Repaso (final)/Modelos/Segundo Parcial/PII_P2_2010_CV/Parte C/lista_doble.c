#include "lista_doble.h"

void crearLista(t_lista * pl)
{
    *pl = NULL;
}

int insertar(t_lista * pl, const t_dato *d, t_cmp comparar)
{
    t_nodo * actual = *pl, * antAux, * sigAux, * nuevo;
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
            antAux = actual->ant;
            sigAux = actual;
        }
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

int buscarElemento(t_lista * pl, t_dato *d, t_cmp comparar)
{
    t_nodo * actual = *pl;
    int cmp;

    if (!(*pl))
        return NO_ENCONTRADO;

    while (actual && comparar(&actual->dato, d) < 0)
        actual = actual->sig;
    while (actual && comparar(&actual->dato, d) > 0)
        actual = actual->ant;

    cmp = comparar(&actual->dato, d);

    if (!cmp)
    {
        *d = actual->dato;
        return SUCCESS;
    }

    return NO_ENCONTRADO;
}

int compararDNI(const void *arg1, const void *arg2)
{
    t_alumno * alum1 = (t_alumno *) arg1, * alum2 = (t_alumno *) arg2;

    return (int) alum1->dni - alum2->dni;
}
