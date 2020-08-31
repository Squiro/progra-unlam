#ifndef COLAGEN_H_
#define COLAGEN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define COLA_VACIA 99
#define COLA_LLENA 98
#define SIN_MEM 97

typedef struct s_nodo
{
    void * dato;
    struct s_nodo * sig;
} t_nodo;

typedef struct
{
    int tamElem;
    t_nodo * primero;
    t_nodo * ultimo;
} t_cola;

/** Inicializa la cola.
*/
void crearCola(t_cola *c, int tamElem);

/** Verifica si la cola está llena haciendo un falso chequeo de memoria.
*   Solo existe por retrocompatibilidad.
*/
int colaLlena(const t_cola *c);

/** Verifica si la cola no tiene ningún elemento.
*/
int colaVacia(const t_cola *c);

/** Agarra el primer elemento de la cola y lo guarda en d, sin desencolarlo.
*/
int verTope(const t_cola *c, void *d);

/** Encola el dato que llegue
*/
int acolar(t_cola *c, const void *d);

/** Y a vos qué te parece que hace.
*/
int desacolar(t_cola *c, void *d);

/** Vacía toda la cola.
*/
void vaciarCola(t_cola *c);
#endif // COLAGEN_H_
