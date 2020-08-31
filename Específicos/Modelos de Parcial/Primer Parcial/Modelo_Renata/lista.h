#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 98
#define LISTA_VACIA 97
#define LISTA_LLENA 96

typedef int (*t_cmp)(const void *, const void *);

typedef struct
{
    int coef;
    int exp;
} t_termino;

typedef t_termino t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

/** Primitivas de Lista */

void crearLista(t_lista *pl);

int insertarPrimero(t_lista *pl, const t_dato *d);

int insertarFinal(t_lista *pl, const t_dato *d);

int insertarOrdenadoAsc(t_lista *pl, const t_dato *d, t_cmp comparar);

int quitarClave(t_lista *pl, t_dato *d);

void recorrerLista(t_lista *pl);
#endif // LISTA_H_
