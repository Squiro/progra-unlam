#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    // Bugfix v1.1: Cant de col de mat1 tiene que ser igual a cant de filas de mat2.
    /*int mat1[3][COL] = { { 1, 2 },
                      { 4, 5 },
                      { 7, 8 }
                    };
    int mat2[2][COL] = { { 1, 2, 3},
                      { 4, 5, 6 },
                    };*/

    int mat1[2][COL] = { { 1, 2, 3, 4 },
                         { 2, 2, 2, 2 }
                       };
    int mat2[4][COL] = { { 1, 0 },
                         { 2, 1 },
                         { 2, 3 },
                         { 0, 1 }
                      };

    printf("Mostrando la primera matriz: \n");
    mostrarMatriz(mat1, 2, 4);
    printf("\n\nMostrando la segunda matriz: \n");
    mostrarMatriz(mat1, 4, 2);
    printf("\n\nMostrando el producto entre las matrices: \n");
    productoMatrices(mat1, mat2, 2, 4, 4, 2);

    return 0;
}
