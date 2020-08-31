#include <stdio.h>
#include <stdlib.h>

//Ejercicio 8
//Obtiene el producto de dos numeros naturales a traves de sumas sucesivas

int sumaSucesiva(int, int);

int main()
{
    int numeroM, numeroN;
    printf("Ingrese el primer numero: \n");
    scanf("%d", &numeroM);
    printf("Ingrese el segundo numero: \n");
    scanf("%d", &numeroN);
    printf("El resultado del producto entre %d y %d es: %d \n", numeroM, numeroN, sumaSucesiva(numeroM, numeroN));
    printf("Presione cualquier tecla para ejecutar nuevamente este programa.\n");
    getch();
    main();
    return 0;
}

int sumaSucesiva(int numeroM, int numeroN)
{
    int i, suma = 0;

    if (numeroN)
    {
        for(i = 0; i < numeroN; i++)
        {
            suma += numeroM;
        }
        return suma;
    }

    //Si el otro numero es 0, retornamos 0. Porque cualquier numero por 0 da 0. A excepcion del 5.
    //Por ejemplo: 1 x 0 = 0, 2 x 0 = 0, 3 x 0 = 0, 4 x 0 = 0, 5 x 0 = 991
    return 0;

}
