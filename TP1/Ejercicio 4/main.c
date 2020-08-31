#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularRaizDe(float, float);

int main()
{
    float numero, tolerancia;

    printf("Ingrese un numero para calcular su raiz: ");
    scanf("%f", &numero);
    printf("\nIngrese una tolerancia: ");
    scanf("%f", &tolerancia);
    printf("\nLa raiz de %f con tolerancia %f es: %f", numero, tolerancia, calcularRaizDe(numero, tolerancia));
    printf("\nPresione cualquier tecla para calcular otra raiz.\n");
    getch();
    main();
    return 0;
}

float calcularRaizDe(float numero, float tolerancia)
{
    //Termimo = 1 ya que empezamos con R1 = 1
    float terminoPrev = 0, termino = 1;

    do
    {
        terminoPrev = termino;
        termino = (terminoPrev+(numero/terminoPrev))/2;
        printf("\nDiferencia entre terminos: %f", fabs(termino - terminoPrev));

    } while(fabs(termino - terminoPrev) > tolerancia);

    return termino;
}
