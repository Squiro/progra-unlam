#include <stdio.h>
#include <stdlib.h>

//Ejercicio 9
//Obtiene el cociente entero y el resto de A/B

int restoEntre(int, int);

int main()
{
    int numeroA, numeroB;

    printf("Ingrese el numero A: \n");
    scanf("%d", &numeroA);
    printf("Ingrese el numero B: \n");
    scanf("%d", &numeroB);
    printf("El cociente entre %d y %d es: %.4f. El resto es: %d\n", numeroA, numeroB, (float)numeroA/numeroB, restoEntre(numeroA, numeroB));
    printf("Presione cualquier tecla para ejecutar nuevamente este programa.\n");
    getch();
    main();
    return 0;
}

//Obtiene el resto de la division entre dos numeros
int restoEntre(int numeroA, int numeroB)
{
    if(!numeroB)
    {
        printf("No se puede dividir por 0. Ingrese otro par de numeros.");
        main();
    }
    else
        return numeroA % numeroB;
}
