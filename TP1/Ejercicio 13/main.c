#include <stdio.h>
#include <stdlib.h>

//Ejercicio 13
//Determina si un numero natural es primo
int esPrimo(int);


int main()
{
    int numero;

    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    if (esPrimo(numero))
        printf("Es primo.\n");
    else
        printf("No es primo.\n");

    printf("Presione cualquier tecla para ejecutar nuevamente este programa.\n");
    getch();
    main();

    return 0;
}

int esPrimo(int numero)
{
    int i;
    //Chequeamos si el numero es == 1 o si es un numero par
    if (numero == 1 || numero % 2 == 0 && numero > 2)
        return 0;
    //En caso de que no, iteramos desde el 3 en adelante (porque ya descartamos el 1 y el 2)
    //y comprobamos que si el numero tiene algun divisor que dé resto 0
    //Incrementamos de a 2 porque ya descartamos todos los numeros pares
    for (i = 3; i < numero/2; i+=2)
        if (numero % i == 0)
            return 0;

    return 1;
}
