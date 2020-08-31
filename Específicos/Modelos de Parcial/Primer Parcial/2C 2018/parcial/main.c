#include <stdio.h>
#include <stdlib.h>
#include <actas.h>
#include <utilitarias.h>

int main()
{

    /*crear_archivo_alumnos("../Archivos/alumnos.bin");

    printf("\n\n*********ALUMNOS***********\n");
    mostrar_archivo_alumnos("../Archivos/alumnos.bin");
    printf("\n*********FIN ALUMNOS***********\n\n");
    printf("\n\n*********NOTAS***********\n");
    mostrar_archivo_notas("../Archivos/notas.txt");
    printf("\n*********FIN NOTAS***********\n\n");*/

    /**
        Esta función debe crear el acta
    */
    generar_acta_res("../Archivos/alumnos.bin","../Archivos/notas.txt", "../Archivos/acta.txt", "../Archivos/observaciones.txt");
    ///generar_acta("../Archivos/alumnos.bin","../Archivos/notas.txt", "../Archivos/acta.txt", "../Archivos/observaciones.txt");

    /*printf("\n\n*********ACTA***********\n");
    mostrar_archivo_acta("../Archivos/acta.txt");
    printf("\n*********FIN ACTA***********\n\n");
    printf("\n\n*********OBSERVACIONES***********\n");
    mostrar_archivo_errores("../Archivos/observaciones.txt");
    printf("\n*********FIN OBSERVACIONES***********\n\n");*/

    return 0;
}
