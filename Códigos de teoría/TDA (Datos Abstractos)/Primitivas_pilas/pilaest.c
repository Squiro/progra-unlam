#include "pilaest.h"

void crearPila(t_pila *p)
{
    //Utilizamos la logica de primera posición libre para tope
    p->tope = 0;
}

int pilaVacia(const t_pila *p)
{
    //Retorna 1 si es el tope es igual a 0, 0 si el tope es dif
    return p->tope == 0;
}

int pilaLlena(const t_pila *p)
{
    return p->tope == TAM_PILA;
}

//Las primitivas no pueden llamarse entre sí
int apilar(t_pila *p, const t_dato *d)
{
    if (p->tope == TAM_PILA)
        return PILA_LLENA;

    p->pila[p->tope] = *d;
    p->tope++;

    return SUCCESS;
}

int verTope(const t_pila *p, t_dato *d)
{
    if (p->tope == 0)
        return PILA_VACIA;

    *d = p->pila[p->tope-1];
    return SUCCESS;
}

int desapilar(t_pila *p, t_dato *d)
{
    if (p->tope == 0)
        return PILA_VACIA;

    //Decrementamos antes de guardar el dato
    p->tope--;
    *d = p->pila[p->tope];
    return SUCCESS;
}

void vaciarPila(t_pila *p)
{
    p->tope = 0;
}
