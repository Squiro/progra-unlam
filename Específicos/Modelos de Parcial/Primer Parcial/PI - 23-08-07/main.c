#include "funciones.h"

int main()
{

    /** Ejercicio 1
    char cad[] = "hola";
    int mat[TAM][TAM] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    printf("%s", invertirCadena(cad));
    triangularInferior(mat, 3); */

    generarLote();
    incrementarPrecio();
    mostrarArchivo();

    t_lista lista;
    crearLista(&lista);
    guardarEnLista(&lista);
    ordenarLista(&lista, compararMotos);
    mostrarLista(&lista);
    quitarMarca(&lista);
    mostrarMayoresA(&lista, 10000);
    return 0;
}
