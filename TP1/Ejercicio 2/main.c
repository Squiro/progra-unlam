#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Calcula el combinatorio de M sobre N, siendo ambos enteros

int factorialDe(int);
int combinatorioDe((int, int);

int main()
{
    int numeroM, numeroN;

    printf("Ingrese el numero M: \n");
    scanf("%d", &numeroM);
    printf("Ingrese el numero N: \n");
    scanf("%d", &numeroN);
    if (numeroN > numeroM || numeroN < 0)
    {
        printf("Para poder calcular el combinatorio, el numero M debe ser mayor o igual al numero N, y N debe ser mayor o igual a 0.\n");
        printf("Presione una tecla, ingrese los valores correctamente, e intentelo de nuevo.");
        getch();
        system("CLS");
        main();
    }
    else
    {
        printf("El combinatorio de %d sobre %d es: %d.\n", numeroM, numeroN, combinatorioDe(numeroM, numeroN));
        printf("Presione una tecla para calcular otro combinatorio de dos numeros.\n");
        getch();
        main();
    }
    //return 0;
}

int combinatorioDe(int numeroM, int numeroN)
{
    return factorialDe(numeroM)/(factorialDe(numeroN)*factorialDe(numeroM-numeroN));
}

int factorialDe(int numero)
{
    if (numero)
        return numero * factorialDe(numero-1);
    else
        return 1;
}
