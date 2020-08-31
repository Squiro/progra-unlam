#include <stdio.h>
#include <stdlib.h>
#define TAM 6

//Ejercicio 25
//Elimina la primera aparicion de un elemento determinado

void eliminarElemento(int , int*, int);
void showArrayWithPos(int[], int);
int is_inArray(int, int*, int);

int main()
{
    int vec[] = {10, 2, 20, 10, 40, 10};
    int elemento, cantElem = 6;
    int size = sizeof(vec)/sizeof(int);
    showArrayWithPos(vec, size);

    printf("\n\nIngrese un elemento para eliminar del vector: ");
    scanf("%d", &elemento);
    eliminarElemento(elemento, vec, size);
    printf("\nAsi quedo el vector: \n");
    showArrayWithPos(vec, size);
    return 0;
}

void eliminarElemento(int elemento, int* pvec, int cantElem)
{
    //Si no está en el array, no hacemos nada
    if (!is_inArray(elemento, pvec, cantElem))
        return;

    int* pFin = pvec+cantElem-1;
    int removed = 0;

    while (pvec < pFin)
    {
        if (*(pvec+1) != elemento || removed == 1)
        {
            *pvec = *(pvec+1);
            removed = 1;
        }
        pvec++;
    }

    *pvec = 0;
}

int is_inArray(int elemento, int* pvec, int cantElem)
{
    int i;

    for (i = 0; i < cantElem; i++)
    {
        if (*pvec == elemento)
            return 1;
        pvec++;
    }

    return 0;
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
