#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include "arbol.h"

#define ERROR_ARCH 99

typedef struct
{
    int dni;
    char apyn[30];
    double sueldo;
} t_empleado;

int generarLote(char * ruta);
int guardarIndiceEnArbol(t_arbol *pa, char * ruta);
int generarArchivoIndice(t_arbol *pa, char *rutaIdx);
void escribirArchivoIndice(t_arbol *pa, FILE * arch);
int ordenarArchivo(char *rutaEmp, char * rutaIdx, char *rutaRes);
int mostrarArchivo(char * ruta);

#endif // FUNCIONES_H_
