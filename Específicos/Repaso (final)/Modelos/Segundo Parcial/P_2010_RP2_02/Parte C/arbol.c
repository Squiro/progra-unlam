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
        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }

    return SUCCESS;
}

void guardarEnOrden(t_arbol *pa, FILE *arch)
{
    if (*pa)
    {
        guardarEnOrden(&(*pa)->izq, arch);
        fwrite(&(*pa)->dato, sizeof(t_etiqueta), 1, arch);
        guardarEnOrden(&(*pa)->der, arch);
    }
}

int compararCuentas(const void *arg1, const void *arg2)
{
    t_etiqueta * ct1 = (t_etiqueta *) arg1, *ct2 = (t_etiqueta *) arg2;

    return ct1->nroCta - ct2->nroCta;
}
