#include <stdio.h>
#include <stdlib.h>

//Ejercicio 10
//A partir de un numero N, calcula la suma de los primeros numeros N

int sumaNaturales(int);

int main()
{
    int numero;

    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    numero = abs(numero);
    printf("La suma de los primeros numeros naturales hasta %d (incluyendolo) es: %d \n", numero, sumaNaturales(numero));
    printf("Presione cualquier tecla para ejecutar nuevamente este programa.\n");
    getch();
    main();
    return 0;
}

int sumaNaturales(int numero)
{
    int i, suma = 0;

    for (i = 1; i <= numero; i++)
        suma += i;

    return suma;
}

