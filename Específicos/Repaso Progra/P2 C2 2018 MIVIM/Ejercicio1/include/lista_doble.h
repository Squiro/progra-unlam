#ifndef LISTA_DOBLE_H_
#define LISTA_DOBLE_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <tipos.h>

typedef int (*t_comp)(const void *, const void *);

typedef struct l_nodo
{
    t_info info;
    struct l_nodo * sig;
    struct l_nodo * ant;
} t_nodo_lista;

typedef t_nodo_lista * t_lista;

void crearLista(t_lista * pl);
int insertarOrdenado(t_lista * pl, const t_info * d, t_comp comparar);
void recorrerAscendente(const t_lista * pl);
void recorrerDescendente(const t_lista * pl);
void mostrar(t_info * alum);
int compararNombresAsc(const void * arg1, const void * arg2);

#endif // LISTA_DOBLE_H_
