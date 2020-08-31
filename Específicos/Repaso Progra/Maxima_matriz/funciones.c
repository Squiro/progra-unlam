#include "funciones.h"

void maximaMatrizDesde(int mat[][COL], int filas, int columnas, int posI, int posJ)
{
    int limFilas, limColumnas, i, j, limI, limJ;

    filas--;
    columnas--;
    posI--;
    posJ--;

    if (posI <= filas/2)
    {
        limFilas = filas;
        limI = posI;
    }
    else
    {
        limFilas = posI;
        limI = 0;
    }

    if (posJ <= columnas/2)
    {
        limColumnas = columnas;
        limJ = posJ;
    }
    else
    {
        limColumnas = posJ;
        limJ = 0;
    }

    for (i = limI; i <= limFilas; i++)
        for (j = limJ; j <= limColumnas; j++)
            printf("%d ", mat[i][j]);

}
