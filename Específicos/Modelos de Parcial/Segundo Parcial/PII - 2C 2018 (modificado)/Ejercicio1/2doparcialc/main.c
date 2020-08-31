#include <stdio.h>
#include <stdlib.h>
#include <utilitarias.h>
#include <varias.h>
#include <arbol.h>
#include <cola.h>
#include "indice.h"
#include "arbol_indice.h"

void imprimir_mensaje(int res);
void op_alta(t_arbol * pa);
void op_baja(t_arbol * pa);
void op_mayor_promedio(const t_arbol * pa);
void op_mostrar_arbol(const t_arbol * pa);
void op_listar_alumnos(const t_arbol * pa);
void op_validar_arbol(const t_arbol * pa);
void op_crear_indice_apyn(t_arbol_indice * pa, const char * path, const char * rutaIdx);
void op_listar_ape_desc(const char * path, const char * rutaIdx);
void op_prom_general(const t_arbol * pa);

int main()
{

    const char rutaIdx[] = "..\\archivos\\ape.idx";
    const char opciones [][TAM_MENU] = {"ABIPLVCMOS",
                                        "Alta",
                                        "Baja Masiva",
                                        "Mostrar Arbol",
                                        "Mayor Promedio",
                                        "Listar Alumnos",
                                        "Validar Arbol",
                                        "Crear Indice APYN",
                                        "Listar ape desc",
                                        "Promedio general",
                                        "Salir"};
    char op;
    t_arbol arbol;
    t_arbol_indice arbIdx;

    crear_arbol_res(&arbol);
    cargar_arbol_de_archivo_ordenado_res(&arbol,"..\\archivos\\alumnos.dat");

    crear_arbol_indice(&arbIdx);

    do{
        op=menu(opciones, "Menu Principal");
        switch (op)
        {
            case 'A':
                op_alta(&arbol);
                break;
            case 'B':
                op_baja(&arbol);
                break;
            case 'I':
                op_mostrar_arbol(&arbol);
                break;
            case 'P':
                op_mayor_promedio(&arbol);
                break;
            case 'L':
                op_listar_alumnos(&arbol);
                break;
            case 'V':
                op_mayor_promedio(&arbol);
                break;
            case 'C':
                op_crear_indice_apyn(&arbIdx, "..\\archivos\\alumnos.dat", rutaIdx);
              break;
            case 'M':
                op_listar_ape_desc("..\\archivos\\alumnos.dat", rutaIdx);
              break;
            case 'O':
                op_prom_general(&arbol);
              break;
        }
    }while(op!='S');
    grabar_arbol_en_archivo_ordenado_res(&arbol,"..\\archivos\\alumnos.dat");
    vaciar_arbol_res(&arbol);
    return 0;
}

void op_alta(t_arbol * pa)
{
    int res;
    t_alumno alu;
    ingresar_dni_alumno_res(&alu);
    res= alta_res(alu.dni, pa);
    imprimir_mensaje(res);
}

void op_baja(t_arbol * pa)
{
    int res;
    t_cola cola;
    crear_cola_res(&cola);
    res= cargar_bajas_masiva_res(&cola);
    if(res!=TODO_OK)
    {
        imprimir_mensaje(res);
        return;
    }
    res= baja_masiva_res(pa, &cola);
    vaciar_cola_res(&cola);
    imprimir_mensaje(res);
}

void op_mostrar_arbol(const t_arbol * pa)
{
    printf("\n\n");
    arbol_grafico_res(pa, mostrar_dni_res);
    pausa("\n\n");
}

void op_mayor_promedio(const t_arbol * pa)
{
    printf("\n\nALUMNO CON MAYOR PROMEDIO\n\n");
    mayor_promedio_res(pa);
    pausa("\n\n");
}

void op_listar_alumnos(const t_arbol * pa)
{
    printf("\n\n");
    imprimir_listado_res(pa);
    pausa("\n\n");
}

void op_validar_arbol(const t_arbol * pa)
{
    printf("\n\n");
    validar_arbol_res(pa);
    pausa("\n\n");
}

void op_crear_indice_apyn(t_arbol_indice * pa, const char * path, const char * rutaIdx)
{
    printf("\n\n");
    crearIndice(pa, path, rutaIdx);
    pausa("\n\n");
}

void op_listar_ape_desc(const char * path, const char * rutaIdx)
{
    printf("\n\n");
    listar_ape_desc(path, rutaIdx);
    pausa("\n\n");
}

void op_prom_general(const t_arbol * pa)
{
    printf("\n\n");
    promedio_general(pa);
    pausa("\n\n");
}

void imprimir_mensaje(int res)
{
    switch(res)
    {
        case TODO_OK: pausa("Operacion realizada correctamente.");
                break;
        default: pausa("Error al realizar la operacion.");

    }
}
