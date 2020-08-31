#ifndef ARBOL_H_
#define ARBOL_H_

#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define NO_ENCONTRADO -1
#define SUCCESS 0

typedef struct
{
    long dni;
    unsigned long pos;
} t_indice;

typedef t_indice t_info;

typedef struct a_nodo
{
    t_info dato;
    struct a_nodo * izq;
    struct a_nodo * der;
} t_nodo;

typedef t_nodo * t_arbol;

void crearArbol(t_arbol * pa);
int alturaArbol(t_arbol *pa);
int insertar_arbol_bin(t_arbol * pa, const t_info *d, t_cmp comparar);
int eliminar_de_arbol(t_arbol * pa, t_info *d, t_cmp comparar);
int eliminar_raiz(t_arbol *pa);
t_arbol * buscarMayor(t_arbol * pa);
t_arbol * buscarMenor(t_arbol * pa);

#endif // ARBOL_H_
