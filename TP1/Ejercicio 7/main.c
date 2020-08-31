#include <stdio.h>
#include <stdlib.h>

//Ejercicio 7
//Verifica si un número natural es perfecto, deficiente, o abundante.

int numeroPerfecto(int);

int main()
{
    int numero;
    printf("Ingrese un numero natural: \n");
    scanf("%d", &numero);
    numero = abs(numero); //Lo convertimos a valor absoluto por las dudas de que algun usuario se quiera pasar de vivo
    switch (numeroPerfecto(numero))
    {
        case 1: printf("El numero %d es perfecto. \n", numero);
            break;
        case 2: printf("El numero %d es deficiente. \n", numero);
            break;
        case 3: printf("El numero %d es abundante. \n", numero);
            break;
    }
    printf("Presione cualquier tecla para volver a ejecutar este programa.\n");
    getch();
    main();
    return 0;
}

//Verifica si un número natural es perfecto, deficiente, o abundante.
//En caso de ser pefecto, retorna 1
//En caso de ser deficiente, retorna 2
//En caso de ser abundante, retorna 3

int numeroPerfecto(int numero)
{
    int sumaDivisores = 1, i;
    //Seteamos sumaDivisores = 1 ya que todo numero es divisible por 1

    //Además comenzamos el for en 2 porque... no podemos obtener el resto de una division por cero
    //y porque ya "pasamos" por el 1 al setear sumaDivisores
    for (i = 2; i < numero; i++)
    {
        if (numero % i == 0)
        {
            sumaDivisores += i;
        }
    }

    //printf("Suma: %d \n", sumaDivisores);

    if (sumaDivisores == numero)
        return 1;
    else if (sumaDivisores < numero)
        return 2;
    else
        return 3;
}
