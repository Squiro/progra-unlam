#ifndef LISTA_CIRC_H_
#define LISTA_CIRC_H_

#include <stdlib.h>
#include <stdio.h>

#define SUCCESS 0
#define COLA_VACIA 99
#define SIN_MEM 98

typedef int t_dato;

typedef int (*t_cmp)(const void *, const void *);

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

void crearLista(t_lista * pl);
int listaVacia(t_lista * pl);
int insertarPrincipio(t_lista * pl, t_dato * d);

/* cola circ */

void crearCola(t_lista * pl);
int colaLlena(t_lista * pl);
int colaVacia(t_lista * pl);
int verTopeCola(t_lista * pl, t_dato * d);
int acolar(t_lista * pl, t_dato * d);
int desacolar(t_lista * pl, t_dato * d);
void vaciarCola(t_lista * pl);



#endif // LISTA_CIRC_H_
