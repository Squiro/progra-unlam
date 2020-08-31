#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    float mat[2][TAM] =
    {
        { 1, 0 },
        { 0, 1 }
    };

    printf("%d", chequearSuma(mat, 2, 2));
    return 0;
}
