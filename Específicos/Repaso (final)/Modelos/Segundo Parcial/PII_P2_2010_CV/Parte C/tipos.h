#ifndef TIPOS_H_
#define TIPOS_H_

typedef struct
{
    long dni;
    char nombre[30];
} t_alumno;

typedef t_alumno t_dato;

typedef int (*t_cmp)(const void *, const void *);

#endif // TIPOS_H_
