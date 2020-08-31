#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define COL 100
#define NO_VALIDO -1
#define SUCCESS 0

#include <stdio.h>
#include <stdlib.h>

int productoMatrices(int mat1[][COL], int mat2[][COL], int filMat1, int colMat1, int filMat2, int colMat2);
void mostrarMatriz(int mat[][COL], int fil, int col);

#endif // FUNCIONES_H_
