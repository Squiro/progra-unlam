#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int mat[4][TAM] =
    {
        { 1, 0, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 1 }
    };

    printf("%d" ,chequearSimetria(mat, 4, 4));
    return 0;
}
