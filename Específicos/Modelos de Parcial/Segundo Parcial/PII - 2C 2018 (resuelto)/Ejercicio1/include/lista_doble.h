#ifndef LISTA_DOBLE_H_
#define LISTA_DOBLE_H_

#include <tipos.h>
#include <stdlib.h>
#include <stdio.h>

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
void recorrerAscdente(const t_lista * pl);
void recorrerDescendente(const t_lista * pl);
void mostrar(t_nodo_lista * alum);
int compararNombresAsc(const void *, const void *);

#endif // LISTA_DOBLE_H_
