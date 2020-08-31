#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructuras, estructuras y punteros, y otras yerbas

void mostrarAlum(t_alumno);

typedef struct
{
    int anio;
    int mes;
    int dia;
} t_fecha;

typedef struct
{
    int dni;
    char sexo;
    char apyn[50];
    t_fecha fecha;
} t_alumno;

/* Esto NO se puede hacer. La estructura NO es una porcion de memoria. No puedo asignarle un valor a algo que no esta en memoria.
La estructura es un tipo de datos, una forma de representar un conjunto de datos.
typedef struct
{
    int anio = 1;
    int mes = 2;
    int dia = 2;
} t_fecha;
*/

int main()
{
    //Declarar con casteo, primero se declara y luego se inicializa
    //t_alumno al1;
    // al1 = (t_alumno) { .dni = 123, .sexo = 'M', .apyn = 'Juan Perez', .fnac = { .dia = 31, .mes = 1, .anio = 2 } };

    t_alumno al1, al3;
    //Declaracion accediendo a la estructura directamente, se declara y se inicializa en la misma linea.
    //No se puede inicializar de esta forma luego de declararlo.
    t_alumno al2 = { 123, 'M', "Hola", { 1, 2, 3} };

    //Se pueden asignar estructuras asi
    al3 = al2;

    //O también asignando miembro a miembro, pero da mas paja asi
    strcpy(al1.apyn, "Juancito perez");
    al1.sexo = 'M';
    al1.dni = 1098293;
    al1.fecha.anio = 1997;
    al1.fecha.dia = 23;
    al1.fecha.mes = 12;

    //Copiamos el nombre de AL1 a AL3
    strcpy(al3.apyn, al1.apyn);
    printf("Ingrese el dia de nacimiento del al3: ");
    scanf("%d", &al3.fecha.dia);
    printf("\nIngrese el mes de nacimiento del al3: ");
    scanf("%d", &al3.fecha.mes);
    printf("\nIngrese el anio de nacimiento del al3: ");
    scanf("%d", &al3.fecha.anio);

    mostrarAlum(al3);

    //////////////////////////////////////
    //      PUNTEROS Y ESTRUCTURAS      //
    /////////////////////////////////////

    t_alumno *pal1, *pal2; //Puntero a la estructura
    pal1 = &al1; //pal1 apunta al alumno 1
    al2 = *pal1; //el alumno 2 ahora tendra los datos del alumno 1, asignados a traves de punteros
    pal2 = &al2;

    //Si lo que esta a la izquierda es un puntero y quiero acceder a la estructura
    //utilizo los simbolos ->
    printf("\nNombre alumno (con punteros y ->): %s", pal2->apyn);
    //Notacion vieja de ANSIC para acceder a una estructura a traves de punteros
    printf("\nNombre alumno (con punteros y (*puntero): %s", (*pal2).apyn);
    //Si lo que esta a la izquierda inmediantamente es puntero, va flecha
    //Si lo que esta a la izquierda inmediatamente es estructura, va punto
    //Por ejemplo: pal2->estructura
    //pal2->estructura.subestructura

    //Copiar una estructura a otra con punteros
    *pal2 = *pal1;


    /*mostrarAlum(al1);
    mostrarAlum(al2);*/

    return 0;
}

void mostrarAlum(t_alumno alum)
{
    printf("\nNombre de alumno: %s", alum.apyn);
    printf("\nDNI: %d", alum.dni);
    printf("\nSexo: %c", alum.sexo);
    printf("\nFecha nac: %d/%d/%d", alum.fecha.dia, alum.fecha.mes, alum.fecha.anio);
}
