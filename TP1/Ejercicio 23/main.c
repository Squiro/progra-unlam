#include <stdio.h>
#include <stdlib.h>
#define TAM 6

//Ejercicio 23
//Inserta un elemento en un array de ints ordenado de forma ascendente, de forma de no alterar el orden

void insertarElementoAscendente(int , int*, int);
void showArrayWithPos(int[], int);
int is_inArray(int, int*, int);

int main()
{
    int vec[TAM] = {2, 10, 20, 30, 40, 50};
    int elemento, cantElem = 6; //Apunta a la siguiente posicion libre, o sea, cantElem - 1 es la verdadera cant;
    int size = sizeof(vec)/sizeof(int);

    showArrayWithPos(vec, size);

    printf("\n\nIngrese un elemento para añadir al vector: ");
    scanf("%d", &elemento);
    insertarElementoAscendente(elemento, vec, cantElem);
    printf("\nAsi quedo el vector: \n");
    showArrayWithPos(vec, size);
    return 0;
}

void insertarElementoAscendente(int elemento, int* pvec, int cantElem)
{
    //Si el elemento está en el array, no hacemos nada
    if (is_inArray(elemento, pvec, cantElem))
        return;

    pvec += cantElem-1;

    while (*pvec > elemento && *(pvec-1) > elemento)
	{
		*pvec = *(pvec-1);
        pvec--;
	}

	*pvec = elemento;

//    if (elemento > *(pvec+(size-1))) //Ultima posicion
//    {
//        *(pvec+(size-1)) = elemento;
//        return;
//    }
//
//
//    if (elemento < *pvec) //Primera posicion
//    {
//        *pvec = elemento;
//        return;
//    }
//
//    for(i=0; i < size; i++) //Recorremos posiciones restantes
//    {
//        if (elemento < *pvec)
//        {
//            //*(vec+i) = elemento;
//            //O también
//            *(pvec) = elemento; //Usamos primero, incrementamos después
//            return;
//        }
//        pvec++;
//    }
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
