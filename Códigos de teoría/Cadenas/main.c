#include <stdio.h>
#include <stdlib.h>
#define TAM 4

int main()
{
    char *pc = "dice que dice"; //Puntero a cadena. Esta cadena ES CONSTANTE. No se puede modificar.
    char cad1[TAM] = "ola";
    char cad2[TAM] = "chau"; //No va a entrar el caracter de termino de linea \0
    char cad3[TAM] = "adios mundo cruel"; //Tira warning, porque la cant de caracteres es mayor que TAM
    char cad4[] = "ASDASDF"; //Reserva la cantidad de caracteres necesarias para lo ingresado mas el fin de linea
    char cad5[] = {'a', 'd', 'i', 'o', '\0' }; //Lo asignamos caracter por caracter, agregando el terminador nulo
    //cad5++; No puedo modificar algo constante. cad5 es un puntero constante a la primera direccion del primer elemento del array.
    printf("%s\n", cad1);
    printf("%s\n", cad2); //Al hacer el printf, se mostrara "chauola", porque chau no tiene el fin de linea, pero ola si.
    printf("%s SIZE: %d\n", pc, sizeof(pc)); //El tamaño es 4 porque esta mostrando el sizeof del puntero, no de la cadena
    printf("%s SIZE: %d Dir: %p\n", cad5, sizeof(cad5), cad5); //Notar que cad5 es el puntero constante.
    *cad5 = 'A'; //Al contenido de cad5 le pongo A mayuscula
    printf("%s SIZE: %d Dir: %p\n", cad5, sizeof(cad5), cad5); //Notar que cad5 es el puntero constante.

    /* Esto va a explotar, porque al declarar pc, lo declaramos como una cadena constante. Esa zona de memoria que ocupa
    esta reservada y no puedo acceder a ella. No la puedo modificar.
    pc es un puntero, la cadena es constante, es un literal
    pc+=4;
    *pc = 'E';
    pc-=4;
    printf("%s SIZE: %d\n", pc, sizeof(pc));*/

    return 0;
}

//Investigar las mem de string.h
//Para lo de string.h:
//NOMBRE: mi_strcpy
