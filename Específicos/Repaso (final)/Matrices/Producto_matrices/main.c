#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int mat1[2][2] = {  { 1, 2 },
                        { 3, 4 }
                     };
    int mat2[2][2] = {  { 2, 3 },
                        { 4, 5 }
                     };

    int matRes[2][2];
    //int * matRes;

    //matRes = producto_matrices(2, 2, mat1, 2, 2, mat2);
    producto_matrices(2, 2, mat1, 2, 2, mat2, matRes);

    mostrarMatriz(2, 2, matRes);
    //mostrarMatrizPuntero(2, 2, matRes);

    return 0;
}
