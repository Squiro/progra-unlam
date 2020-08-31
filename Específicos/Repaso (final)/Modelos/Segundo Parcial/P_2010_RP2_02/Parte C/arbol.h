#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define SUCCESS 1

typedef struct
{
    long nroCta;
    long nroReg;
} t_etiqueta;

typedef t_etiqueta t_dato;

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
void guardarEnOrden(t_arbol *pa, FILE *arch);
int compararCuentas(const void *, const void *);

#endif // ARBOL_H_
