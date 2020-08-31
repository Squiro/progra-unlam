#ifndef PILA_H_
#define PILA_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 99
#define PILA_VACIA 98
#define SUCCESS 0

typedef int t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_pila;

void crearPila(t_pila *p);
int pilaLlena(const t_pila *p);
int pilaVacia(const t_pila *p);
int apilar(t_pila *p, const t_dato *d);
int desapilar(t_pila *p, t_dato *d);
int verTope(const t_pila *p, t_dato *d);
int vaciarPila(t_pila *p);

#endif // PILA_H_
