#include "arbol.h"

void crearArbol(t_arbol *pa)
{
    *pa = NULL;
}

int insertar(t_arbol *pa, const t_dato *d, t_cmp comparar)
{
    int cmp;

    if (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            insertar(&(*pa)->der, d, comparar);
        else if (cmp > 0)
            insertar(&(*pa)->izq, d, comparar);
        else
            return DUPLICADO;
    }
    else
    {
        *pa = (t_nodo *) malloc(sizeof(t_nodo));

        if (!*pa)
            return SIN_MEM;

        (*pa)->dato = *d;
        (*pa)->der = NULL;
        (*pa)->izq = NULL;
    }

    return SUCCESS;
}

void vaciarArbol(t_arbol *pa)
{
    if (*pa)
    {
        vaciarArbol(&(*pa)->izq);
        vaciarArbol(&(*pa)->der);
        free(*pa);
        *pa = NULL;
    }
}

int compararEnteros(const void *arg1, const void *arg2)
{
    int *dato1 = (int *) arg1, *dato2 = (int *) arg2;

    return *dato1-*dato2;
}
