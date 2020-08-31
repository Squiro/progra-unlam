#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_ABRIR 99

int generarLote();

int leerLote();

int esMultiplo5(char *cadena);

int esMultiplo6(const char *cadena);

int esMultiplo11(char *cadena);

int esMayorA(const char *cadena, int num);

int guardarArchivo(char *ruta, const char *cadena);

#endif // FUNCIONES_H_
