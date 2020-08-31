#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_ABRIR 99
#define ERROR_APILAR 98
#define ERROR_SUMA 97

int leerNum(char *ruta, char *str);
int guardarEnPila(char *str, t_pila *pila);

/**
* Suma los contenidos de ambas pilas y los guarda en una tarcera pila
*
* Recibe como parámetros las tres pilas necesarias para el proceso.
* Las pilas se reciben como punteros, porque se trabajan de igual forma que las estructuras.
*/

int sumarPilas(t_pila *pila1, t_pila *pila2, t_pila *pila3);

int stackToFile(char *ruta, t_pila *pila);
int stackToStr(char *str, t_pila *pila);

#endif // FUNCIONES_H_
