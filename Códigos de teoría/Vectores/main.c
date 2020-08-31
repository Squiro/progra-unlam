#include <stdio.h>
#include <stdlib.h>
#define TAM 4

//Cosas sobre arrays, vectores, y otras yerbas

void inicVec(int *, int);

int main()
{
    int vec[TAM];
    int vec1[TAM] = {1,2,3,4};
    int vec2[] = {11, 12, 13, 14};
    //El compilador ignora los ultimos valores ingresados que sobrepasen TAM
    int vec3[TAM] = {21, 22, 23, 24, 25, 26, 27, 28, 29};

    *vec = 3; //Esto es lo mismo que vec[0] = 3

    int i;
    for (i=0; i < sizeof(vec3)/sizeof(int); i++)
        printf("%d ", vec3[i]);

    //////////////////////////////////////
    //      ARIMETICA DE PUNTEROS      //
    /////////////////////////////////////

    /*
    Si por ejemplo px = &x;
    si yo hago px++, estoy saltando 1 direccion, porque el puntero salta entre datos del mismo tipo de datos

    Con vectores:

    vec == vec[0]
    vec+1 == vec[1]
    vec+2 == vec[2]

    Esto se llama indireccion, ya que vec se queda fijo, lo que cambia es el subindice. Para el compilador, usar una notacion o la otra es lo mismo.

    vec++ es algo que NO se puede hacer, porque vec es algo CONSTANTE, que no se puede modificar. El operador ++ intenta asignar y modificar.

    //Asignacion de un puntero que apunta a un vec
    int vec[TAM];
    int *ov;

    pv = vec; (SIN EL AMPERSAND);
    pv = &vec[0];

    pv++;

    En este caso SI se puede utilizar el ++, ya que es un puntero que no es contasnte, a diferencia de vec.

    //Asignarles valores a un vector con un for
    int i;

    for (i=0; i < TAM; i++)
    {
        *pv++ = i*2; //Notar como incrementamos pv en cada ciclo. De otra forma, estariamos asignandole siempre al mismo valor.
    }

    for (i=0; i < TAM; i++)
    {
        printf("\n%d", *pv);
        *pv = i *2; //ESTO ESTA MAL, NO PUEDO ASIGNARLE ENTEROS A UNA DIRECCION DE MEMORIA
                    // Y ademas, no "rebobinamos" el puntero xd
    }
    */
    return 0;
}

int inicVec(int* vec, int size)
{
    int i;
    for (i=0; i < size; i++)
        *vec++ = i*2; //En este caso SI podemos utilizar esta forma, ya que el vec que recibe esta funcion
                        //no es el mismo que el vec del main, C copia los valores de las cosas que pasamos como parametros

}

void mostrarVec(int vec, int size)
{
    int i;

    for (i=0; i<size; i++)
    {
        printf("\n%d", *vec);
        vec++;
    }
}
