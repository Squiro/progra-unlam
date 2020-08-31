#include "arbol.h"

void crearArbol(t_arbol * pa)
{
    *pa = NULL;
}

int insertar(t_arbol * pa, const t_dato * d, t_cmp comparar)
{
    int cmp;

    if (*pa)
    {
        cmp = comparar(&(*pa)->dato.dni, &d->dni);

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

        (*pa)->dato = *d;
        (*pa)->izq = NULL;
        (*pa)->der = NULL;
    }

    return SUCCESS;
}

int buscarClave(t_arbol * pa, t_dato * d, t_cmp comparar)
{
    int cmp;

    if (*pa)
    {
        cmp = comparar(&(*pa)->dato.dni, &d->dni);

        if (cmp < 0)
            buscarClave(&(*pa)->der, d, comparar);
        else if (cmp > 0)
            buscarClave(&(*pa)->izq, d, comparar);
        else
            *d = (*pa)->dato;
    }
    else
    {
        d->dni = -1;
        d->numReg = -1;
    }

    return SUCCESS;
}

int eliminarDeArbol(t_arbol * pa, t_dato * d, t_cmp comparar)
{
    int cmp;

    while (*pa && (cmp = comparar(&(*pa)->dato.dni, &d->dni) != 0))
    {
        if (cmp < 0)
            pa = &(*pa)->der;
        else if (cmp > 0)
            pa = &(*pa)->izq;
    }

    if (!(*pa))
        return NOT_FOUND;

    eliminarRaiz(pa);

    return SUCCESS;
}

void eliminarRaiz(t_arbol * pa)
{
    int altIzq, altDer;
    t_arbol * remp;

    if (!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
        return;
    }

    altIzq = alturaArbol(&(*pa)->izq);
    altDer = alturaArbol(&(*pa)->der);

    if (altIzq > altDer)
        remp = buscarMayor(&(*pa)->izq);
    else
        remp = buscarMenor(&(*pa)->der);

    (*pa)->dato = (*remp)->dato;

    eliminarRaiz(remp);
}

int alturaArbol(const t_arbol *pa)
{
    int altIzq, altDer;

    if (!(*pa))
        return 0;

    altIzq = alturaArbol(&(*pa)->izq);
    altDer = alturaArbol(&(*pa)->der);

    return altIzq > altDer ? altIzq + 1 : altDer + 1;

}

t_arbol * buscarMenor(t_arbol * pa)
{
    while ((*pa)->izq)
        pa = &(*pa)->izq;

    return pa;
}

t_arbol * buscarMayor(t_arbol * pa)
{
    while ((*pa)->der)
        pa = &(*pa)->der;

    return pa;
}

int compararDNI(const void * arg1, const void * arg2)
{
    int * dni1 = (int *) arg1, * dni2 = (int *) arg2;

    return *dni1-*dni2;
}
