#include <stdio.h>
#include <stdlib.h>
#define TAM 6

//Ejercicio 26
//Elimina la todas las apariciones de un elemento determinado

void eliminarElemento(int , int*, int);
void showArrayWithPos(int[], int);
int is_inArray(int, int*, int);

int main()
{
    int vec[TAM] = {2, 10, 20, 10, 40, 11};
    int elemento, cantElem = 6;
    int size = sizeof(vec)/sizeof(int);
    showArrayWithPos(vec, size);

    printf("\n\nIngrese un elemento para eliminar del vector: ");
    scanf("%d", &elemento);
    eliminarElemento(elemento, vec, cantElem);
    printf("\nAsi quedo el vector: \n");
    showArrayWithPos(vec, size);
    return 0;
}

void eliminarElemento(int elemento, int* pvec, int cantElem)
{
    //Si no está en el array, no hacemos nada
    if (!is_inArray(elemento, pvec, cantElem))
        return;

    int* pFin = pvec+cantElem;
    //puntero lectura, puntero escritura
    int* pLec = pvec, *pEsc = pvec;

    while (pLec < pFin)
    {
        if (*pLec == elemento)
            pLec++;

        *pEsc = *pLec;
        pEsc++;
        pLec++;
    }

    //Seteamos en 0 la basura
    while (pEsc < pFin)
    {
        *pEsc = 0;
        pEsc++;
    }
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
