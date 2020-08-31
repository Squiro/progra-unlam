#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "menu.h"

int main()
{
    int i, arr[9] = { 1, 23, 44, 2, 4, 6, 99, 8, 10}, num;
    t_arbol arbol;
    crearArbol(&arbol);

    for (i = 0; i < 9; i++)
        insertarClaveIterativo(&arbol, &arr[i], compararEnteros);

    printf("----MENU----\n\n");
    printf("1. Recorridos recursivos e iterativos\n\n");
    printf("2. Buscar clave\n\n");
    printf("3. Guardar y recuperar de archivo\n\n");
    printf("4. Contar nodos, hojas, etc\n\n");
    printf("5. Cortar hojas\n\n");
    printf("6. Mostrar nodos en...\n\n");
    printf("7. Busqueda de nodos y claves...\n\n");
    printf("8. Podar hasta nivel\n\n");
    printf("Ingrese la opcion: ");
    scanf("%d", &num);
    menu(num, &arbol);

    return 0;
}
