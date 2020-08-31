#ifndef LISTA_DOBLE_H_
#define LISTA_DOBLE_H_

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define SUCCESS 0

typedef struct
{
    int dni;
    char apyn[30];
    double sueldo;
} t_empleado;

typedef int t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
    struct s_nodo * ant;
} t_nodo;

typedef t_nodo * t_lista;

typedef int (*t_cmp)(const void *, const void *);

void crearLista(t_lista *pl);
int insertar(t_lista *pl, const t_dato *d, t_cmp comparar);
int insertarPrincipio(t_lista *pl, const t_dato *d);
int ordenarLista(t_lista *pl, t_cmp comparar);
t_nodo * hallarMenor(t_nodo *nodo, t_cmp comparar);
void mostrarLista(t_lista * pl);
int compararEnteros(const void *, const void *);

#endif // LISTA_DOBLE_H_
