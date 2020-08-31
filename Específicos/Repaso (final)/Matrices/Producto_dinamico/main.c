#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** For real this time. Vamos a hacer un producto de matrices en el que el resultado se guarde en una matrix
    malloc-eada dinamicamente. */

int main()
{
    int *res;
    int mat[2][2] =
    {
        { 1, 0 },
        { 0, 1 }
    };

    int mat2[2][2] =
    {
        { 1, 0 },
        { 0, 1 }
    };

    res = producto_matrices(2, 2, mat, 2, 2, mat2);
    mostrarMatrizPuntero(2, 2, res);

    return 0;
}
