#include "arbol.h"

void crearArbol(t_arbol *pa)
{
    *pa = NULL;
}

int insertar_arbol_bin(t_arbol *pa, const t_info *d, t_cmp comparar)
{
    int cmp;

    if (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            insertar_arbol_bin(&(*pa)->der, d, comparar);
        else if (cmp > 0)
            insertar_arbol_bin(&(*pa)->izq, d, comparar);
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

int alturaArbol(t_arbol *pa)
{
    int altIzq, altDer;
    if (!(*pa))
        return 0;

    altIzq = alturaArbol(&(*pa)->izq);
    altDer = alturaArbol(&(*pa)->der);

    return altIzq > altDer ? altIzq + 1 : altDer + 1;
}

int eliminar_de_arbol(t_arbol * pa, t_info *d, t_cmp comparar)
{
    int cmp;

    //Si la comparacion sigue siendo mayor que 0, quiere decir que el dato que buscamos es mas grande, por lo que tenemos
    //que movernos a la derecha
    while (*pa && (cmp = comparar(&(*pa)->dato, d)) != 0)
    {
        if (cmp > 0)
            pa = &(*pa)->der;
        else
            pa = &(*pa)->izq;
    }

    if (!*pa)
        return NO_ENCONTRADO;

     return eliminar_raiz(pa);
}

int eliminar_raiz(t_arbol *pa)
{
    int hi, hd;
    t_arbol *remp;

    if (!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
        return SUCCESS;
    }

    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);

    if (hi > hd)
        remp = buscarMayor(&(*pa)->izq);
    else
        remp = buscarMenor(&(*pa)->der);

    (*pa)->dato = (*remp)->dato;

    eliminar_raiz(remp);

    return SUCCESS;
}

t_arbol * buscarMayor(t_arbol * pa)
{
    while ((*pa)->der)
        pa = &(*pa)->der;

    return pa;
}

t_arbol * buscarMenor(t_arbol * pa)
{
    while ((*pa)->izq)
        pa = &(*pa)->izq;

    return pa;
}
