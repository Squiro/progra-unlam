#include "funciones.h"

/*
    Ejercicio 13: dados dos archivos binarios de empleados y estudiantes, hacer un programa que aumente el sueldo de los empleados
    en base a su promedio como estudiantes.
*/

int main()
{
    generarEmpleados(2);
    generarEstudiantes(2);
    leerEstudiantes();
    mostrarEmpleados();


    return 0;
}
