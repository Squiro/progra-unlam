#ifndef PILADIN_H_
#define PILADIN_H_

#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"


#define SIN_MEM 99
#define SIN_PILA 98
#define PILA_VACIA 97
//#define SUCCESS 1

typedef t_nodo * t_pdato;

typedef struct s_pnodo
{
    t_pdato dato;
    struct s_pnodo *sig; //Siguiente
} t_pnodo;

typedef t_pnodo* t_pila; //t_nodo* se va a interpretar como t_pila, y viceversa

void crearPila(t_pila *p);

int apilar(t_pila *p, const t_pdato *d);

int desapilar(t_pila *p, t_pdato *d);

int pilaVacia(const t_pila *p);

void vaciarPila(t_pila *p);

int verTope(const t_pila *p, t_pdato *d);
#endif // PILADIN_H_
