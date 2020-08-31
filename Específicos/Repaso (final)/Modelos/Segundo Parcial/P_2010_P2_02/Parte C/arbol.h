#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 99
#define SUCCESS 0

typedef int t_dato;

typedef struct a_nodo
{
    t_dato dato;
    struct a_nodo * izq;
    struct a_nodo * der;
} t_nodo;

typedef t_nodo * t_arbol;

int alturaArbol(t_arbol *pa);
int arbolBalanceado(t_arbol *pa);
int esBalanceado(t_arbol *pa, int altura);
int arbolCompleto(t_arbol *pa);
int esCompleto(t_arbol *pa, int altura);
#endif // ARBOL_H_
