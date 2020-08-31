#include "menu.h"


void menu(t_arbol * pa, char * rutaAlum, char * rutaIdx)
{
    int i;
    char op;
    const char menu[][32] = {   "1234",
                                "Alta",
                                "Baja",
                                "Listar el indice",
                                "Listar archivo alumnos"
    };

    printf("\t\t\t MENU\n");

    for (i = 1; i <= strlen(menu[0]); i++)
        printf("\n %c - %s", menu[0][i-1], menu[i]);

    printf("\n\nSeleccione la opcion: ");
    scanf("%c", &op);

    while (!(strchr(menu[0], op)))
    {
        printf("\n\nOpcion incorrecta. Ingrese de nuevo: ");
        scanf("%c", &op);
    }
    opciones(op, pa, rutaAlum, rutaIdx);
}

void opciones(int op, t_arbol * pa, char * rutaAlum, char * rutaIdx)
{
    switch(op)
    {
        case '1': alta(pa, rutaAlum, rutaIdx);
            mostrarArchivoAlum(rutaAlum);
            mostrarIndice(rutaIdx);
            break;

        case '2': baja(pa, rutaAlum, rutaIdx);
            mostrarArchivoAlum(rutaAlum);
            mostrarIndice(rutaIdx);
            break;

        case '3': mostrarIndice(rutaIdx);
            break;

        case '4': mostrarArchivoAlum(rutaAlum);
            break;

    }
}
