#include "funciones.h"

int * producto_matrices(int filMat1, int colMat1, int mat1[][colMat1], int filMat2, int colMat2, int mat2[][colMat2])
{
    int i, j, k, acum = 0;
    if (colMat1 != filMat2)
    {
        fprintf(stderr, "Las matrices no pueden multiplicarse.");
        return NULL;
    }

    int(*res)[colMat2] = malloc (sizeof(int[filMat1][colMat2]));

    if (!res)
    {
        fprintf(stderr, "No hay espacio en memoria para almacenar el resultado");
        return NULL;
    }

    for (i = 0; i < filMat1; i++)
    {
        for (k = 0; k < colMat2; k++)
        {
            for (j = 0; j < colMat1; j++)
                acum += mat1[i][j] * mat2[j][k];

            res[i][k] = acum;
            acum = 0;
        }
    }

    return (int *) res;
}

void mostrarMatrizPuntero(int fil, int col, int *mat)
{
    int i, j;

    for (i = 0; i < fil; i++)
      for (j = 0; j < col; j++)
        printf("%d ", mat[i*col+j]);
}
