#include "funciones.h"

void ordenarPorSeleccion(int *array, int cantElem)
{
    int *pIni = array, *pMenor;
    int aux = 0;
    //int pos = 0, aux = 0;

    while (array < pIni+cantElem)
    {
        pMenor = hallarPosMenor(array, pIni+cantElem);

        if (pMenor != array)
        {
            aux = *array;
            *array = *(pMenor);
            *(pMenor) = aux;
        }
        array++;
    }
    /*int *pLec = array, *pIni = array;
    int i = 0, men, pos = 0, aux = 0;

    while (array < pIni+cantElem)
    {
        men = *array;

        for (i = 0; array+i < pIni+cantElem; i++, pLec++)
        {
            if (*pLec < men)
            {
                men = *pLec;
                pos = i;
            }
        }

        if (array+pos != array)
        {
            aux = *array;
            *array = *(array+pos);
            *(array+pos) = aux;
        }
        array++;
        pLec = array;
        pos = 0;
    }*/
}

int * hallarPosMenor(int *currentPos, int *pFin)
{
    int *pMenor = currentPos;
    //int pos = 0, men = 0, i;

    //printf("\nCP: %p PI: %p", currentPos, pIni);
    //men = *currentPos;

    for (; currentPos < pFin; currentPos++)
    {
        if (*currentPos < *pMenor)
        {
            pMenor = currentPos;
            /*men = *currentPos;
            pos = i;*/
        }
    }

    return pMenor;
}

void mostrarVector(int vec[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", vec[i]);

    printf("\n\n");
}
