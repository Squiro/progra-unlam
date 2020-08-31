#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Ejercicio 7
//Calcula el seno polinómicamente

float calcularSeno(float, float);
int factorialDe(int);
//int int_pow(int, int);
float float_pow(float, float);

int main()
{
    float numeroX, tolerancia;

    printf("Ingrese un numero X: \n");
    scanf("%f", &numeroX);
    printf("Ingrese una tolerancia: \n");
    scanf("%f", &tolerancia);
    printf("El resultado del seno de X = %.5f con tolerancia de %.5f es: %.5f \n", numeroX, tolerancia, calcularSeno(numeroX, tolerancia));
    printf("Presione cualquier tecla para volver a ejecutar este programa. \n");
    getch();
    main();
    //return 0;
}

float calcularSeno(float numeroX, float tolerancia)
{
	//Se puede optimizar multiplicando cada termino por (-1) / ! \ CORREGIR

    int incremental = 1, suma = 1;
    float resultado = 0, termino = 0;

    //Si suma == 1, se considera como TRUE, y suma
    //Si suma == 0, se considera como FALSE, y resta

    do
    {
        termino = float_pow(numeroX, incremental)/factorialDe(incremental);
        if (suma)
        {
            resultado += termino;
            suma = 0;
        }
        else
        {
            resultado -= termino;
            suma = 1;
        }
        incremental += 2;
    } while (tolerancia < abs(termino));

    return resultado;

}

int factorialDe(int numero)
{
    if (numero)
        return numero * factorialDe(numero-1);
    else
        return 1;
}


/*int int_pow(int base, int exponente)
{
    int incremental = 0, resultado = 1;

    while (exponente > incremental)
    {
        resultado *= base;
        incremental++;
    }

    return resultado;
}*/

float float_pow(float base, float exponente)
{
    float incremental = 0, resultado = 1;

    while (exponente > incremental)
    {
        resultado *= base;
        incremental++;
    }

    return resultado;
}
