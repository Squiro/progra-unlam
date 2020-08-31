#include "colaest.h"

void crearCola(t_cola *c)
{
  //Inicializamos los valores en 0, no nos importa "limpiar" lo que está dentro del vector
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
  return c->cantElem == TAM;
}

int colaVacia(const t_cola *c)
{
  return c->cantElem == 0;
}

/*
  Pasos para acolar:

  1.- Me fijo si la cola está llena.
  2. Incremento el ultimo.
  3. Incremento cantElem.
  4. Pongo el dato en la pos de ult.
*/

int acolar(t_cola *c, const t_dato *d)
{
  if (c->cantElem == TAM)
    return COLA_LLENA;

  //No podemos incrementar el ultimo si este está en el limite "fisico" del vector.
  /*if (c->ultimo == TAM-1)
    c->ultimo = 0;
  else
    c->ultimo++;*/

  c->ultimo = (c->ultimo+1)%TAM;

  c->cantElem++;
  c->cola[c->ultimo] = *d;

  return SUCCESS;
}

int desacolar(t_cola *c, t_dato *d)
{
  if (c->cantElem == 0)
    return COLA_VACIA;

  *d = c->cola[c->primero];
  c->primero = (c->primero+1)%TAM;

  /*if (c->primero != TAM-1)
    c->primero++;
  else
    c->primero = 0;*/

  c->cantElem--;

  return SUCCESS;
}

int verTope(const t_cola *c, t_dato *d)
{
  if (!c->cantElem)
    return COLA_VACIA;

  *d = c->cola[c->primero];

  return SUCCESS;
}
