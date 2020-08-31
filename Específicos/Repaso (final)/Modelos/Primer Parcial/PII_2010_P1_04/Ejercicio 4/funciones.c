#include "funciones.h"

int chequearSimetria(int mat[][TAM], int fil, int col)
{
    int i, j;
    for (i = 0; i < fil; i++)
        for (j = 0; j < col; j++)
            if (mat[i][j] != mat[j][i])
                return 0;

    return 1;
}
