#ifndef LISTA_CIRC_H_
#define LISTA_CIRC_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 99
#define PILA_VACIA 98
#define PILA_LLENA 97
#define COLA_VACIA 96
#define COLA_LLENA 95
#define LISTA_VACIA 94
#define LISTA_LLENA 93
#define SUCCESS 0

typedef int t_dato;

typedef int (*t_cmp)(const void *, const void *);

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

/** Primitivas Lista Circular */

void crear_lista(t_lista *pl);
int lista_vacia(t_lista *pl);
int insertar_al_principio(t_lista *pl, t_dato *d);
int insertar_al_final(t_lista *pl, t_dato *d);
int insertar_ordenado(t_lista *pl, t_dato *d, t_cmp comparar);
int quitar_del_principio(t_lista *pl, t_dato *d);
int * compararEnteros(const void *d1, const void *d2);



/** Primitivas Pila Circular */

void crearPila(t_lista *pl);
int pilaLlena(const t_lista *pl);
int pilaVacia(const t_lista *pl);
int verTopePila(const t_lista *pl, t_dato *d);
int apilar(t_lista *pl, const t_dato *d);
int desapilar(t_lista *pl, t_dato *d);
void vaciarPila(t_lista *pl);

/** Primitivas Cola Circular */

void crearCola(t_lista *pl);
int colaLlena(const t_lista *pl);
int colaVacia(const t_lista *pl);
int verTopeCola(const t_lista *pl, t_dato *d);
int acolar(t_lista *pl, const t_dato *d);
int desacolar(t_lista *pl, t_dato *d);
void vaciarCola(t_lista *pl);

#endif // LISTA_CIRC_H_
