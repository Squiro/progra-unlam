#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int mat[3][COL] = { { 1, 2, 3 },
                      { 4, 5, 6 },
                      { 23, 44, 11 }
                    };

    printf("Pre-traspuesta:\n\n");
    mostrar_matriz(mat, 3, 3);
    trasponer_insitu(mat, 3, 3);
    printf("\n\nPost-traspuesta:\n\n");
    mostrar_matriz(mat, 3, 3);
    return 0;
}
