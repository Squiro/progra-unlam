#include <stdio.h>
#include <stdlib.h>

//Ejercicio 27
//Dada una cadena, chequea si es palindromo

int esPalindromo(char[], int, int);
int removerEspacios(char*, char*);

int main()
{
    char cadena[] = "anita lava la tina";
    int size = 0, cantPosiciones;
    char cadenaLimpia[sizeof(cadena)];

    //cantPosiciones guarda la cantidad de posiciones de diferencia que hay entre la cadena original
    //y la cadena sin espacios. A este numero le sumamos 2, ya que es la cantidad de caracteres del null terminator en C ('\0')
    cantPosiciones = removerEspacios(cadena, cadenaLimpia) + 2;
    size = sizeof(cadenaLimpia)/sizeof(char);
    printf("%s \n", cadenaLimpia);
    printf("%d \n", cantPosiciones);

    if (esPalindromo(cadenaLimpia, size, cantPosiciones))
        printf("\nEs palindromo.");
    else
        printf("\nNo es palindromo.");
    return 0;
}

int esPalindromo(char cadena[], int size, int cantPos)
{
    //int i = 0, j = size-cantPos; //Esto es a lo que se refiere el comentario de la linea 13
    char *i = cadena, *j = cadena+(size-cantPos); //Punteros al vector

    //Recorremos la cadena desde 0 con i, hacia la derecha, y desde size-cantPos con j, hacia la izquierda

    while (i < (cadena+size) && j >= cadena)
    {
        printf("%c -> %c \n", *i, *j);
        if (*i != *j)
            return 0;
        i++;
        j--;
    }

    /*while (i < size && j >= 0)
    {
        printf("%c -> %c \n", cadena[i], cadena[j]);
        if (cadena[i] != cadena[j])
            return 0;
        i++;
        j--;
    }*/

    return 1;
}

//Retorna la cantidad de espacios removidos
int removerEspacios(char* source, char* dest)
{
    int i = 0, j = 0, contador = 0;

    while (*source != '\0') //Mientras no lleguemos al null terminator...
    {
        if (*source != ' ') //Si es diferente de un espacio en blanco... copiamos el contenido en el otro char
        {
            *dest = *source;
            dest++; //Incrementamos el pointer de dest para que el prox char se guarde en la siguiente posicion
        }
        else //Si no es diferente, no lo copiamos, y aumentamos el contador de espacios
            contador++;
        source++; //Incrementamos el pointer de source para ir avanzando por el string
    }
    *(dest) = '\0'; //Al ultimo espacio de dest le ponemos el null terminator para terminar la cadena cuando es necesario
    return contador;
}
