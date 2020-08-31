#include "funciones.h"

int eliminarDeCola(t_arbol *pa, t_lista *pl, char * ruta)
{
    FILE * arch;

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ARCH;

    recorrer_inorden_eliminar(pa, pl, arch);

    fclose(arch);

    return SUCCESS;
}

void recorrer_inorden_eliminar(t_arbol *pa, t_lista *pl, FILE * arch)
{
    if (*pa)
    {
        recorrer_inorden_eliminar(&(*pa)->izq, pl, arch);
        if (eliminarNodo(pl, &(*pa)->dato.nroCliente, compararClientes))
        {
            escribirEnArchivo(arch, &(*pa)->dato);
        }
        recorrer_inorden_eliminar(&(*pa)->der, pl, arch);
    }
}

void escribirEnArchivo(FILE * arch, t_indice * idx)
{
    t_cliente cli;

    cli.nroCliente = idx->nroCliente;
    cli.email = idx->email;
    cli.nroSorteo = ftell(arch)/sizeof(t_cliente);

    fwrite(&cli, sizeof(t_cliente), 1, arch);
}

int mostrarArchivo(char * ruta)
{
    t_cliente cli;
    FILE * arch;

    arch = fopen(ruta, "rb");

    if (!arch)
        return ERROR_ARCH;

    fread(&cli, sizeof(t_cliente), 1, arch);

    while (!feof(arch))
    {
        printf("NroCli: %ld", cli.nroCliente);
        printf("\nEmail: %s", cli.email);
        printf("\nNroSorteo: %d", cli.nroSorteo);
        printf("\n\n");
        fread(&cli, sizeof(t_cliente), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

void ingresarCliente(t_indice * idx)
{
    printf("\nIngrese numero de cliente: ");
    scanf("%ld", &idx->nroCliente);
    printf("\nIngrese el email: ");
    idx->email = ingresarCadena();

}

char * ingresarCadena()
{
    char buffer[1024];
    int size = 256;
    char * input = malloc(sizeof(char)*size);
    fflush(stdin);
    scanf("%s", buffer);
    mi_strncpy(input, buffer, 256);

    return input;
}

char * mi_strncpy(char *str, char * buffer, unsigned int limit)
{
    char *pIni = str;
    unsigned int count = 0;

    while (*buffer && count <= limit)
    {
        *str++ = *buffer++;
        count++;
    }

    *str = '\0';

    return pIni;
}
