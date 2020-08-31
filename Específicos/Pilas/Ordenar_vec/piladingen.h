#ifndef PILADINGEN_H_
#define PILADINGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN_MEM 99
#define PILA_LLENA 98
#define PILA_VACIA 97
#define SUCCESS 0

typedef int (*t_cmp)(const void *, const void *);

typedef struct s_nodo
{
    void * dato;
    struct s_nodo * sig;
} t_nodo;

typedef struct
{
    int tamElem;
    t_nodo * pila;
} t_pila;

void crearPila(t_pila *p, int tamElem);

int pilaLlena(const t_pila *p);

int pilaVacia(const t_pila *p);

int apilar(t_pila *p, const void *d);

int desapilar(t_pila *p, void *d);

int verTope(const t_pila *p, void *d);

int vaciarPila(t_pila *p);

int ordenarPila(t_pila *p, t_cmp comparar);

void * hallarMayor(t_nodo *nodo, t_cmp comparar);

int compararEnteros(const void *arg1, const void *arg2);

#endif // PILADINGEN_H_
