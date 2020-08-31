#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Ejercicio 3
//Calcular e^x dados x y una tolerancia
//...o sea, una aproximación lineal
float calcularFuncExponencial(float, float);
int factorialDe(int);
//int int_pow(int, int);
float float_pow(float, float);

int main()
{
    float numeroX, tolerancia;
    printf("Ingrese el valor de X: \n");
    scanf("%f", &numeroX);
    printf("Ingrese una tolerancia: \n");
    scanf("%f", &tolerancia);
    //printf("Calcule esto: %d", int_pow(numeroX, tolerancia));
    printf("El resultado de la funcion exponencial para X = %.6f y con tolerancia = %.6f es: %.6f \n", numeroX, tolerancia, calcularFuncExponencial(numeroX, tolerancia));
    printf("Presione una tecla para calcular nuevamente el resultado con otros valores. \n");
    getch();
    main();
}

int factorialDe(int numero)
{
    if (numero)
        return numero * factorialDe(numero-1);
    else
        return 1;
}

float calcularFuncExponencial(float numeroX, float tolerancia)
{
    int incremental = 0;
    float resultado = 0, termino;

    do
    {
        termino = (float_pow(numeroX, incremental)/factorialDe(incremental));
        resultado += termino;
        incremental++;
    } while (termino > tolerancia);
    //printf("%f", resultado);
    return resultado;
}

float calcExp(float x, float tol)
{
	float t_ant = 1, t_actual, n = 1;
	float ex;

	/*if (n == 0)
		return 1;*/

	do
	{
        t_actual = t_ant * x/n;
        n++;
        t_ant = t_actual;
        ex += t_actual;
	} while (t_actual > tol);

	return ex;
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
