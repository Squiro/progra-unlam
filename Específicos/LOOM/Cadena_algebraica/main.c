#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* Consigna

Desarrollar una funci�n, que recibe una cadena de caracteres validada, la misma contiene expresiones algebraicas simples, de la forma:
nro1 (operaci�n) nro2 (operaci�n) nroN � =
nroX: es un n�mero entero sin signo.
(operaci�n) s�lo puede ser + -
La expresi�n puede tener �n� t�rminos.
El s�mbolo �=� siempre aparece al final de la cadena.
La funci�n retorna el valor num�rico de la expresi�n algebraica recibida.
*/

int main()
{
    char cadena[] = "300+90-5+54+100-100=";

    printf("EL RESULTADO ES %d ;)", calcularResultado(cadena));
    return 0;
}
