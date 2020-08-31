#ifndef LISTA_DOBLE_H_
#define LISTA_DOBLE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define LISTA_VACIA 97
#define SUCCESS 0

typedef int (*t_cmp)(const void *, const void *);

typedef struct
{
    char clave[41];
    char pci[20];
    char ciu[20];
    char loc[20];
    int cantH;
} t_localidad;

typedef t_localidad t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * ant;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;

/** Primitivas */

void crearLista(t_lista * pl);
int listaLlena(const t_lista * pl);
int listaVacia(const t_lista * pl);
int insertarFinal(t_lista * pl, t_dato * d);
int insertarOrdenado(t_lista * pl, t_dato * d, t_cmp comparar);

/** Utilidades */
int cambiarNombreLocalidad(t_lista * pl, char * str);
int ordenarLista(t_lista * pl);
void * hallarMenor(t_nodo * actual, t_dato * d);
void mostrar(t_lista * pl);
int compararClaves(const void * arg1, const void * arg2);


#endif // LISTA_DOBLE_H_
