#include <stdio.h>
#include <stdlib.h>

#define ORDEN 4

//Ejercicio 29
//Cosas con matrices

void rellenarMatriz(float (*)[ORDEN]);
void mostrarMatriz(float (*)[ORDEN]);

int main()
{
    float mat[ORDEN][ORDEN];
    rellenarMatriz(mat);
    mostrarMatriz(mat);

    return 0;
}

void rellenarMatriz(float mat[ORDEN][ORDEN])
{
    int i, j;

    for (i = 0; i < ORDEN; i++)
        for (j = 0; j < ORDEN; j++)
            mat[i][j] = 2.5;

}

void mostrarMatriz(float mat[ORDEN][ORDEN])
{
    int i, j;

    for (i = 0; i < ORDEN; i++)
        for (j = 0; j < ORDEN; j++)
            printf("%0.2f \n", mat[i][j]);
}
