#include "funciones.h"

void trasponer_insitu(int mat[][COL], int fil, int col)
{
    int i, j, aux;

    //Haciendo que las filas vayan hasta fil/2+1, evitamos un ciclo menos al pedo
    for (i = 0; i < fil/2+1; i++)
        for (j = i; j < col; j++)
        {
            if (i != j)
            {
                /*printf("\nI: %d J: %d\n", i, j);
                printf("I: %d J: %d\n", j, i);*/
                aux = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = aux;
            }
        }
}

void mostrar_matriz(int mat[][COL], int fil, int col)
{
    int i, j;

    for (i = 0; i < fil; i++)
        for (j = 0; j < col; j++)
            printf("%d ", mat[i][j]);
}
