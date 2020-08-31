#include <stdio.h>
#include <stdlib.h>
#include <utilitarias.h>
#include <varias.h>
#include <arbol.h>
#include <cola.h>
#include "lista_doble.h"

void imprimir_mensaje(int res);
void op_alta(t_arbol * pa);
void op_baja(t_arbol * pa);
void op_mayor_promedio(const t_arbol * pa);
void op_mostrar_arbol(const t_arbol * pa);
void op_listar_alumnos(const t_arbol * pa);
void op_validar_arbol(const t_arbol * pa);
void op_listar_alumnos_asc(const t_lista * pl);
void op_listar_alumnos_desc(const t_lista * pl);

int main()
{
    const char opciones [][TAM_MENU] = {"ABIPLVMNS",
                                        "Alta",
                                        "Baja Masiva",
                                        "Mostrar Arbol",
                                        "Mayor Promedio",
                                        "Listar Alumnos",
                                        "Validar Arbol",
                                        "Listar alumnos (asc)",
                                        "Listar alunmnos (desc)",
                                        "Salir"};
    char op;
    t_arbol arbol;
    t_lista lista;

    crearLista(&lista);
    crear_arbol_res(&arbol);
    //cargar_arbol_de_archivo_ordenado_res(&arbol,"..\\archivos\\alumnos.dat");
    cargar_arbol_de_archivo_preorden(&arbol,"..\\archivos\\alumnos.dat");
    //Lleno la lista doble
    recorrer_arbol_pre(&arbol, enlistar, &lista);

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
            case 'M':
                op_listar_alumnos_asc(&lista);
                break;
            case 'N':
                op_listar_alumnos_desc(&lista);
                break;
        }
    }while(op!='S');
    //grabar_arbol_en_archivo_ordenado_res(&arbol,"..\\archivos\\alumnos.dat");
    grabar_arbol_en_archivo_preorden(&arbol,"..\\archivos\\alumnos.dat");
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
    //mayor_promedio_res(pa);
    mayor_promedio(pa);
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

void op_listar_alumnos_asc(const t_lista * pl)
{
    printf("\n\n");
    listar_alumnos_asc(pl);
    pausa("\n\n");
}

void op_listar_alumnos_desc(const t_lista * pl)
{
    printf("\n\n");
    listar_alumnos_desc(pl);
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
