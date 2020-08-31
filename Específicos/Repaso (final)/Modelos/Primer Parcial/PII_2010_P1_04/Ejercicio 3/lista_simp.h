#ifndef LISTA_SIMP_H_
#define LISTA_SIMP_H_

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define SUCCESS 1

typedef struct
{
    int nroPedido;
    char nroArticulo[10];
    int cant;
    float precioUnit;
} t_pedido;

typedef t_pedido t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

typedef int (*t_cmp)(const void *, const void *);

void crearLista(t_lista *pl);
int listaVacia(const t_lista *pl);
int insertarOrdenado(t_lista *pl, const t_dato *d, t_cmp comparar);
int actualizarInfo(t_lista *pl, const t_dato *d, t_cmp comparar);
int quitarPrimero(t_lista *pl, t_dato *d);

int compararPedidos(const void *, const void *);
int compararArticulos(const void *arg1, const void *arg2);
int mi_atoi(char *str);

#endif // LISTA_SIMP_H_
