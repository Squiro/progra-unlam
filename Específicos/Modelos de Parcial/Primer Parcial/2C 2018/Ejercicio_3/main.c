#include <stdio.h>
#include <stdlib.h>
#define TAM 100

int * trasponer_matriz(int mat[][TAM], int f, int c);

int main()
{   int * hola;
    //3*4
    int matriz[][TAM]=
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}/*,
        {13,14,15,16}*/
    };
    mostrar_matriz(matriz,3,4);
    &(matriz) = trasponer_matriz(matriz,3,4);
    printf("\n");
    mostrar_matriz(hola,4,3);
    return 0;
}

/**
 Al realizar esta función,
 asumí que se desea trasponer una matriz cuadrada,
 **/
int * trasponer_matriz(int mat[][TAM], int f, int c)
{
    int matriz[c][f];
    int i,j, aux;
    for( i=0; i < f ;i++)
    {
        for(j=i+1; j<c ;j++)
        {
            matriz[i][j]= mat[j][i];
        }
    }
    return matriz;
}

void mostrar_matriz(int mat[][TAM], int f, int c)
{
    int i,j;
    for( i = 0; i < f ;i++)
    {
        for(j = 0; j < c ;j++)
        {
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}
