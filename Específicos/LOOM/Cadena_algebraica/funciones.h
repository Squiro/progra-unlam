#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include "piladingen.h"

int calcularResultado(char * cadena);
int convertirACodigo(char * op);
int apilarOperador(t_pila *p, char *op);

#endif // FUNCIONES_H_
