#include "pilaest_gen.h"

void crearPila(t_pila *p, int tamElem)
{
    p->tope = 0;
    p->tamElem = tamElem;
}

int pilaLlena(const t_pila *p)
{
    return p->tope == TAM_PILA;
}

int pilaVacia(const t_pila *p)
{
    return p->tope == 0;
}

int apilar(t_pila *p, const void *d)
{
    if (p->tope == TAM_PILA)
        return PILA_LLENA;

    memmove(p->pila[p->tope], d, p->tamElem);
    p->tope++;

    return SUCCESS;
}

int desapilar(t_pila *p, void *d)
{
    if (p->tope == 0)
        return PILA_VACIA;

    p->tope--;
    memmove(d, p->pila[p->tope], p->tamElem);

    return SUCCESS;
}

int verTope(const t_pila *p, void *d)
{
    if (p->tope == 0)
        return PILA_VACIA;

    memmove(d, p->pila[p->tope-1], p->tamElem);

    return SUCCESS;
}

void vaciarPila(t_pila *p)
{
    p->tope = 0;
}
