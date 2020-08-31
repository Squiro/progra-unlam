#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbol.h"

#define ERROR_ABRIR 99

typedef struct
{
    int dni;
    char nombre[50];
    char apellido[50];
    char estado;
} t_alumno;


/** Genera un lote de pruebas para los alumnos */
int generarArchivoAlum(char * ruta);
int mostrarArchivoAlum(char * ruta);

/** Funciones relacionadas a generar y mostrar el indice */
int generarIndice(t_arbol * pa, char * rutaAlum, char * rutaIdx);
void generarArchivoIndice(t_arbol * pa, FILE * archIdx);
//int generarArchivoIndice(t_arbol * pa, char * rutaIdx);
int guardarEnIndice(const void * arg, const void * arg2);
int mostrarIndice(char * ruta);

/** Alta y baja */

int alta(t_arbol * pa, char * rutaAlum, char * rutaIdx);
void ingresarAlumno(t_alumno * alum);
int baja(t_arbol * pa, char * rutaAlum, char * rutaIdx);
int modificarAlumno(char * rutaAlum, int offset);
#endif // FUNCIONES_H_
