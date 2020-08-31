#ifndef LISTA_DOBLE_H_
#define LISTA_DOBLE_H_

#include "tipos.h"
#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define NO_ENCONTRADO -1
#define SUCCESS 0

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
    struct s_nodo * ant;
} t_nodo;

typedef t_nodo * t_lista;

void crearLista(t_lista * pl);
int insertar(t_lista * pl, const t_dato *d, t_cmp comparar);
int buscarElemento(t_lista * pl, t_dato *d, t_cmp comparar);
int compararDNI(const void *, const void *);

#endif // LISTA_DOBLE_H_
