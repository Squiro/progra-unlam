#include <stdio.h>
#include <stdlib.h>

//Ejercicio 20
//Metodo de multiplicacion rusa

int multiplicacionRusa(int, int);

int main()
{
    int numeroA, numeroB;
    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroA);
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &numeroB);
    printf("El resultado del producto utilizando multiplicacion rusa es: %d", multiplicacionRusa(numeroA, numeroB));
    printf("\nPresione cualquier tecla para volver a ejecutar este programa.\n");
    getch();
    main();
    return 0;
}

int multiplicacionRusa(int numeroA, int numeroB)
{
    int suma  = 0;
    //Se deben tomar en cuenta los dos primeros factores en la suma
    if (numeroA %2 != 0)
        suma += numeroB;

    while(numeroA != 1)
    {
        numeroA /= 2;
        numeroB *= 2;

        if (numeroA %2 != 0)
            suma += numeroB;
    }
    return suma;
}

