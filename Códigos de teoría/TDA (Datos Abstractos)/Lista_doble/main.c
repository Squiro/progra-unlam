#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

/*  Lista doblemente enlazada ORDENADA

    El nodo apunta al siguiente y al anterior

    La lista en el main apunta a cualquier nodo, ya que puedo recorrer la lista para cualquier lado

    Usamos 4 punteros en total para movernos en la lista:

    Usamos un puntero nuevo para el nuevo nodo
    Y un puntero actual que recorre la lista para encontrar el lugar donde quiero ponerlo

    1. nuevo-> nuevo nodo
    2. act-> recorreLista
    3. anteriorAux-> anterior del nuevo
    4. sigAux-> siguiente del nuevo

    El puntero a lista doble siempre queda apuntando al ultimo nodo tratado (A LA ULTIMA CLAVE QUE SE TRATO*)
    (ultimo en ser agregado, anterior o siguiente del que se borro)
*/

int main()
{
    int x = 10;
    t_listaD lista;
    crearLista(&lista);
    insertarOrdenado(&lista, &x, compararEnteros);
    x = 9;
    insertarOrdenado(&lista, &x, compararEnteros);
    x = 10;
    //verActual(&lista, &x);
    printf("ACTUAL: %d\n", x);
    eliminarClave(&lista, &x, compararEnteros);
    x = 0;
    verActual(&lista, &x);
    printf("ACTUAL: %d\n", x);
    x = 11;
    eliminarClave(&lista, &x, compararEnteros);
    verActual(&lista, &x);
    printf("ACTUAL: %d\n", x);

    return 0;
}
