#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

#define ERROR_ABRIR 99

typedef struct
{
    int dni;
    char apyn[50];
    char sex;
    char estado;
} t_alumno;

int generarArchivoAlum(char * ruta);
int mostrarArchivoAlum(char * ruta);

int generarIndice(t_arbol * pa, char * rutaAlum, char * rutaIdx);
void generarArchivoIndice(t_arbol * pa, FILE * arch);
int mostrarIndice(char * rutaIdx);

int alta(t_arbol * pa, char * rutaAlum, char * rutaIdx);
void ingresarAlumno(t_alumno * alum);
int baja(t_arbol * pa, char * rutaAlum, char * rutaIdx);
int modificarAlumno(char * rutaAlum, int offset);

#endif // FUNCIONES_H_
