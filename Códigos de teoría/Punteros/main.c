#include <stdio.h>
#include <stdlib.h>

//Explicacion sobre punteros, variables en memoria, y otras yerbas

int main()
{
    int x = 5;
    int *px; //px puede guardar la dir. de memoria de una variable entera

    px = &x; //Utilizamos el simbolo & para hacer referencia a la posición de memoria de x, y no al valor que tiene asignado

    printf("Valor de x: %d \t %d", x, *px);
    printf("\nDireccion de x: %p \t PX: %p", &x, px); //Para mostrar punteros, utilizamos %p
    printf("\nDireccion de PX: %p", &px);

    *px = 8; //Le cambiamos el valor de X a traves de su puntero
    printf("Nuevo valor de x: %d \t %d", x, *px);

    /////////////
    //  COSAS  //
    ////////////

    //En la declaracion
    // * puntero

    // Dentro del cuerpo del codigo
    // * = contenido direccion (por ejemplo *px va a darme el contenido de la direccion de x, o sea, 5)
    // & = direccion

    //Variables en memoria:
    //Las variables se van reservando de abajo para arriba (esto es porque se guardan en una pila en la primera pasada del compilador). Es por eso que PX tiene una direccion de memoria.
    //menor que X.
    //Ademas, si una variable no tiene un valor asignado, si no se usa para nada, no ocupa espacio en memoria, no se hace un malloc.
    //Esto lo detecta el compilador, y de ahi viene la warning "unused variable"

    return 0;
}
