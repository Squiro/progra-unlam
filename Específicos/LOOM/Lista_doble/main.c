#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

/**
    Dada una lista doblemente enlazada, desordenada.
    El puntero a la lista está apuntando al último nodo tratado.
    Estructura del dato: pci (provincia - char 20) | ciu (ciudad - char 20) | loc (localidad - char 20) | cantH (cantidad de habitantes)
    Clave: Provincia - Ciudad
    Ordenarla por clave.
    Debe quedar un único nodo por clave con la cantidad total de habitantes de dicha clave. El nombre de la LOCALIDAD debe reemplazarse por la palabra TOTAL.
    Al finalizar el proceso de ordenamiento, la lista debe quedar apuntando a la misma clave en que comenzó el proceso.
*/

int main()
{
    t_lista lista;
    t_localidad locs[4] = { { "Bs. As. - Moron", "Bs. As.", "Moron", "Moron", 20 }, { "Bs. As. - Ituzaingo", "Bs. As.", "Ituzaingo", "Ituzaingo", 10 },
    { "Cordoba - Cordoba", "Cordoba", "Cordoba", "Cordoba", 15 }, { "Bs. As - Hurlingham" , "Bs. As.", "Hurligham", "Moron", 25} };
    int i;
    crearLista(&lista);

    for (i = 0; i < 4; i++)
        insertarFinal(&lista, &locs[i]);

    mostrar(&lista);
    ordenarLista(&lista);
    cambiarNombreLocalidad(&lista, "TOTAL");
    printf("\n\n DESPUES \n\n");
    mostrar(&lista);

    return 0;
}
