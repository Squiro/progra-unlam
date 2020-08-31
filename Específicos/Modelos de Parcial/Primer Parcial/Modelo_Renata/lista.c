#include "lista.h"
#include "funciones.h"

void crearLista(t_lista *pl)
{
    *pl = NULL;
}

int insertarPrimero(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->dato = *d;
    nuevo->sig = (*pl)->sig;

    *pl = nuevo;

    return SUCCESS;
}

int insertarFinal(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    while (*pl)
        pl = &(*pl)->sig;

    nuevo->dato = *d;
    nuevo->sig = NULL,
    *pl = nuevo;

    return SUCCESS;
}

/** Insertar datos en orden ascendente */

int insertarOrdenadoAsc(t_lista *pl, const t_dato *d, t_cmp comparar)
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

int quitarClave(t_lista *pl, t_dato *d);

void recorrerLista(t_lista *pl)
{
    printf("Recorriendo la lista... \n\n");

    while (*pl)
    {
        printf("COEF: %d EXP: %d\n", (*pl)->dato.coef, (*pl)->dato.exp);
        pl = &(*pl)->sig;
    }
}
