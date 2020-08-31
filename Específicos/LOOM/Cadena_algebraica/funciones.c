#include "funciones.h"


int calcularResultado(char * cadena)
{
    int res = 0;
    char ultop = '+', aux;
    char *pIni = cadena;

    while(*cadena)
    {
        if(*cadena == '+' || *cadena == '=' || *cadena == '-')
        {
            aux = *cadena;
            *cadena = '\0';
            if (ultop == '+')
                res += atoi(pIni);
            else
                res -= atoi(pIni);
            ultop = aux;
            pIni = cadena+1;
        }
         cadena++;
    }
    return res;
}


/*int calcularResultado(char *cadena) {

    char operacion = '+';
    int numero, resultado = 0;

    do {

        numero = atoi(cadena);
        cadena = strpbrk(cadena, "+-=");

        operacion == '+' ? (resultado += numero) : (resultado -= numero);

        operacion = *cadena++;

    } while (*cadena);

    return resultado;

}*/
