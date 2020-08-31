#ifndef LISTA_DOBLE_H_
#define LISTA_DOBLE_H

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define SUCCESS 0

typedef int (*t_cmp)(const void *, const void *);

typedef struct
{
    int dni;
    char apyn[50];
    char sex;
} t_alumno;

typedef t_alumno t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
    struct s_nodo * ant;
} t_nodo;

typedef t_nodo * t_lista;

void crearLista(t_lista * pl);
int insertar(t_lista * pl, const t_dato * d, t_cmp comparar);
int eliminarDuplicados(t_lista * pl, t_cmp comparar);
void mostrarLista(t_lista * pl);
int compararDNI(const void * arg1, const void * arg2);

#endif // LISTA_DOBLE_H_
