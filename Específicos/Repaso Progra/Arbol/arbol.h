#ifndef ARBOL_H_
#define ARBOL_H_

#include <stdlib.h>
#include <stdio.h>

#define SIN_MEM 99
#define DUPLICADO 98
#define SUCCESS 0

typedef int (*t_cmp)(const void *, const void *);
typedef void (*t_accion)(const void *);

typedef struct
{
    int dni;
    char apyn[50];
    char sex;
} t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * izq;
    struct s_nodo * der;
} t_nodo;

typedef t_nodo * t_arbol;


void crearArbol(t_arbol * pa);
int arbolVacio(const t_arbol * pa);
int arbolLleno(const t_arbol * pa);
int alturaArbol(const t_arbol * pa);
void cortarHojas(t_arbol * pa);
void podarHastaNivel(t_arbol * pa, int nivel);
void podarHastaAltura(t_arbol * pa, int nivel);
void eliminarArbol(t_arbol * pa);
int eliminarDeArbol(t_arbol * pa, t_dato * d, t_cmp comparar);
void eliminarRaiz(t_arbol * pa);
void preOrden(t_arbol * pa, t_accion accion);
void inOrden(t_arbol * pa, t_accion accion);
void posOrden(t_arbol * pa, t_accion accion);
int insertar(t_arbol * pa, const t_dato * d, t_cmp comparar);
int insertarIterativo(t_arbol * pa, const t_dato * d, t_cmp comparar);
int hallarNodo(const t_arbol * pa, t_dato * d, t_cmp comparar);
t_arbol * buscarMenor(t_arbol * pa);
t_arbol * buscarMayor(t_arbol * pa);
#endif // ARBOL_H_
