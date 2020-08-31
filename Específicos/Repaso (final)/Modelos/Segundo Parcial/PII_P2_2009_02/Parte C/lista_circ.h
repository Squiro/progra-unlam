#ifndef LISTA_CIRC_H_
#define LISTA_CIRC_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 99
#define COLA_VACIA 98
#define SUCCESS 1

typedef long t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

typedef int (*t_cmp)(const void *, const void *);

void crearCola(t_lista *pl);
int colaVacia(t_lista *pl);
int colaLlena(t_lista *pl);
int acolar(t_lista *pl, const t_dato *d);
int desacolar(t_lista *pl, t_dato *d);
int verTope(const t_lista *pl, t_dato *d);
void vaciarCola(t_lista *pl);
int eliminarNodo(t_lista *pl, const t_dato *d, t_cmp comparar);

int compararClientes(const void *arg1, const void *arg2);
#endif // LISTA_CIRC_H_
