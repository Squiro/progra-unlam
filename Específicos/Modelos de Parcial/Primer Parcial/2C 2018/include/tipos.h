#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

///estructura para el archivo alumnos.bin
typedef struct
{
    long dni;
    char apyn[30];
}t_alumno;


///Estructura para el archivo notas.txt
typedef struct
{
    long dni;
    char tipo[3];
    int nota;
}t_nota;

///estructura para el archivo acta.txt
typedef struct
{
    long dni;
    char apyn[30];
    int p1,
        p2,
        r1,
        r2,
        nota;
    char cond[4];
}t_acta;

typedef t_acta t_info;

typedef int (*t_cmp)(const void *, const void *);

#endif // TIPOS_H_INCLUDED
