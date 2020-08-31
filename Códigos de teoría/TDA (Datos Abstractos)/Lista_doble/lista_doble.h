#ifndef LISTA_DOBLE_H_
#define LISTA_DOBLE_H_

#include <stdio.h>
#include <stdlib.h>

#define NOT_FOUND 404
#define SIN_MEM 99
#define LISTA_LLENA 98
#define LISTA_VACIA 97
#define DATO_DUPLICADO 96
#define SUCCESS 0

typedef int (*t_cmp)(const void *, const void *);

typedef int t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
    struct s_nodo * ant;
} t_nodo;

typedef t_nodo * t_lista;

void crearLista(t_lista *pl);

int insertarOrdenado(t_lista *pl, const t_dato *d, t_cmp comparar);

int eliminarClave(t_lista *pl, t_dato *d, t_cmp comparar);

int eliminarDuplicados(t_lista *pl, t_cmp comparar);

int ordenarLista(t_lista *pl, t_cmp comparar);

t_nodo * hallarMenor(t_nodo *actual, t_cmp comparar);

int verActual(t_lista *pl, t_dato *d);

int compararEnteros(const void *arg1, const void *arg2);

/*
    Eliminar duplicados en lista ordenada o desordenada.
    Eliminar no duplicados en lista ordenada o desordenada.
    ETC.
*/

#endif // LISTA_DOBLE_H_
