#include "funciones.h"

//El nombre de una funcion es un puntero constante a donde empieza la funcion

//definir un vector de enteros hardcodeado, ordenarlo con qsort de mayor a menor y menor a mayor
//tomar un array de structs, desordenado, hacer una funcion de comparacion que compare ap nombre dni
//hacer otra que compare por dni nombre apellido

int main()
{
    int vector[] = { 1, 44, 23, 20, 15, 2, 439, 0, 25};

    t_empleado emps[] = { { 235, "Jose", "Polverini", 250.00 }, { 222, "Juan", "Perez", 120.30 }, { 333, "Dario", "Oirad", 400.25 }, { 234, "Agustin", "Alvaro", 120.30},
    { 235, "Agustin", "Alvaro", 120.30} };

    qsort(vector, 9, sizeof(int), menorAMayor);
    mostrarVector(vector, 9);

    qsort(vector, 9, sizeof(int), mayorAMenor);
    mostrarVector(vector, 9);

//    qsort(emps, 5, sizeof(t_empleado), compararAND);
//    mostrarEmpleados(emps, 5);

    qsort(emps, 5, sizeof(t_empleado), compararDNA);
    mostrarEmpleados(emps, 5);

//    qsort(emps, 5, sizeof(t_empleado), compararDNAmayAMen);
//    mostrarEmpleados(emps, 5);

    return 0;
}
