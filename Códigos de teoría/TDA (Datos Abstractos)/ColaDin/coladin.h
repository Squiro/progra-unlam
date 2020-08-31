#ifndef COLADIN_H_
#define COLADIN_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 99
#define COLA_VACIA 98
#define SUCCESS 0

/* En el main, necesito dos punteros a t_nodo *, pri y ult.
*/
typedef int t_dato;

typedef struct s_nodo
{
  t_dato dato;
  struct s_nodo * sig;
} t_nodo;

typedef struct
{
  t_nodo * primero;
  t_nodo * ultimo;
} t_cola;

/* Primitivas */

/** Inicializamos la cola.
*/
void crearCola(t_cola *c);

void vaciarCola(t_cola *c);

int colaLlena(const t_cola *c);

int colaVacia(const t_cola *c);

int acolar(t_cola *c, const t_dato *d);

int desacolar(t_cola *c, t_dato *d);

/** verPrimero (duh)
*/
int verTope(const t_cola *c, t_dato *d);
#endif // COLADIN_H_
