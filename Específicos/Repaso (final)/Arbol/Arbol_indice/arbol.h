#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define SUCCESS 0

typedef struct
{
    int dni;
    long numReg;
} t_indice;

typedef t_indice t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * izq;
    struct s_nodo * der;
} t_nodo;

typedef t_nodo * t_arbol;

typedef int (*t_cmp)(const void *, const void *);

void crearArbol(t_arbol *pa);
int insertar(t_arbol *pa, const t_dato *d, t_cmp comparar);
void vaciarArbol(t_arbol *pa);

int compararEnteros(const void *arg1, const void *arg2);

#endif // ARBOL_H_
