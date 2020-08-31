#include "funciones.h"

int productoMatrices(int mat1[][COL], int mat2[][COL], int filMat1, int colMat1, int filMat2, int colMat2)
{
    int i, j, k, acum = 0;

    if (colMat1 != filMat2)
    {
        printf("No se pueden multiplicar estas matrices. \nLa cantidad de col de la primera no coincide con la cant. de filas de la segunda.");
        return NO_VALIDO;
    }

    for (i = 0; i < filMat1; i++)
    {
      for (k = 0; k < colMat2; k++)
      {
        for (j = 0; j < colMat1; j++)
        {
          acum += mat1[i][j]*mat2[j][k];
        }
        printf("%d ", acum);
        acum = 0;
      }
    }

    return SUCCESS;
}

void mostrarMatriz(int mat[][COL], int fil, int col)
{
    int i, j;

    for (i = 0; i < fil; i++)
      for (j = 0; j < col; j++)
        printf("%d ", mat[i][j]);
}
