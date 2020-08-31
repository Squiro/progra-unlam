#include <stdio.h>
#include <stdlib.h>

int factorialDe(int);

int main()
{
    int numero;
    printf("Ingrese un numero entero para calcular su factorial: \n");
    scanf("%d", &numero);

    printf("El factorial de %d es %d.", numero, factorialDe(numero));
    return 0;
}

int factorialDe(int numero)
{
    if (numero)
        return numero * factorialDe(numero-1);
    else
        return 1;
}
