#include "funciones.h"

int sumatoriaArribaDP(int mat[][COL], int fil, int col, int incluir)
{
    int i, j, sum = 0;

    for (i = 0; i < fil; i++)
        for (j = i; j < col; j++)
        {
            if (i != j || incluir)
                sum += mat[i][j];

        }

    return sum;
}

int sumatoriaArribaDS(int mat[][COL], int fil, int col, int incluir)
{
    int i, j, sum = 0;

    for (i = 0; i < fil; i++)
        for (j = 0; j < col-i; j++)
        {
            if (j != (col-1)-i || incluir)
                sum += mat[i][j];
        }

    return sum;
}

int sumatoriaAbajoDP(int mat[][COL], int fil, int col, int incluir)
{
    int i, j, sum = 0;

    for (i = 0; i < fil; i++)
        for (j = 0; j < i+1; j++)
        {
            if (i != j || incluir)
                sum += mat[i][j];

        }

    return sum;
}

int sumatoriaAbajoDS(int mat[][COL], int fil, int col, int incluir)
{
    int i, j, sum = 0;

    for (i = fil-1; i >= 0; i--)
        for (j = (col-1)-i; j < col; j++)
        {
            if (j != (col-1)-i || incluir)
            {
                printf("I: %d, J: %d\n", i, j);
                sum += mat[i][j];
            }

        }

    return sum;
}
