#include "funciones.h"

int procesarPasajes()
{
    char codEvent;
    long id;
    t_pasaje pas;

    t_cola cola;
    crearCola(&cola);

    do
    {
        ingresarCodigo(&codEvent);

        switch (codEvent)
        {
        case 'S':
            ingresarID(&id);
            pas.nroPasaporte = id;
            if (!acolar(&cola, &pas))
                printf("No se pudo acolar. No hay memoria suficiente. Se sigue con el proceso.\n\n");
            break;
        case 'A':
            ingresarID(&id);
            if (!desacolar(&cola, &pas))
                printf("No se pudo desacolar. La cola se encuentra vacia.\n\n");
            else
            {
                pas.nroPasaje = id;
                printf("PASAPORTE: %ld PASAJE: %ld\n\n", pas.nroPasaporte, pas.nroPasaje);
            }
            break;
        }
    }
    while (codEvent != '*');

    generarArchivo(&cola);

    return SUCCESS;
}

void ingresarCodigo(char * codEvent)
{
    do
    {
        printf("\nIngrese cod. evento: ");
        fflush(stdin);
        scanf("%c", codEvent);
    }
    while (*codEvent != 'S' && *codEvent != 'A' && *codEvent != '*');
}

void ingresarID(long * id)
{
    printf("\nIngrese num. ID: ");
    scanf("%ld", id);
}

int generarArchivo(t_cola *c)
{
    FILE * arch;
    t_pasaje pas;

    arch = fopen("pasajes.bin", "wb");

    if (!arch)
        return ERROR_ARCH;

    while (!colaVacia(c))
    {
        desacolar(c, &pas);
        fwrite(&pas, sizeof(t_pasaje), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}
