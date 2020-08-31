#ifndef PILAEST_GEN_H_
#define PILAEST_GEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_PILA 100
#define SUCCESS 0
#define PILA_LLENA 99
#define PILA_VACIA 98

typedef struct
{
    int tamElem;
    void *pila[TAM_PILA];
    int tope;
} t_pila;


/** Inicializa la pila seteando tope en 0.
*/
void crearPila(t_pila *pila, int tamElem);

/** Verifica si la pila está vacía viendo el tope.
*/
int pilaVacia(const t_pila *p);

/** Verifica si la pila está llena viendo el tope.
*/
int pilaLlena(const t_pila *p);

/** Apila el dato que recibe por parametro
*/
int apilar(t_pila *p, const void *d);

/** Desapila el dato que se encuentra en el tope y lo guarda en d.
*/
int desapilar(t_pila *p, void *d);

/** Muestra el tope de la pila sin desapilarlo.
*/
int verTope(const t_pila *p, void *d);

/** Vacía la pila seteando el tope en 0.
*/
void vaciarPila(t_pila *p);
#endif // PILAEST_GEN_H_
