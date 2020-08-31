#ifndef COLA_H_
#define COLA_H_

#include <stdio.h>
#include <stdlib.h>

#define SIN_MEM 99
#define COLA_VACIA 98
#define SUCCESS 1

typedef long int t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo * sig;
} t_nodo;

typedef struct
{
    t_nodo * primero;
    t_nodo * ultimo;
} t_cola;

void crearCola(t_cola * c);
int colaVacia(t_cola *c);
int colaLlena(t_cola *c);
int acolar(t_cola *c, const t_dato *d);
int desacolar(t_cola *c, t_dato *d);
int verTope(t_cola *c, t_dato *d);
void vaciarCola(t_cola *c);

#endif // COLA_H_
