#ifndef PILAESTGEN_H_
#define PILAESTGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 100
#define SIN_MEM 99
#define PILA_VACIA 98
#define SUCCESS 0

//typedef int t_dato;

typedef struct s_nodo
{
    void * dato;
    struct s_nodo * sig;
} t_nodo;

typedef struct
{
    int tamElem;
    t_nodo* pila;
} t_pila;

// /!\ Las primitivas no pueden llamarse entre sí. Por algo son primitivas.

/** Inicializa la pila seteando al primer nodo en null.
*/
void crearPila(t_pila *p, int tamElem);

/** Verifica si la pila llegó a su máxima capacidad haciendo un falso chequeo de memoria.
*   Solo existe por retrocompatibilidad.
*/
int pilaLlena(const t_pila *p);

/** Verifica si la pila se encuentra sin elementos.
*/
int pilaVacia(const t_pila *p);

/** Mira el tope de la pila. El último dato ingresado.
*/
int verTope(const t_pila *p, void * d);

/** Apila
*/
int apilar(t_pila *p, const void *d);

/** Desapila
*/
int desapilar(t_pila *p, void *d);

/** Vacia completamente la pila, elemento por elemento
*/
void vaciarPila(t_pila *p);
#endif // PILAESTGEN_H_
