#include "funciones.h"

int generarLote(char * ruta)
{
    FILE * arch;
    int i;
    t_cuenta cts[3] =
    {
        { 1, "Asd", {1, 2, 3}, { 2, 2, 2 }, 20, 'A' },
        { 2, "Dsa", {3, 3, 3}, { 4, 4, 4 }, 0, 'A' },
        { 3, "Sad", {5, 5, 5}, { 6, 6, 6 }, 0, 'A' },
    };

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ARCH;

    for (i = 0; i < 3; i++)
        fwrite(&cts[i], sizeof(t_cuenta), 1, arch);

    fclose(arch);

    return SUCCESS;
}

int darBajaInactivas(t_arbol *pa, char * ruta)
{
    t_cuenta cuenta;
    t_fecha fechaParam;
    t_etiqueta etiqueta;
    FILE * arch;

    ingresarFecha(&fechaParam);

    arch = fopen(ruta, "rb+");

    if (!arch)
        return ERROR_ARCH;

    fread(&cuenta, sizeof(t_cuenta), 1, arch);

    while (!feof(arch))
    {
        if (cuenta.saldo == 0 && cuenta.estado != 'B' && compararFechas(&fechaParam, &cuenta.fch_ult_mov) > 0)
        {
            cuenta.estado = 'B';
            modificarRegistro(arch, &cuenta);
            etiqueta.nroCta = cuenta.nroCta;
            etiqueta.nroReg = ftell(arch)/sizeof(t_cuenta);
            insertar(pa, &etiqueta, compararCuentas);
        }
        fread(&cuenta, sizeof(t_cuenta), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

void modificarRegistro(FILE * arch, t_cuenta *cta)
{
    fseek(arch, -1*sizeof(t_cuenta), SEEK_CUR);
    fseek(arch, 0, SEEK_CUR);
    fwrite(cta, sizeof(t_cuenta), 1, arch);
    fseek(arch, 0, SEEK_CUR);
}

int generarArchivo(t_arbol *pa, char * ruta)
{
    FILE * arch;

    arch = fopen(ruta, "wb");

    if (!arch)
        return ERROR_ARCH;

    guardarEnOrden(pa, arch);

    fclose(arch);

    return SUCCESS;
}

int mostrarArchivo(char * ruta)
{
    FILE * arch;
    t_etiqueta cta;

    arch = fopen(ruta, "rb");

    if (!arch)
        return ERROR_ARCH;

    fread(&cta, sizeof(t_etiqueta), 1, arch);

    while (!feof(arch))
    {
        printf("NroCuenta: %ld", cta.nroCta);
        printf("\nNroReg: %ld", cta.nroReg);
        printf("\n\n");
        fread(&cta, sizeof(t_etiqueta), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}
