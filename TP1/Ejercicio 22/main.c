#include <stdio.h>
#include <stdlib.h>

#define TAM 6

//Ejercicio 22
//Inserta un elemento en un array de ints, dada la posicion de insercion

//Insertar != reemplazar / ! \ CORREGIR
//tener en cuenta espacios usados

//Usar:

//1. Insercion contigua, con cantElem
//2. Insercion en la que se corra todo (y se pierda el ultimo)

int insertarElemento(int , int , int*, int);
void showArrayWithPos(int[], int);

int main()
{
    int vec[TAM] = {2, 3, 7, 9};
    int elemento, posicion, cantElem; //size
    cantElem = 6; //Apunta a la siguiente posicion libre, o sea, cantElem - 1 es la verdadera cant

    //size = sizeof(vec)/sizeof(int);

    showArrayWithPos(vec, sizeof(vec)/sizeof(int));

    printf("\n\nIngrese un elemento para añadir al vector: ");
    scanf("%d", &elemento);
    printf("\nIngrese la posicion en la que desea añadirlo: ");
    scanf("%d", &posicion);
    posicion = abs(posicion);

    while (posicion>TAM-1 || posicion > cantElem)
    {
        printf("\nLa posicion ingresada es mas grande que la cantidad de posiciones del vector.");
        printf("\nIntente de nuevo.\n\n");
        printf("\nIngrese la posicion: ");
        scanf("%d", &posicion);
        posicion = abs(posicion);
    }

	cantElem = insertarElemento(posicion, elemento, vec, cantElem);
	printf("\nAsi quedo el vector: \n");
	showArrayWithPos(vec, sizeof(vec)/sizeof(int));
	printf("Cant elem: %d", cantElem);

    return 0;
}

//Parametros:
//pos = a una posicion del vector
//elemento = elemento/num a insertar
//vector = al puntero de la primera posicion

//Tiene que retornar la cant de elem del vector
int insertarElemento(int pos, int elemento, int* pvec, int cantElem)
{
	int i;
	int* pFin;

	pFin = pvec+pos;

	pvec += cantElem-1; //Le sumamos al puntero la cantElem para apuntar a la ult posicion ocupada

	while (pvec > pFin)
    {
		*pvec = *(pvec-1);
        pvec--;
    }

	/*for (i = cantElem; i > pos; i--)
	{
		*pvec = *(pvec-1);
        pvec--;
	}*/

	*pvec = elemento; //Le asignamos a la pos indicada por el usuario, el elem indicado

	return cantElem < TAM ? cantElem++ : cantElem;

	/* Forma menos optima
	int aux;
	aux = *(pvec); //el auxiliar es el elemento ORIGINAL que estaba en esa posicion

    for (i = pos; i < TAM; i++)
	{
		*(pvec+i) = elemento; //Guardamos el elemento DADO en la posicion dada
		elemento=aux; //SOBREESCRIBIMOS el elemento DADO por el auxiliar, para poder guardarlo en la prox iteracion
		aux = *(pvec+i+1); //Ahora el nuevo auxiliar va a ser el elemento presente en la posicion contigua
	}*/
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
