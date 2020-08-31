#include "colaest_gen.h"

void crearCola(t_cola *c, int tamElem)
{
    c->tamElem;
    c->cantElem = 0;
    c->primero = 0;
    c->ultimo = -1;
}

void vaciarCola(t_cola *c)
{
    c->cantElem = 0;
    c->primero = 0;
    c->ultimo = -1;
}

int colaLlena(const t_cola *c)
{
    return c->cantElem == TAM_COLA;
}

int colaVacia(const t_cola *c)
{
    return c->cantElem == 0;
}

int acolar(t_cola *c, const void *d)
{
    if (c->cantElem == TAM_COLA)
        return COLA_LLENA;

    //Debemos incrementar el ultimo, pero tenemos que tener cuidado con el limite fisico del vector
    //No nos podemos pasar de el, en caso de hacerlo, quiere decir que la primera posicion de la cola está libre
    c->ultimo = (c->ultimo+1)%TAM_COLA;
    //Aumentamos la cantidad de elementos
    c->cantElem++;
    //Copiamos el dato en la posicion debida
    memmove(c->cola[c->ultimo], d, c->tamElem);

    return SUCCESS;
}

int desacolar(t_cola *c, void *d)
{
    if (c->cantElem == 0)
        return COLA_VACIA;

    memmove(d, c->cola[c->primero], c->tamElem);
    //Sucede lo mismo que en la linea 32, pero en este caso para el primero
    c->primero = (c->primero+1)%TAM_COLA;
    c->cantElem--;

    return SUCCESS;
}

int verTope(const t_cola *c, void *d)
{
    if (c->cantElem == 0)
        return COLA_VACIA;

    memmove(d, c->cola[c->primero], c->tamElem);
    return SUCCESS;
}
