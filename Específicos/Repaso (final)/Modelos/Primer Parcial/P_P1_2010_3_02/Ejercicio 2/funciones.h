#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

#define ERROR_ARCH 99

int procesarPasajes();
void ingresarCodigo(char * codEvent);
void ingresarID(long * id);
int generarArchivo(t_cola *c);

#endif // FUNCIONES_H_
