#ifndef LISTA_CIRC_H_
#define LISTA_CIRC_H_

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define COLA_VACIA 98
#define SUCCESS 0


typedef struct
{
    int numero;
    char * str;
} t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

typedef int (*t_cmp)(const void *, const void *);

void crearCola(t_lista *pl);
int colaLlena(const t_lista *pl);
int colaVacia(const t_lista *pl);
int acolar(t_lista *pl, const t_dato *d);
int desacolar(t_lista *pl, t_dato *d);
int verTope(const t_lista *pl, t_dato *d);
void vaciarCola(t_lista *pl);

#endif // LISTA_CIRC_H_
