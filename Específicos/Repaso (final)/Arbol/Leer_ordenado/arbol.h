#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define SUCCESS 0

typedef struct
{
    int dni;
    char apyn[30];
    double sueldo;
} t_empleado;

typedef t_empleado t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * izq;
    struct s_nodo * der;
} t_nodo;

typedef t_nodo * t_arbol;

typedef int (*t_cmp)(const void *, const void *);
typedef void (*t_accion)(const void *);

void crearArbol(t_arbol *pa);
int insertar(t_arbol *pa, const t_dato *d, t_cmp comparar);
void recorrerEnOrden(t_arbol *pa, t_accion accion);
void leerEnOrden(t_arbol *pa, FILE * arch, int ini, int fin, t_cmp comparar);

void mostrar(const void *);
int compararDNI(const void *, const void *);
#endif // ARBOL_H_
