#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define SUCCESS 1
#define NO_ENCONTRADO 0

typedef struct
{
    long nroCliente;
    char * email;
} t_indice;

typedef t_indice t_info;

typedef struct a_nodo
{
    t_info dato;
    struct a_nodo * izq;
    struct a_nodo * der;
} t_nodo_arbol;

typedef t_nodo_arbol * t_arbol;

typedef int (*t_cmp)(const void *, const void *);

void crearArbol(t_arbol *pa);
int insertar(t_arbol *pa, const t_info *d, t_cmp comparar);
char * buscarCliente(t_arbol *pa, t_info *d, t_cmp comparar);

#endif // ARBOL_H_
