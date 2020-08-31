#ifndef PILADIN_H_
#define PILADIN_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 99
#define SIN_PILA 98
#define PILA_VACIA 97
#define SUCCESS 1

//typedef struct { } t_algo;

typedef int t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *sig; //Siguiente
} t_nodo;

typedef t_nodo* t_pila; //t_nodo* se va a interpretar como t_pila, y viceversa

void crearPila(t_pila *p);

int apilar(t_pila *p, const t_dato *d);

int desapilar(t_pila *p, t_dato *d);

int pilaVacia(const t_pila *p);

void vaciarPila(t_pila *p);

int verTope(const t_pila *p, t_dato *d);
#endif // PILADIN_H_
