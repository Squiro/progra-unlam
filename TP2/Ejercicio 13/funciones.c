#include "funciones.h"

void generarEmpleados(int cant)
{
    FILE * arch;

    //Esto se simplificó usando un vector de la estructura correspondiente, inicializándolo con los datos
    //necesarios.
    t_empleado emps[] = { { 36789234, "Alvaro", "Jose", 2500.50 },
        { 37891324, "Berto", "Pedro", 3000 },
        { 39222123, "Cassini", "Tomas", 1550.25 },
        { 40808298, "Doria", "Sargento", 4900 }

    };

    //Siempre abrir el archivo de acuerdo a lo que uno va a hacer y SOLO para eso. Si vamos a escribir
    //solo lo abrimos en modo escritura.
    arch = fopen("empleados.bin", "wb");

    //Si no se pudo abrir el archivo, el puntero quedará nulo, y eso es signo de que hubo un error.
    //Este chequeo es mandatorio.
    if (!arch)
        exit(1); //exit, al contrario de return, obliga al programa ENTERO a cerrarse, y retornar 1. No solo a la funcion en la que estamos.


    //Esto se simplifico utilizando solamente un fwrite con la cantidad de veces en el parametro t_nmem (el tercero)
    //Guarda todo el array sin necesidad de cant: fwrite(emps, sizeof(emps), 1, arch);
    fwrite(emps, sizeof(t_empleado), cant, arch);

    //Cerramos el archivo
    fclose(arch);
}

void generarEstudiantes(int cant)
{
    FILE * arch;

    t_estudiante ests[] = { { 36789234, "Alvaro", "Jose", 6.33 },
        { 37891324, "Berto", "Pedro", 8 },
        { 39222123, "Cassini", "Tomas", 9 },
        { 40808298, "Doria", "Sargento", 2 }

    };

    //Siempre abrir el archivo de acuerdo a lo que uno va a hacer y SOLO para eso. Si vamos a escribir
    //solo lo abrimos en modo escritura.
    arch = fopen("estudiantes.bin", "wb");

    //Si no se pudo abrir el archivo, el puntero quedará nulo, y eso es signo de que hubo un error.
    //Este chequeo es mandatorio.
    if (!arch)
        exit(1); //exit, al contrario de return, obliga al programa ENTERO a cerrarse, y retornar 1. No solo a la funcion en la que estamos.
    //Tratar de no usar exit, utilizar returns para poder capturarlos


    fwrite(ests, sizeof(t_estudiante), cant, arch);

    //Cerramos el archivo
    fclose(arch);
}

void leerEstudiantes()
{
    FILE * arch;
    t_estudiante est;

    arch = fopen("estudiantes.bin", "rb");

    if (!arch)
        exit(1);

    //Lectura principal
    fread(&est, sizeof(est), 1, arch);

    while (!feof(arch))
    {
        if (est.promedio > 7.00)
            aumentarSueldo(est.dni);

        //Leemos otro registro
        fread(&est, sizeof(est), 1, arch);
    }

    fclose(arch);
}

void aumentarSueldo(int dni)
{
    FILE * arch;
    t_empleado emp;

    //Abrimos el archivo en modo read/update
    arch = fopen("empleados.bin", "rb+");

    if (!arch)
        exit(1);

    //Lectura principal
    fread(&emp, sizeof(emp), 1, arch);

    while (!feof(arch))
    {
        if (emp.dni == dni)
        {
            emp.sueldo = emp.sueldo + ((emp.sueldo*7.28)/100);

            //acá vamos a MODIFICAR el registro que ya leimos, por lo que hay que volver un registro atrás!
            fseek(arch, -sizeof(emp), SEEK_CUR);
            fwrite(&emp, sizeof(emp), 1, arch);
        }
        //Como el fread y el fwrite quedaron "contiguos", hay que darle un golpecito para que cambia de modo (de lectura a escritura)
        //If you have a file opened for update and you want to switch from reading to writing or vice versa, you must do an "fseek" (or "rewind" or some similar operation).
        fseek(arch, 0L, SEEK_CUR);
        //Siguiente lectura
        fread(&emp, sizeof(emp), 1, arch);
    }

    fclose(arch);
}

void mostrarEmpleados()
{
    FILE * arch;
    t_empleado emp;

    arch = fopen("empleados.bin", "rb+");

    if (!arch)
        exit(1);

    fread(&emp, sizeof(emp), 1, arch);

    while (!feof(arch))
    {
        printf("\n\nDNI: %d", emp.dni);
        printf("\nApellido: %s", emp.apellido);
        printf("\nNombre: %s", emp.nombre);
        printf("\nSueldo: %0.3lf", emp.sueldo);

        fread(&emp, sizeof(emp), 1, arch);
    }

    fclose(arch);
}
