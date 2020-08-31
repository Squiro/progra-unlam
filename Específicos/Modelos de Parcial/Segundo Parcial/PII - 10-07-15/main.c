#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "menu.h"

/* Parte de lenguaje C:

    Un instituto educativo cuenta con un programa que administra las altas y bajas de su base de datos de alumnos (el archivo binario alumnos.dat).
    Este archivo utiliza como clave el DNI del alumno, pero no está ordenado En su lugar utiliza un índice (implementado en un árbol binario de búsqueda)
    y almacenado en el archivo alumnos.idx. El programa presenta un menú donde permite ver qué operación se desea realizar:
        -Alta
        -Baja
        -Listar el índice
        -Listar el archivo de alumnos

    Se pide:
     -Desarrollar la funcion alta. Que debe, además de agregar al alumno al final del archivo alumnos.dat, insertar el registro en el índice.
     -Desarollar la función baja. Que debe dar una baja lógica al registro (estado = 'B') y borrar del índice la entrada.
     -Desarrollar las funciones insertar_en_arbol_bin_busq Y buscar_en_arbol_bin_busq. Y elegir entre las funciones eliminar_de_arbol
     o cargar_arbol_de_archivo_ordenado y desarrollar una de las dos.

        Desarrrole y utilice todas las funciones que le sean necesarias.
*/

int main()
{
    char rutaAlum[] = "alumnos.dat", rutaIdx[] = "alumnos.idx";
    t_arbol arbol;

    crearArbol(&arbol);
    generarArchivoAlum(rutaAlum);
    generarIndice(&arbol, rutaAlum, rutaIdx);
    menu(&arbol, rutaAlum, rutaIdx);
    return 0;
}
