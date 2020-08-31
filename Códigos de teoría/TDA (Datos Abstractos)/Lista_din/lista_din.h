#ifndef LISTA_DIN_H_
#define LISTA_DIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define SIN_MEM 99
#define LISTA_VACIA 98
#define NOT_FOUND 97

typedef int (*t_cmp)(const void *, const void*);

typedef struct
{
    int id;
    char nombre[50];
} t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef t_nodo * t_lista;


/* Primitivas */

/** Inicializa la lista en nulo.
*/
void crearLista(t_lista *pl);

/** Inserta SIEMPRE al principio.
*/
int insertarPrincipio(t_lista *pl, const t_dato *d);

/** Inserta SIEMPRE al final.
*/
int insertarFinal(t_lista *pl, const t_dato *d);

/** Insertar en lista ordenadamente.
*/
int insertarOrdenado(t_lista *pl, const t_dato *d, t_cmp comparar);

int quitarPrimero(t_lista *pl, t_dato *d);

int quitarUltimo(t_lista *pl, t_dato *d);

int quitarClave(t_lista *pl, t_dato *d, t_cmp comparar);

int quitarDuplicados(t_lista *pl, t_cmp comparar);

int quitarTodosDuplicados(t_lista *pl, t_cmp comparar);

int quitarNoDuplicados(t_lista *pl, t_cmp comparar);

int ordernarLista(t_lista *pl, t_cmp comparar);

void * hallarMenor(t_lista *pl, t_cmp comparar);

int comparar(const void * arg1, const void * arg2);

int compararEmp(const void * arg1, const void * arg2);

void recorrerLista(t_lista *pl);
#endif // LISTA_DIN_H_
