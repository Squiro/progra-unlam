#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_ASSIGN 99

typedef int (*t_cmp)(const void*, const void*);

void seleccion(void *array, int cantElem, int tamElem, t_cmp);
void mostrarVector(int vec[], int size);
int compararEnteros(const void*, const void *);
int intercambio(void * array, void * pMenor, int tamElem);
void * hallarPosMenor(void *currentPos, const void *pFinal, int tamElem, t_cmp);

#endif // FUNCIONES_H_
