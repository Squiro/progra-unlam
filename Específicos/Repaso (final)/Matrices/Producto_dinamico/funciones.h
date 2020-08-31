#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>

int * producto_matrices(int filMat1, int colMat1, int mat1[][colMat1], int filMat2, int colMat2, int mat2[][colMat2]);
void mostrarMatrizPuntero(int fil, int col, int *mat);
#endif // FUNCIONES_H_
