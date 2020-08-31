#ifndef LISTA_H_
#define LISTA_H_

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define LISTA_VACIA 98
#define NO_ENCONTRADO 97
#define SUCCESS 0

typedef int t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

typedef int (*t_cmp)(const void *, const void *);

void crearLista(t_lista *pl);
int insertarOrdenado(t_lista *pl, const t_dato *d, t_cmp comparar);
int insertarPrincipio(t_lista *pl, const t_dato *d);
int insertarFinal(t_lista *pl, const t_dato *d);
int quitarPrimero(t_lista *pl, t_dato *d);
int quitarUltimo(t_lista *pl, t_dato *d);
int quitarClave(t_lista *pl, t_dato *d, t_cmp comparar);
int quitarDuplicados(t_lista *pl, t_dato *d, t_cmp comparar);
int quitarTodosDuplicados(t_lista *pl, t_dato *d, t_cmp comparar);
int ordenarLista(t_lista *pl, t_cmp comparar);
t_lista * hallarMenor(t_lista *pl, t_cmp comparar);
void recorrerLista(t_lista *pl);
int compararEnteros(const void *, const void *);

#endif // LISTA_H_
