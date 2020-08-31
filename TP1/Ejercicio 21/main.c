#include <stdio.h>
#include <stdlib.h>

//Ejercicio 21
//Obtiene la parte entera de un numero real

int parteEntera(float numero);

int main()
{
    float numero;

    printf("Ingrese un numero: ");
    scanf("%f", &numero);
    printf("La parte entera de %0.3f es %d", numero, parteEntera(numero));
    printf("\nPresione cualquier tecla para volver a ejecutar este programa.\n");
    getch();
    main();
    return 0;
}

int parteEntera(float numero)
{
    return (int) numero;
}
