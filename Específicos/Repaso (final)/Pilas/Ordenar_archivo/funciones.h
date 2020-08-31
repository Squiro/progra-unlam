#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include "pila.h"

#define ERROR_ARCH 99

typedef int (*t_cmp)(const void *, const void *);

int generarLote();
int guardarEnPila(t_pila *p, char * ruta);
int generarResultado(t_pila *p, char * ruta);
int ordenarPila(t_pila *p, t_cmp comparar);
int mostrarArchivo(char * ruta);
int compararDNI(const void *, const void *);

#endif // FUNCIONES_H_
