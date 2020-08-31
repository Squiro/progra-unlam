#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED


#define TODO_OK 1
#define SIN_MEM 0
#define ERROR_ARCHIVO 0
#define DUPLICADO 0
#define NO_EXISTE 0
#define VERDADERO 1
#define FALSO 0


typedef struct
{
	int dni;
	char apyn[30];
	int notas[50];
	int cant_materias;
}
t_alumno;


typedef t_alumno t_info;

typedef int t_info_cola;


#endif // TIPOS_H_INCLUDED
