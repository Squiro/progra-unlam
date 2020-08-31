#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LISTA_VACIA -1
#define TODO_OK 1
#define SIN_MEM -1
typedef struct
{
    char pci[20];
    char ciu[20];
    char loc[20];
    int cantH;
}t_dato;
typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * ant;
    struct s_nodo * sig;
}t_nodo;
typedef t_nodo * t_lista;
typedef int(*t_cmp)(const void *,const void *);

int comparaProvCiu(const void *,const void *);
void crear_lista(t_lista *);
int ordenarListaDoble(t_lista * pl,t_cmp );
void intercambio(t_nodo **,t_nodo **);

int insertarDesordenado(t_lista *,const t_dato *);

void mostrarLista(const t_lista *);

int insertarListaDobleOrdenada(t_lista *, const t_dato *,t_cmp);

int recorreYactualiza(t_lista *);
int recorreYborraDuplis(t_lista *);




#endif // HEADER_H_INCLUDED
