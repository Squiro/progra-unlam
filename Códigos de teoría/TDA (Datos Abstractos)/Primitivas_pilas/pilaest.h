#ifndef PILAEST_H_
#define PILAEST_H_

#include <stdio.h>
#include <stdlib.h>

#define TAM_PILA 100
#define PILA_LLENA 0
#define SUCCESS 1
#define PILA_VACIA 0

typedef int t_dato;

typedef struct
{
    t_dato pila[TAM_PILA];
    int tope;
} t_pila;

/**
* Inicializa la pila.
*
*/
void crearPila(t_pila *pila);

int pilaVacia(const t_pila *p);

int pilaLlena(const t_pila *p);

//Recibe una pila y una direccion
int apilar(t_pila *p, const t_dato *d);

int verTope(const t_pila *p, t_dato *d);

int desapilar(t_pila *p, t_dato *d);

void vaciarPila(t_pila *p);
#endif // FUNCIONES_H_


