#ifndef LISTA_SIMP_H_
#define LISTA_SIMP_H_

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define LISTA_VACIA 98
#define SUCCESS 0

typedef char * t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

typedef int (*t_cmp)(const void *, const void *);

void crearLista(t_lista *pl);
int listaVacia(const t_lista *pl);
int insertar(t_lista *pl, const t_dato *d, t_cmp comparar);
int sacarPrimero(t_lista *pl, t_dato *d);
void vaciarLista(t_lista *pl);

#endif // LISTA_SIMP_H_
