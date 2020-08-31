#include <stdio.h>
#include <stdlib.h>

//Ejercicio 28
//Devuelve el valor numerico de una cadena de caracteres en la que los chars representan digitos

int valorNumerico(char []);

int main()
{
    char cadena[] = "123456789";

    printf("El valor numerico de la cadena es: %d", valorNumerico(cadena));
    return 0;
}

int valorNumerico(char cadena[])
{
    int i, numero = 0;

    //Los numeros son representados a partir del numero 30 (equivalente a 0) en ASCII
    //Si a un char que representa un digito le restamos 30, obtenemos su valor numerico
    //Como tenemos mas de un char y mas de un digito, debemos multiplicar por 10 para ir agregando
    //las unidades. EJ: 1 * 10 = 10 => 10 + 2 = 12, 12 * 10 = 120 => 120 + 3 = 123...
    for (i = 0; cadena[i] != '\0'; i++)
        numero = numero*10 + cadena[i] - '0';

    return numero;
}

