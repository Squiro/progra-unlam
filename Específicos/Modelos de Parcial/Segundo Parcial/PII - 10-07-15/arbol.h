#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define NOT_FOUND 404
#define SUCCESS 0

/** Funciones parametrizadas */

typedef int (*t_cmp)(const void *, const void *);
typedef int (*t_accion)(const void *, const void *);

typedef struct
{
    int dni;
    int numReg;
} t_indice;

typedef t_indice t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * izq;
    struct s_nodo * der;
} t_nodo;

typedef t_nodo * t_arbol;

/** Primitivas */
void crearArbol(t_arbol * pa);
int insertarOrdenado(t_arbol * pa, t_dato * d, t_cmp comparar);
int buscarClave(t_arbol * pa, t_dato * d, t_cmp comparar, t_accion);
int alturaArbol(const t_arbol * pa);

/** Recorridos */

void inOrden(t_arbol * pa, t_accion accion);

/** Utilidades */

int compararDNI(const void * arg1, const void * arg2);
int extraerNodo(const void * arg1, const void * arg2);
int borrarNodo(const void * arg, const void * arg2);
t_dato buscarMin(t_arbol * pa);


int eliminar_de_arbol(t_arbol *pa, t_dato *d, t_cmp comparar);
int eliminar_raiz(t_arbol *pa);
t_arbol * buscarMayor(t_arbol * pa);
t_arbol * buscarMenor(t_arbol * pa);

#endif // ARBOL_H_
