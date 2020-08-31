#include <stdio.h>
#include <stdlib.h>

#define COL 4
#define FIL 2

//Teoría sobre matrices

int main()
{
    //Definición de matrices. Los indices de matrices van desde 0 a FIL-1 y 0 a COL-1
    int mat[FIL][COL]; //Def sin asignacion ni inicializacion

    int mat1[][COL] = { { 1, 2, 3, 4 } , {5, 6} };

    // / ! \ Las matrices siempre deben tener el numero de columnas al momento de definirlas.

    int mat2[FIL][COL] = { { 11, 12, 13, 14 } }; //Prestar atención a la cantidad de llaves. Es un nivel de llave por fila.

    int mat3[][COL] = { {  } }; //Las matrices definidas asi se inicializan llenas de 0

    //El tamaño (si FIL == 1 y COL == 4) el tamaño será 16, porque son 4 columnas
    //de 4 enteros, y cada entero son 4 bytes cada uno
    printf("%d\n\n", sizeof(mat3));

    int i, j;

    //Mostramos la mat
    for (j = 0; j < COL; j++)
        printf(" %d ", mat3[0][j]); //Como la matriz tiene 1 sola fila (porque la definimos así, el subindice es fijo

    //Esto va a producir warning de exceso de elementos, tanto de columnas como de filas
    //int mat4[FIL][COL] = { {21, 22, 23, 24, 25, 26, 27} , { 28, 29, 30, 31, 32, 33} , { 34, 35, 36, 37} };

    //mat[0] representa toda la primera fila de la matriz. Se comporta como un vector.
    //mat[1] representa toda la segunda fila de la matriz. Se comporta como un vector.
    //mat[0] y mat[1] son punteros constantes que apuntan a la primera posicion de la fila

    //mat (sin nada) es un puntero a puntero al primer elemento fisico de la matriz. Pero también es un puntero a la
    //primera fila.

    //Asignamos 4 a mat[0][0]
    mat[0][0] =  4;

    //Esto muestra toda la misma direccion, porque son la direccion al primer elemento
    printf("\n\nMat: %p\n", mat);
    printf("&Mat: %p\n", &mat);
    printf("&Mat[0]: %p\n", &mat[0]);
    printf("&Mat[0][0]: %p\n", &mat[0][0]);
    printf("Mat[0]: %p\n", mat[0]);

    printf("D: %d P: %p\n", *mat, *mat);
    printf("D: %d P: %p\n", **mat, **mat);

    /*for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
            printf(" %d ", mat3[i][j]);
        printf("\n");
    }*/

    printf("\n\n\nEjemplo mostrar matriz: \n\n");
    mostrarMat(mat2, FIL);

    return 0;
}

//Matrices por parametros. El numero de columnas DEBE estar.
//Como COL está definido y no se puede modificar, definimos una matriz de un tamaño absurdamente grande (TAM = 100)
//Y solo utilizamos las posiciones que necesitemos
void mostrarMat(int mat[][COL], int filas)
{
    int i, j;
    for (i = 0; i < FIL; i++)
    {
        for (j = 0; j < COL; j++)
            printf(" %d ", mat[i][j]);
        printf("\n");
    }
}

//Hacer un ejercicio que muestre un elemento ij (enviando la matriz con punteros)
//Hacer otro ejercicio que recorra toda una matriz con punteros
