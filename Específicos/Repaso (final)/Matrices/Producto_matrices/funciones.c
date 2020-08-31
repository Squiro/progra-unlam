#include "funciones.h"

int producto_matrices(int filMat1, int colMat1, int mat1[][colMat1], int filMat2, int colMat2, int mat2[][colMat2], int matRes[][colMat2])
{
    int i, j, k, acum = 0, offset;

    if (colMat1 != filMat2)
        return -1;

    /*int * res = (int *) malloc((filMat1*colMat2)*sizeof(int));

    if (!res)
        return NULL;*/

    for (i = 0; i < filMat1; i++)
    {
        for (k = 0; k < colMat2; k++)
        {
            for (j = 0; j < colMat1; j++)
                acum += mat1[i][j] * mat2[j][k];

            offset = i * colMat2 + k;
            //res[offset] = acum;
            matRes[i][k] = acum;
            //printf("%d OFF: %d\n", res[offset], offset);
            acum = 0;
        }
    }

    //return res;
    return SUCCESS;
}

void mostrarMatriz(int fil, int col, int mat[][col])
{
    int i, j;

    for (i = 0; i < fil; i++)
      for (j = 0; j < col; j++)
        printf("%d ", mat[i][j]);
}

void mostrarMatrizPuntero(int fil, int col, int *mat)
{
    int i, j;

    for (i = 0; i < fil; i++)
      for (j = 0; j < col; j++)
        printf("%d ", mat[i*col+j]);
}
