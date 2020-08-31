#include <lista.h>
#include <actas.h>
#include <utilitarias.h>

#define REDONDEO_POSITIVO(X) (((X)-(int)(X)) >= 0.5) ?((int)(X))+1 :(int)(X)
#define ERROR_ABRIR 99 //Error de apertura de archivo

void generar_acta_res(const char * path_alum, const char * path_notas, const char * path_acta, const char * path_obs)
{
    /* First things first: abrimos los archivos de cada path y comprobamos que se hayan abierto correctamente.

    Recordatorios:

        EXTENSIONES: -alumnos.BIN -> rb
                     -notas.TXT -> rt
                     -acta.TXT -> wt
                     -observaciones.txt -> wt
    */
    FILE *arch_alum, *arch_notas, *arch_acta, *arch_obs;

    arch_alum = fopen("../Archivos/alumnos.bin", "rb");

    if (!arch_alum)
        handle_error(ERROR_ABRIR);

    arch_notas = fopen("../Archivos/notas.txt", "rt");

    if (!arch_notas)
    {
        fclose(arch_alum);
        handle_error(ERROR_ABRIR);
    }

    arch_acta = fopen("../Archivos/acta.txt", "wt");

    if (!arch_acta)
    {
        fclose(arch_alum);
        fclose(arch_notas);
        handle_error(ERROR_ABRIR);
    }

    arch_obs = fopen("../Archivos/observaciones.txt", "wt");

    if (!arch_obs)
    {
        fclose(arch_alum);
        fclose(arch_notas);
        fclose(arch_acta);
        handle_error(ERROR_ABRIR);
    }

    /* Recorro el archivo de notas, agarro una cadena, la convierto a t_nota con la función utilitaria texto_a_nota_res
        Una vez que hago eso, busco el alumno en el archivo alumnos.bin, en base a su DNI.
        Guardo los datos del alumno en t_acta acta, tambien guardo su nota.

        Ahora tengo que avanzar otro registro mas de notas.txt, pero, ¿y si la nota que leo es del mismo alumno?
        Entonces tengo que chequear eso
    */

    t_lista lista;
    t_alumno alum;
    t_nota nota;
    t_acta acta;
    char cad_nota[1024];

    //Creamos la lista
    //crear_lista_res(&lista);

    //Seteamos en 0 al DNI acta, para lo de la primera vuelta
    inicializarActa(&acta, 0);

    //Leo un registro del archivo notas
    fgets(cad_nota, 1024, arch_notas);

    while(!feof(arch_notas))
    {
        texto_a_nota(cad_nota, &nota);

        if (buscar_alumno(nota.dni, &alum, arch_alum))
        {
            //Buscamos al alumno y lo encontramos. Ahora, necesitamos chequear si este alumno es el mismo que el de la anterior busqueda

            //Si el DNI es el mismo, o es la primera vuelta que damos, entonces lo que hacemos es guardar las nuevas notas que juntamos, porque es
            //el mismo alumno
            if (acta.dni == 0 || acta.dni == alum.dni)
            {
                acta.dni = alum.dni;
                strcpy(acta.apyn, alum.apyn);

                //Evaluo de qué tipo de nota es la que estoy guardando
                if (strcmp(nota.tipo, "P1") == 0)
                    acta.p1 = nota.nota;
                else if (strcmp(nota.tipo, "P2") == 0)
                    acta.p2 = nota.nota;
                else if (strcmp(nota.tipo, "R1") == 0)
                    acta.r1 = nota.nota;
                else if (strcmp(nota.tipo, "R2") == 0)
                    acta.r2 = nota.nota;
            }
            //Si no es el mismo alumno, entonces quiere decir que ya tenemos un nuevo alumno y que debemos "guardar" el anterior
            else
            {
                //Calculamos la nota final
                calcular_nota_final(&acta);
                //La validamos
                validar_nota_final(&acta, arch_obs);
                //Lo insertamos en la lista
                //insertar_act_lista(&lista, &acta, compararActas, )

                //Inicializamos un nuevo acta
                inicializarActa(&acta, alum.dni);
            }
        }
        else
            fprintf(arch_obs, "Error: no se ha encontrado al alumno con DNI %li.\n", nota.dni);

        //Leemos otro registro del archivo notas
        fgets(cad_nota, 1024, arch_notas);
    }
}

int buscar_alumno(long dni, t_alumno * alum, FILE * arch)
{
    /* El archivo alumnos.bin ya esta abierto cuando llegamos acá */

    t_alumno reg;

    fread(&reg, sizeof(t_alumno), 1, arch);

    //Como alumno.bin está ordenado por dni, si encontramos un dni más grande que el que tenemos... bueno, nos vamos, porque no existe ese alumno
    while (!feof(arch) && reg.dni < dni)
    {
        if (reg.dni == dni)
        {
            strcpy(alum->apyn, reg.apyn);
            return 1;
        }
    }

    //Si no encontramos el alumno, necesitamos hacer un rewind del archivo, y devolver 0
    rewind(arch);
    return 0;
}

void inicializarActa(t_acta *acta, long dni)
{
    acta->dni = dni;
    acta->p1 = acta->p2 = acta->r1 = acta->r2 = 0;
}

void calcular_nota_final(t_acta *a)
{
    int p1, p2;

    /* Según el archivo de actas generado por el proyecto, las notas de los recuperatorios son 0 si no se rindieron
        entonces, tenemos que chequear si la nota del recupetario es 0 o no, y pisar el valor del parcial. */
    p1 = (a->r1 != 0) ? a->r1 : a->p1;
    p2 = (a->r2 != 0) ? a->r2 : a->p1;

    /* Debemos realizar el chequeo de si las notas están en el mismo grupo.
        Los grupos son: -	Ausente
                        -	las de reprobación (1 a 3),
                        -	las de cursada (4 a 6)
                        -	las de promoción (7 a 10)

        Si están en el mismo grupo, la nota es el promedio de ambas.
        Si están en grupos diferentes, la nota es la más chica.
        Si la nota de alguno de los dos parciales queda en ausente, la nota final es ausente.
    */

    //Si alguna de las notas quedó en 0, independientemente de cual sea, la nota final es ausente (0).
    if (p1 == 0 || p2 == 0)
        a->nota = 0;
    else if (mismo_grupo(p1, p2))
        a->nota = REDONDEO_POSITIVO((p1+p2)/2.0);
    else
        a->nota = p1 < p2 ? p1 : p2;
}

int mismo_grupo(int p1, int p2)
{
    return (p1>=1 && p1<=3 && p2>=1 && p2<=3) || (p1>=4 && p1<=6 && p2>=4 && p2<=6) || (p1>=7 && p1<=10 && p2>=7 && p2<=10);
}

void validar_nota_final(const t_acta *a, FILE * arch_obs)
{
    /* Debemos chequear si:
        -Alguna de las notas de los parciales es igual a 0 (ausente).
        -Si algún alumno recuperó un parcial en el que tenía más de 7.
        -Si algún alumno tiene dos recuperatorios.
    */

    if (a->r1 != 0 && a->r2 != 0)
    {
        strcpy(a->cond, "Err");
        fprintf(arch_obs, "Error, el alumno %s (%li) rindió 2 recuperatorios.\n", a->apyn, a->dni);
        return;
    }
    else if (a->nota == 0)
        strcpy(a->cond, "Aus");
    else if (a->nota >= 1 && a->nota <= 3)
        strcpy(a->cond, "Rec");
    else if (a->nota >= 4 && a->nota <= 6)
        strcpy(a->cond, "Apr");
    else if (a->nota >= 7 && a->nota <= 10)
        strcpy(a->cond, "Pro");

    if(a->p1 >=7 && a->r1!= 0)
        fprintf(arch_obs, "Advertencia, el alumno %s (%li) recuperó el parcial 1 habiéndolo aprobado con %d\n", a->apyn, a->dni, a->p1);

    if(a->p2>=7 && a->r2 != 0)
        fprintf(arch_obs,"Advertencia, el alumno %s (%li) recuperó el parcial 2 habiéndolo aprobado con %d\n",a->apyn,a->dni,a->p2);
}

int compararActas(const void * arg1, const void * arg2)
{
    t_acta * dato1 = (t_acta *) arg1, * dato2 = (t_acta *) arg2;

    return strcmp(dato1->apyn, dato2->apyn);
}

void handle_error(int err)
{
    FILE * arch;

    arch = fopen("../Archivos/errorlog.txt", "at");

    if (err == ERROR_ABRIR)
        fprintf(arch, "Uno de los archivos esenciales para la operación no pudo ser abierto.\n");

    fclose(arch);
    exit(err);
}
