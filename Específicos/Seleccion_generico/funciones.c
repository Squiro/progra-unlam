#include "funciones.h"

void seleccion(void *array, int cantElem, int tamElem, t_cmp comparar)
{
    //Definimos un puntero void que va a estar señalizar el inicio del array
    void *pIni = array, *pMenor;

    while (array < pIni+(tamElem*cantElem))
    {
        //*(comparar) debe devolver la posición del menor elemento dentro del array
        pMenor = hallarPosMenor(array, pIni+(tamElem*cantElem), tamElem, comparar);

        //Chequeamos que las posiciones no sean las mismas
        if (pMenor != array)
            intercambio(array, pMenor, tamElem);

        //Le sumamos al array el tamaño de un elemento entero, avanzando así una posición
        array+=tamElem;
    }
}

int compararEnteros(const void *arg1, const void *arg2)
{
    int *num1 = (int *)arg1, *num2 = (int *)arg2;

    return *num1 - *num2;
}

int intercambio(void * array, void * pMenor, int tamElem)
{
    //Asignamos un espacio de memoria que sea del tamaño de los elementos del array
    void *aux = malloc(tamElem);

    //Chequeamos si se pudo asignar la memoria
    if (!aux)
    {
        printf("No se pudo asignar memoria.\n\n");
        return ERROR_ASSIGN;
    }
    //Como no podemos laburar con el "tipo de dato" void como si fuera uno normal, necesitamos usar memmove
    //memmove evita que haya errores de solapamiento
    //memcpy es mas rapido, pero es menos seguro

    memmove(aux, array, tamElem); //*aux = *array;
    //El razonamiento va por las líneas del comentario anterior
    memmove(array, pMenor, tamElem); //*array = *(array+pos*tamElem);
    memmove(pMenor, aux, tamElem); //*(array+pos) = *aux;

    //Liberamos la memoria
    free(aux);

    return 0;
}

void * hallarPosMenor(void *currentPos, const void *pFinal, int tamElem, t_cmp comparar)
{
    void *pMenor = currentPos;

    //for (; currentPos < pFinal; currentPos+=tamElem)
    while (currentPos < pFinal)
    {
        if (comparar(pMenor, currentPos) > 0)
            pMenor = currentPos;
        currentPos+=tamElem;
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
