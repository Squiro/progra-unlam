#include "arbol.h"

void crearArbol(t_arbol *pa)
{
    *pa = NULL;
}

int alturaArbol(t_arbol *pa)
{
    int altIzq, altDer;

    if (!(*pa))
        return 0;

    altIzq = alturaArbol(&(*pa)->izq);
    altDer = alturaArbol(&(*pa)->der);

    return altIzq > altDer ? altIzq+1 : altDer+1;
}

void cortarHojas(t_arbol *pa)
{
    if (!*pa)
        return;

    if (!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
    }
    else
    {
        cortarHojas(&(*pa)->izq);
        cortarHojas(&(*pa)->der);
    }
}

void podarHastaNivel(t_arbol *pa, int nivel)
{
    if (!*pa)
        return;

    if (nivel >= 0 && !(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
    }
    else
    {
        podarHastaNivel(&(*pa)->izq, nivel-1);
        podarHastaNivel(&(*pa)->der, nivel-1);
    }
}

void podarHastaAltura(t_arbol *pa, int altura)
{
    podarHastaNivel(pa, altura+1);
}

void eliminarArbol(t_arbol *pa)
{
    if (*pa)
    {
        eliminarArbol(&(*pa)->izq);
        eliminarArbol(&(*pa)->der);
        free(*pa);
        *pa = NULL;
    }
}

int eliminarDeArbol(t_arbol *pa, t_dato *d, t_cmp comparar)
{
    int cmp;

    while (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            pa = &(*pa)->der;
        else if (cmp > 0)
            pa = &(*pa)->izq;
        else
            eliminarRaiz(pa);
    }

    if (!*pa)
        return -1;

    return SUCCESS;
}
void eliminarRaiz(t_arbol *pa)
{
    t_arbol *remp;
    int hi, hd;

    if (!(*pa)->izq && !(*pa)->der)
    {
        free(*pa);
        *pa = NULL;
    }

    hi = alturaArbol(&(*pa)->izq);
    hd = alturaArbol(&(*pa)->der);

    if (hi > hd)
        remp = buscarMayor(&(*pa)->izq);
    else
        remp = buscarMenor(&(*pa)->der);

    (*pa)->dato = (*remp)->dato;
    eliminarRaiz(remp);
}

t_arbol * buscarMayor(t_arbol *pa)
{
    while ((*pa)->der)
        pa = &(*pa)->der;

    return pa;
}

t_arbol * buscarMenor(t_arbol *pa)
{
    while ((*pa)->izq)
        pa = &(*pa)->izq;

    return pa;
}

void preOrden(t_arbol *pa, t_accion accion)
{
    if (*pa)
    {
        accion(&(*pa)->dato);
        preOrden(&(*pa)->izq, accion);
        preOrden(&(*pa)->der, accion);
    }
}

void inOrden(t_arbol *pa, t_accion accion)
{
    if (*pa)
    {
        inOrden(&(*pa)->izq, accion);
        accion(&(*pa)->dato);
        inOrden(&(*pa)->der, accion);
    }

}

void posOrden(t_arbol *pa, t_accion accion)
{
    if (*pa)
    {
        posOrden(&(*pa)->izq, accion);
        posOrden(&(*pa)->der, accion);
        accion(&(*pa)->dato);
    }
}

int insertar(t_arbol *pa, const t_dato *d, t_cmp comparar)
{
    int cmp;

    if (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            insertar(&(*pa)->izq, d, comparar);
        else if (cmp > 0)
            insertar(&(*pa)->der, d, comparar);
        else
            return DUPLICADO;
    }
    else
    {
        *pa = (t_nodo *) malloc(sizeof(t_nodo));

        if (!(*pa))
            return SIN_MEM;

        (*pa)->dato = *d;
        (*pa)->izq = NULL,
        (*pa)->der = NULL;
    }

    return SUCCESS;
}
int hallarNodo(const t_arbol *pa, t_dato *d, t_cmp comparar)
{
    int cmp;

    if (*pa)
    {
        cmp = comparar(&(*pa)->dato, d);

        if (cmp < 0)
            pa = &(*pa)->der;
        else if (cmp < 0)
            pa = &(*pa)->izq;
        else
            *d = (*pa)->dato;
    }

    if (!*pa)
        return -1;

    return SUCCESS;
}

int leerEnOrdenBin(t_arbol *pa, FILE * arch, int ini, int fin, t_cmp comparar)
{
    t_dato dato;
    int mid = (ini+fin)/2;

    if (ini > fin)
        return 0;

    fseek(arch, mid*sizeof(t_dato), SEEK_SET);
    fread(&dato, sizeof(t_dato), 1, arch);
    insertar(pa, &dato, comparar);
    leerEnOrdenBin(pa, arch, ini, mid-1, comparar);
    leerEnOrdenBin(pa, arch, mid+1, fin, comparar);

    return SUCCESS;
}

int arbolCompleto(t_arbol *pa)
{
    int altura = alturaArbol(pa);
    return esCompleto(pa, altura);
}

int esCompleto(t_arbol *pa, int altura)
{
    if (*pa)
    {
        return esCompleto(&(*pa)->izq, altura-1) && esCompleto(&(*pa)->der, altura-1);
    }
    return altura == 0;
}

int arbolBalanceado(t_arbol *pa)
{
    int altura = alturaArbol(pa);
    return esBalanceado(pa, altura);
}

int esBalanceado(t_arbol *pa, int altura)
{
    if (*pa)
    {
        return esBalanceado(&(*pa)->izq, altura-1) && esBalanceado(&(*pa)->der, altura-1):
    }

    return h <= 1;
}
