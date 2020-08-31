#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>

#define TAM 100

int chequearSuma(float mat[][TAM], int fil, int col);
float sumaTriangularSuperior(float mat[][TAM], int fil, int col);
float sumaTriangularInferior(float mat[][TAM], int fil, int col);

#endif // FUNCIONES_H_
