#ifndef LISTA_H_
#define LISTA_H_

#include <tipos.h>
#include <stdlib.h>
#include <stdio.h>

typedef int (*t_comp)(const void *, const void *);

typedef struct l_nodo
{
  t_info info;
  struct l_nodo * sig;
} t_nodo_lista;

typedef t_nodo_lista * t_lista;

void crearLista(t_lista * pl);
int insertarOrdenado(t_lista * pl, const t_info * d, t_comp comparar);
void mostrarLista(t_lista * pl);
void vaciarLista(t_lista * pl);
int verPrimero(t_lista * pl, t_info * d);
int compararNombresAsc(const void *, const void *);
int compararNombresDesc(const void *, const void *);
int compararPromedio(const void *, const void *);

#endif // LISTA_H_
