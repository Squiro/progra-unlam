#ifndef COLAEST_H_
#define COLAEST_H_

#include <stdio.h>
#include <stdlib.h>

#define TAM 4
#define COLA_LLENA 99
#define COLA_VACIA 98
#define SUCCESS 0

/*
  Las colas siguen este patr�n. Primero que entra, primero que sale: FIFO

  COLAS DE PRIORIDADES: son colas que tienen prioridades por sobre sus elementos. Primero
  se atienden aquellos elementos de prioridad m�xima, y as�.

  Voy revisando por las prioridades para ver a qui�n atender.

  COLA COM�N EST�TICA

  -Primer modelo:
    Siempre sale el que se encuentra primero. (POS 0)

    Necesito un tope para representar el �ltimo lugar que est� ocupado.

    La estructura de cola va a tener un vector y un tope (el ultimo elemento de la cola).

  -Segundo modelo:
    Ninguno de los elementos se mueve.

    El corte est� dado logicamente por los punteros de primero y ultimo.

    A la estructura necesito agregarle otro entero. Quedar�an: primero (frente) y ultimo (fondo).
    Al momento de inicializarlos, los puedo poner en (0, 0), (0, -1), (-1, -1), (-1, 0)... etc.
    El �ltimo queda posicionado en uno anterior al primero. Entonces usamos (0, -1).

    Cuando el �lt. est� en -1, no hay nadie en la cola.
    La cola est� llena cuando ultimo + 1 = primero... pero esto es mas complicado y complejo de preguntar.
    Para simplificar las cosas, agregamos una variable cantElem. Cuando est� llena ser� igual a TAM, cuando est�
    vac�a ser� 0.

*/

typedef struct
{
  int dni;
  char apyn[50];
  char sexo;
} t_persona;

typedef t_persona t_dato;

//typedef int t_dato;

typedef struct
{
  t_dato cola[TAM];
  int cantElem;
  int ultimo;
  int primero;
} t_cola;


/* Primitivas */

/** Inicializamos la cola.
*/
void crearCola(t_cola *c);

void vaciarCola(t_cola *c);

int colaLlena(const t_cola *c);

int colaVacia(const t_cola *c);

int acolar(t_cola *c, const t_dato *d);

int desacolar(t_cola *c, t_dato *d);

/** verPrimero (duh)
*/
int verTope(const t_cola *c, t_dato *d);
#endif // COLAEST_H_
