#include "funciones.h"

int chequearSuma(float mat[][TAM], int fil, int col)
{
    return sumaTriangularInferior(mat, fil, col) == sumaTriangularSuperior(mat, fil, col);
}

float sumaTriangularSuperior(float mat[][TAM], int fil, int col)
{
    float suma = 0;
    int i, j;

    for (i = 0; i < fil; i++)
        for (j = i; j < col; j++)
            suma += mat[i][j];

    printf("SUMA SUP: %f\n", suma);
    return suma;
}

float sumaTriangularInferior(float mat[][TAM], int fil, int col)
{
    float suma = 0;
    int i, j;

    for (i = 0; i < fil; i++)
        for (j = 0; j <= i; j++)
            suma += mat[i][j];
    printf("SUMA INF: %f\n", suma);
    return suma;
}
