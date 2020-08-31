#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int dni;
    char apellido[50];
    char nombre[50];
    double sueldo;
} t_empleado;

typedef struct
{
    int dni;
    char apellido[50];
    char nombre[50];
    float promedio;
} t_estudiante;

/** Genera un archivo que contiene los empleados, ordenados alfabéticamente por apellido/nombre.
* PARAM: cant -> indica la cantidad de registros que se van a guardar.
*/
void generarEmpleados(int cant);

/** Genera un archivo que contiene los estudiantes, ordenados alfabéticamente por apellido/nombre.
* PARAM: cant -> indica la cantidad de registros que se van a guardar.
*/
void generarEstudiantes(int cant);


/** Lee todos los estudiantes que haya en el archivo de empleados, ejecutando la lógica necesaria según corresponda
*
*/
void leerEstudiantes();


/** Recibiendo un DNI (que es usado como ID), aumenta el sueldo del empleado correspondiente en un 7,28%
*
*/
void aumentarSueldo(int dni);


/** Muestra el archivo empleados por pantalla.
*
*/
void mostrarEmpleados();
#endif // FUNCIONES_H_
