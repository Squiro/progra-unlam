#include <stdio.h>
#include <stdlib.h>
#define TAM 6

//Ejercicio 24
//Elimina un elemento en determinada posicion

void eliminarElementoEnPos(int, int*, int);
void showArrayWithPos(int[], int);

int main()
{
    int vec[TAM] = {2, 10, 20, 30, 40, 50};
    int posicion, cantElem = 6;
    int size = sizeof(vec)/sizeof(int);

    showArrayWithPos(vec, size);

    printf("\nIngrese la posicion del elemento que desea eliminar: ");
    scanf("%d", &posicion);
    posicion = abs(posicion);
    while (posicion>size-1)
    {
        printf("\nLa posicion ingresada es mas grande que la cantidad de posiciones del vector.");
        printf("\nIntente de nuevo.\n\n");
        printf("\nIngrese la posicion del elemento que desea eliminar: ");
        scanf("%d", &posicion);
        posicion = abs(posicion);
    }
    eliminarElementoEnPos(posicion, vec, cantElem);
    printf("\nAsi quedo el vector: \n");
    showArrayWithPos(vec, size);
    return 0;
}

void eliminarElementoEnPos(int pos, int* pvec, int cantElem)
{
    int* pFin = pvec+cantElem-1;
    pvec += pos;

    while (pvec < pFin)
    {
        *pvec = *(pvec+1);
        pvec++;
    }

    *pvec = 0;
}

//Imprime el vector con sus posiciones por pantalla
void showArrayWithPos(int vec[], int size)
{
    int i;

    printf("ELEMENTOS: \t |");
    for (i = 0; i < size; i++)
        printf(" %d | ", *vec++);
    printf("\nPOSICIONES: \t |");
    for (i = 0; i < size; i++)
        printf(" %d | ", i);
}
