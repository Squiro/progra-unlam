#ifndef COLAEST_GEN_H_
#define COLAEST_GEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_COLA 20
#define COLA_LLENA 99
#define COLA_VACIA 98
#define SUCCESS 0

typedef struct
{
    int tamElem;
    void * cola[TAM_COLA];
    int cantElem;
    int ultimo;
    int primero;
} t_cola;


/** Inicializamos la cola seteando los valores de primero, ultimo, y cantElem.
*/
void crearCola(t_cola *c, int tamElem);

/** Vacia toda la cola seteando los valores de primero, ultimo, y cantElem.
*/
void vaciarCola(t_cola *c);

/** Verifica si la cola está llena comparando con cantElem.
*/
int colaLlena(const t_cola *c);

/** Verifica si la cola está vacía comparando con cantElem.
*/
int colaVacia(const t_cola *c);

/** Acola el dato que llega
*/
int acolar(t_cola *c, const void *d);

/** Desacola el primer dato a atender.
*/
int desacolar(t_cola *c, void *d);

/** Muestra el primer dato a atender sin desacolarlo.
*/
int verTope(const t_cola *c, void *d);
#endif // COLAEST_GEN_H_
