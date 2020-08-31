#include "menu.h"
#include "funciones.h"

void menu(t_arbol * pa, char * rutaAlum, char * rutaIdx)
{
    int num;

    printf("\t\t\t----MENU----\n\n");
    printf("1. Dar de alta\n");
    printf("2. Dar de baja\n");
    printf("3. Listar el indice\n");
    printf("4. Listar el archivo de alumnos\n");

    printf("\nSeleccione una opcion: ");
    scanf("%d", &num);
    while (!seleccion(num, pa, rutaAlum, rutaIdx))
    {
        printf("Opcion incorrecta, seleccione bien.");
        printf("\nSeleccione una opcion: ");
        scanf("%d", &num);
    }

}

int seleccion(int num, t_arbol * pa, char * rutaAlum, char * rutaIdx)
{
    switch(num)
    {
        case 1:
            alta(pa, rutaAlum, rutaIdx);
            mostrarArchivoAlum(rutaAlum);
            mostrarIndice(rutaIdx);
            break;
        case 2:
            baja(pa, rutaAlum, rutaIdx);
            mostrarArchivoAlum(rutaAlum);
            mostrarIndice(rutaIdx);
            break;
        case 3:
            mostrarIndice(rutaIdx);
            break;
        case 4:
            mostrarArchivoAlum(rutaAlum);
            break;
        default:
            return 0;
            break;
    }

    return 1;
}
