#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* Desarrollar una funcion para que, dada una matriz cuadrada de orden N,
    obtenga la sumatoria de los elementos que están por encima de la diagonal
    principal (exluida esta). Lo mismo para la diagonal secundaria. Lo mismo
    incluyendo la diagonal. Lo mismo, con lo que están por debajo de la diagonal.*/



int main()
{
    int mat[3][COL] = { { 1, 2, 3 },
                        { 4, 5, 6 },
                        { 7, 8, 9 }
                    };

    printf("Sumatoria por encima de DP sin incluirla: %d\n", sumatoriaArribaDP(mat, 3, 3, 0));
    printf("Sumatoria por encima de DP incluyendola: %d\n", sumatoriaArribaDP(mat, 3, 3, 1));
    printf("Sumatoria por encima de DS sin incluirla: %d\n", sumatoriaArribaDS(mat, 3, 3, 0));
    printf("Sumatoria por encima de DS incluyendola: %d\n", sumatoriaArribaDS(mat, 3, 3, 1));
    printf("Sumatoria por dejajo de DP sin incluirla: %d\n", sumatoriaAbajoDP(mat, 3, 3, 0));
    printf("Sumatoria por debajo de DP incluyendola: %d\n", sumatoriaAbajoDP(mat, 3, 3, 1));
    printf("Sumatoria por debajo de DS sin incluirla: %d\n", sumatoriaAbajoDS(mat, 3, 3, 0));
    printf("Sumatoria por debajo de DS incluyendola: %d\n", sumatoriaAbajoDS(mat, 3, 3, 1));
    return 0;
}
