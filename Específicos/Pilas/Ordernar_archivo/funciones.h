#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "piladingen.h"
#define ERROR_ABRIR 99

typedef int (*t_cmp)(const void *, const void *);

typedef struct
{
    int dni;
    char nombre[50];
    char apellido[50];
    float sueldo;
} t_empleado;

int generarLote();
int guardarEnPila(t_pila *p);
int ordenarPila(t_pila *p, t_cmp comparar);
int generarArchivo(t_pila *p);
int mostrarArchivo();
int compararEmpleados(const void * arg1, const void * arg2);
#endif // FUNCIONES_H_
