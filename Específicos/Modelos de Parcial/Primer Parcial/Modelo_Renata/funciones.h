#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define ERROR_ABRIR 99
#define SUCCESS 0

int calcularSumaPolinomios();
int leerPolinomio(const char * ruta, char * cadena, int tam);
int guardarEnLista(t_lista * lista, char * polinomio);
int sumarExpDuplicados(t_lista * pl, t_cmp comparar);
int sumarPolinomios(t_lista * poliP, t_lista * poliQ, t_lista * resultado, t_cmp comparar);
int guardarResultado(t_lista *pl, FILE * arch);

int compararTerminos(const void *arg1, const void *arg2);

char * mi_atoi(char * cadena, int * entero);
#endif // FUNCIONES_H_
