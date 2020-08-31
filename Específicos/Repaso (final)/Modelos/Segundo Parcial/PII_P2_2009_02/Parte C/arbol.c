#include "arbol.h"

void crearArbol(t_arbol *pa)
{
    *pa = NULL;
}

int insertar(t_arbol *pa, const t_info *d, t_cmp comparar)
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
        *pa = (t_nodo_arbol *) malloc(sizeof(t_nodo_arbol));

        if (!*pa)
            return SIN_MEM;

        (*pa)->dato = *d;
        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }

    return SUCCESS;
}

char * buscarCliente(t_arbol *pa, t_info *d, t_cmp comparar)
{
    int cmp;

    while (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            pa = &(*pa)->der;
        else if (cmp > 0)
            pa = &(*pa)->izq;
        /*else
            *d = (*pa)->dato;*/
    }

    if (!*pa)
        return NULL;

    return (*pa)->dato.email;
}
