#include <stdio.h>
#include <stdlib.h>

/*

    MEMORIA DINAMICA

    Malloc, free, realloc, calloc

*/

int main()
{
    //void * malloc (size_t tam);
    //Siempre después de asignar un espacio de memoria con malloc hay que chequear que realmente
    //se haya asignado. Necesitamos hacer un if (!var) para ver si retornó nulo


    //void free(void *);
    //Una vez que yo liberé una memoria, no debo volver a acceder a ella ni usarla. Porque ya no me pertenece.

    //Ejemplo
    /**int *p1;
    p1 = (int *) malloc(sizeof(int));

    if (!p1)
    {
        //Retornamos error
        return 99;
    }
    else
        free(p1);*/

    /**
    int * p1;
    p1 = (int *) malloc(sizeof(int)*20);

    if (!p1)
        return 99;

    *(p1+9) = 123;
    p1[9] = 123;*/

    //p1++; ! ! ! ! ! !  ! ! ! ! !
    //Hay que tener cuidado con perder la posicion de inicio, porque despues no vamos a poder hacer
    //el free de memoria

    //void * calloc(size_t ce, size_t tam);
    //clear allocation, inicializa todo en 0

    /** Asigna 20 elementos y los deja limpitos
    int *p2 = (int *)calloc(20, sizeof(int));

    if (!p2)
        return SIN_MEMORIA;
    */

    //void * realloc(void * ptr, size_t tam);
    //REUBICA.
    //cambia el tamaño de un bloque de memoria, pero puede reubicarlo, significando que la dir. de mem. va a cambiar
    //el contenido del bloque de memoria es preservado hasta el ultimo elemento del tamaño original
    // /!\ Hay que tener cuidado con asignar realloc a un mismo puntero, porque si no se puede asignar, vamos a perder todo!
    //Si el ptr es null, se comporta como malloc, si el tamaño es 0, se comporta como free

    return 0;
}
