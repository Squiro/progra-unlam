#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

#define ERROR_ARCH 99

char * leerNum(char * ruta);
int guardarEnPila(t_pila *p, char *str);
int sumarPilas(t_pila *pila1, t_pila *pila2, t_pila *pila3);
char * stackToStr(t_pila *p);

#endif // FUNCIONES_H_
