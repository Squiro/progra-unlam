#include <stdio.h>
#include <stdlib.h>

//Ejercicio 5
//Verifica si un entero pertence a la serie de Fibonacci

int pertenceFibonacci(int);

int main()
{
    int numero;

    printf("Ingrese un numero entero para verificar si pertenece a la serie de Fibonacci: \n");
    scanf("%d", &numero);
    if (pertenceFibonacci(numero))
        printf("Si, pertence.\n");
    else
        printf("No, no pertenece.\n");

    printf("Presione cualquier tecla para volver a ejecutar este programa.\n");
    getch();
    main();
    return 0;
}

int pertenceFibonacci(int numero)
{
    int numPrev = 1, numProx = 1, aux;

    while (numProx < numero)
    {
        aux = numProx;
        numProx = numPrev + numProx;
        numPrev = aux;
    }

    if (numero == numProx)
        return 1;
    else
        return 0;
}
