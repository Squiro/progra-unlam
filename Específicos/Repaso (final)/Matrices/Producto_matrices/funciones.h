#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>

#define NO_VALIDO -1
#define SUCCESS 0

//int * producto_matrices(int filMat1, int colMat1, int mat1[][colMat1], int filMat2, int colMat2, int mat2[][colMat2]);
int producto_matrices(int filMat1, int colMat1, int mat1[][colMat1], int filMat2, int colMat2, int mat2[][colMat2], int matRes[][colMat2]);
void mostrarMatriz(int fil, int col, int mat[][col]);
void mostrarMatrizPuntero(int fil, int col, int *mat);

#endif // FUNCIONES_H_
