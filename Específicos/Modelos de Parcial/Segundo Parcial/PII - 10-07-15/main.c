#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "menu.h"

/* Parte de lenguaje C:

    Un instituto educativo cuenta con un programa que administra las altas y bajas de su base de datos de alumnos (el archivo binario alumnos.dat).
    Este archivo utiliza como clave el DNI del alumno, pero no est� ordenado En su lugar utiliza un �ndice (implementado en un �rbol binario de b�squeda)
    y almacenado en el archivo alumnos.idx. El programa presenta un men� donde permite ver qu� operaci�n se desea realizar:
        -Alta
        -Baja
        -Listar el �ndice
        -Listar el archivo de alumnos

    Se pide:
     -Desarrollar la funcion alta. Que debe, adem�s de agregar al alumno al final del archivo alumnos.dat, insertar el registro en el �ndice.
     -Desarollar la funci�n baja. Que debe dar una baja l�gica al registro (estado = 'B') y borrar del �ndice la entrada.
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
