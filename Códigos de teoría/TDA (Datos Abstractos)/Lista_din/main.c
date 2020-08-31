#include <stdio.h>
#include <stdlib.h>
#include "lista_din.h"

/*
    Sobre LISTAS

    Una lista es una serie de elementos que pueden o no tener orden.
    Al momento de agregar un elemento, tengo que tener en cuenta su orden.
    Al momento de sacar uno, no necesariamente respete un orden.

    A diferencia de las pilas y las colas, puedo recorrer las listas.

    Una lista estática va a ser un array (vector), con una cant. de elem, dentro de un TDA.

    Listas simplemente enlazadas:

    En las listas simplemente enlazadas, el puntero de posicion siempre apunta al primer elemento de la lista.
*/

int main()
{
    t_lista lista;
    t_dato emp;

    crearLista(&lista);

    emp.id = 5;
    strcpy(emp.nombre, "Algo");
    insertarFinal(&lista, &emp);
    emp.id = 2;
    insertarFinal(&lista, &emp);
    emp.id = 2;
    insertarFinal(&lista, &emp);
    emp.id = 2;
    strcpy(emp.nombre, "Alga");
    insertarFinal(&lista, &emp);
    emp.id = 3;
    insertarFinal(&lista, &emp);
    emp.id = 2;
    insertarFinal(&lista, &emp);
    emp.id = 4;
    insertarFinal(&lista, &emp);
    //quitarDuplicados(&lista, compararEmp);
    //quitarTodosDuplicados(&lista, compararEmp);
    //quitarNoDuplicados(&lista, compararEmp);
    ordernarLista(&lista, compararEmp);
    recorrerLista(&lista);

    /* Pruebas de primitiva quitarClave, con estructura de datos distinta

    emp.id = 1;
    strcpy(emp.nombre, "Algo");
    insertarFinal(&lista, &emp);
    quitarClave(&lista, &emp, compararEmp);
    emp.id = 2;
    strcpy(emp.nombre, "Algo");
    insertarFinal(&lista, &emp);
    recorrerLista(&lista);*/


    /* Prueba de primitivas insertarOrdenado, quitarPrimero, quitarUltimo, con enteros

    int num;

    int i, siete = 7;

    for (i = 0; i < 10; i++)
    {
        if (i != 7)
            insertarFinal(&lista, &i);
    }

    insertarOrdenado(&lista, &siete, compararEnteros);
    quitarPrimero(&lista, &num);
    printf("NUM: %d\n", num);
    quitarUltimo(&lista, &num);
    printf("NUM: %d\n", num);
    recorrerLista(&lista);*/
    return 0;
}
