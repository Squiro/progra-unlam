#include "funciones.h"

/** Ejercicio 1*/

int contarCaracteres(char *cadena)
{
    if(!(*cadena))
        return 0;
    return (contarCaracteres(cadena+1) + 1);
}

char * invertirCadena(char *cadena)
{
    int len = contarCaracteres(cadena), i;
    char * pFin = cadena+len-1, * pIni = cadena, aux;

    for (i = 0; i < len/2; i++, cadena++, pFin--)
    {
        aux = *cadena;
        *cadena = *pFin;
        *pFin = aux;
    }

    return pIni;
}

void triangularInferior(int mat[][TAM], int tam)
{
    int i, j;

    for (i = 0; i < tam; i++)
        for (j = 0; j < i; j++)
            printf("%d", mat[i][j]);

}

/** Ejercicio 2*/

/** Parte A */

int generarLote()
{
    FILE * arch;
    int i;
    t_moto regs[3] = { { "1", "Yamaha", "A", 1992, 100 },
        { "2", "Jawa", "B", 1999, 220 },
        { "3", "Suzuki", "C", 2001, 10000 }
    };

    arch = fopen("motos.bin", "wb");

    if (!arch)
        return ERROR_ABRIR;

    for(i = 0; i < 3; i++)
        fwrite(&regs[i], sizeof(t_moto), 1, arch);

    fclose(arch);

    return 0;
}

int incrementarPrecio()
{
    int anio;
    printf("Ingrese el anio para incrementar precio: ");
    scanf("%d", &anio);

    actualizarRegistros(anio);

    return 0;
}

int actualizarRegistros(int anio)
{
    FILE * arch;
    t_moto reg;

    arch = fopen("motos.bin", "rb+");

    if (!arch)
        return ERROR_ABRIR;

    fread(&reg, sizeof(t_moto), 1, arch);

    while (!feof(arch))
    {
        if (reg.anio == anio)
        {
            reg.precio = (reg.precio + (reg.precio * 25)/100);
            fseek(arch, -sizeof(t_moto), SEEK_CUR);
            //fseek(arch, 0, SEEK_CUR);
            fwrite(&reg, sizeof(t_moto), 1, arch);
            fseek(arch, sizeof(t_moto), SEEK_CUR);
        }
        fread(&reg, sizeof(t_moto), 1, arch);
    }

    fclose(arch);

    return 0;
}

int mostrarArchivo()
{
    FILE * arch;
    t_moto reg;

    arch = fopen("motos.bin", "rb");

    if (!arch)
        return ERROR_ABRIR;

    fread(&reg, sizeof(t_moto), 1, arch);

    printf("Mostrando archivo actualizado... \n\n");
    while (!feof(arch))
    {
        printf("\n\nCOD: %s", reg.cod);
        printf("\nMarca: %s", reg.marca);
        printf("\nModelo: %s", reg.modelo);
        printf("\nAnio: %d", reg.anio);
        printf("\nPrecio: %0.3lf", reg.precio);
        fread(&reg, sizeof(t_moto), 1, arch);
    }

    fclose(arch);

    return 0;
}

/** Parte B */

void crearLista(t_lista * pl)
{
    *pl = NULL;
}

int insertarPrincipio(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->sig = *pl;
    nuevo->dato = *d;
    *pl = nuevo;

    return SUCCESS;
}

int insertarFinal(t_lista *pl, const t_dato *d)
{
    t_nodo * nuevo = (t_nodo *) malloc(sizeof(t_nodo));

    if (!nuevo)
        return SIN_MEM;

    nuevo->dato = *d;
    nuevo->sig = NULL;

    while (*pl)
        pl = &(*pl)->sig;

    *pl = nuevo;

    return SUCCESS;
}

int ordenarLista(t_lista *pl, t_cmp comparar)
{
    t_lista * menor;
    t_nodo * aux, * menSig;

    while (*pl)
    {
        menor = hallarMenor(pl, comparar);

        if (menor != pl)
        {
            aux = *pl;
            *pl = *menor;
            menSig = (*menor)->sig;
            (aux->sig == *menor) ? ((*pl)->sig = aux) : ((*pl)->sig = aux->sig);
            *menor = aux;
            (*menor)->sig = menSig;
        }

        pl = &(*pl)->sig;
    }

    return SUCCESS;
}

void * hallarMenor(t_lista *pl, t_cmp comparar)
{
    t_lista * menor = pl;

    while (*pl)
    {
        if (comparar(&(*pl)->dato, &(*menor)->dato) < 0)
            menor = pl;

        pl = &(*pl)->sig;
    }

    return menor;
}

int compararMotos(const void * arg1, const void * arg2)
{
    t_dato * dato1 = (t_dato *)arg1, *dato2 = (t_dato *)arg2;

    int cmp = mi_strcmp(dato1->marca, dato2->marca);

    if (!cmp)
        return mi_strcmp(dato1->modelo, dato2->modelo);
    else
        return cmp;
}

int mi_strcmp(const char * str1, const char * str2)
{
    do
    {
        if (*str1 != *str2)
            return (*str1 > *str2) ? 1 : -1;
        str1++;
        str2++;
    } while (*str1 && *str2 && (*str1 == *str2));

    return 0;
}

void mostrarLista(t_lista *pl)
{
    printf("\n\nMostrando ordenada... \n");

    while (*pl)
    {
        printf("\n\nMarca: %s", (*pl)->dato.marca);
        printf("\nModelo: %s", (*pl)->dato.modelo);
        pl = &(*pl)->sig;
    }
}

int guardarEnLista(t_lista *pl)
{
    FILE * arch;
    t_dato reg;

    arch = fopen("motos.bin", "rb");

    if (!arch)
        return ERROR_ABRIR;

    fread(&reg, sizeof(t_dato), 1, arch);

    while (!feof(arch))
    {
        insertarFinal(pl, &reg);
        fread(&reg, sizeof(t_dato), 1, arch);
    }

    fclose(arch);

    return SUCCESS;
}

/** Parte C */

int quitarMarca(t_lista *pl)
{
    t_nodo * aux;
    char marca[10];

    printf("\n\nPor favor ingrese la marca a quitar: ");
    scanf("%s", marca);

    while (*pl)
    {
        if (!mi_strcmp((*pl)->dato.marca, marca))
        {
            aux = *pl;
            *pl = aux->sig;
            free(aux);
        }
        else
            pl = &(*pl)->sig;
    }

    return 0;
}

/** Parte D */

void mostrarMayoresA(t_lista *pl, double precio)
{
    printf("\n\nMostrando motos con precio mayor a %0.3lf... \n", precio);

    while (*pl)
    {
        if ((*pl)->dato.precio > precio)
        {
            printf("\n\nMarca: %s", (*pl)->dato.marca);
            printf("\nModelo: %s", (*pl)->dato.modelo);
            printf("\nPrecio: %0.3lf", (*pl)->dato.precio);
        }

        pl = &(*pl)->sig;
    }
}
