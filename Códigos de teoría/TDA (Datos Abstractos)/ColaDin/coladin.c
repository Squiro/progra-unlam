#include "coladin.h"

void crearCola(t_cola *c)
{
  c->primero = NULL;
  c->ultimo = NULL;
}

void vaciarCola(t_cola *c)
{
  t_nodo * auxPri = c->primero;

  while (auxPri)
  {
    c->primero = c->primero->sig;
    free(auxPri);
    auxPri = c->primero;
  }

  c->ultimo = NULL;
}

int colaLlena(const t_cola *c)
{
  //t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));
  void * nuevo = malloc(sizeof(t_nodo));

  free(nuevo);
  return !nuevo;
}

int colaVacia(const t_cola *c)
{
  return c->primero == NULL;
}

/*
    Pasos para acolar:

    1.- Reservo memoria para un nodo. Si no hay, retorno SIN MEM.
    2.- Pongo el dato en el nuevo.
    3.- Al siguiente le pongo null.
    4.- Si el ultimo es nulo, al primero le pongo nuevo.
        Si el ultimo no es nulo, al siguiente del ultimo le pongo nuevo.
    5.- Al ultimo le pongo el nuevo.
*/

int acolar(t_cola *c, const t_dato *d)
{
  t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

  if (!nuevo)
    return SIN_MEM;

    nuevo->dato = *d;
    nuevo->sig = NULL;

    if (!c->ultimo)
      c->primero = nuevo;
    else
      c->ultimo->sig = nuevo;
    c->ultimo = nuevo;

    return SUCCESS;
}

/*
  Pasos para desacolar:

  0.- Declaro aux, que apunta al primero
  1.- Pregunto si hay algo para desacolar (si el primero es !null)
  2.- Asignamos el dato
  3.- Al primero le ponemos el valor del siguiente (seria el nuevo primero)
  4.- Si el primero es nulo, tambien seteamos al ultimo como nulo
  5.- Liberamos aux
*/

int desacolar(t_cola *c, t_dato *d)
{
  t_nodo * aux = c->primero;

  if (!c->primero)
    return COLA_VACIA;

    *d = c->primero->dato;
    c->primero = c->primero->sig;

    if (!c->primero)
      c->ultimo = NULL;
    free(aux);

    return SUCCESS;
}

int verTope(const t_cola *c, t_dato *d)
{
  if (!c->primero)
    return COLA_VACIA;

  *d = c->primero->dato;
  return SUCCESS;
}
