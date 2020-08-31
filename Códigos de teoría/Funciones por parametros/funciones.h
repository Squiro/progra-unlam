#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char nombre[50];
    char apellido[50];
    float sueldo;
} t_empleado;

int menorAMayor(const void *arg1, const void *arg2);
int mayorAMenor(const void *arg1, const void *arg2);
void mostrarVector(int vec[], int size);
int compararAND(const void *arg1, const void*arg2);
int compararDNA(const void *arg1, const void*arg2);
void mostrarEmpleados(t_empleado * emp, int size);
int compararDNAmayAMen(const void *arg1, const void*arg2);

#endif //FUNCIONES_H_
