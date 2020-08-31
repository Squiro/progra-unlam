#include "funciones.h"

int almacenarCadenas(char * mat[20])
{
    char * prim, * seg;
    int count = 0, fin = 0;

    anularMatriz(mat);

    while (count <= 20 && !fin)
    {
        printf("Ingrese la primera cadena: ");
        prim = ingresarCadena();
        printf("Ingrese la segunda cadena: ");
        seg = ingresarCadena();


        if (mi_strcmp(prim, "final") && mi_strcmp(seg, "final"))
        {
            if (chequearMayor(prim, seg) >= 1)
            {
                mat[count++] = seg;
                mat[count++] = prim;
            }
            else
            {
                mat[count++] = prim;
                mat[count++] = seg;
            }
            printf("\n\n---- NUEVO PAR ----\n\n");
        }
        else
            fin = 1;
    }

    return 1;
}

void anularMatriz(char * mat[20])
{
    int i;

    for (i = 0; i < 20; i++)
        mat[i] = NULL;
}

char * ingresarCadena()
{
    char buffer[1024];
    char * input = malloc(sizeof(char)*80);
    fflush(stdin);
    scanf("%s", buffer);
    mi_strncpy(input, buffer, 80);

    return input;
}

char * mi_strncpy(char * str1, const char *str2, int limit)
{
    char *pIni = str1;
    int count = 0;

    while (*str2 && count <= limit)
    {
        *str1 = *str2;
        str1++;
        str2++;
        count++;
    }

    *str1 = '\0';

    return pIni;
}

/** Devuelve 1 (o mayor) si str1 es mayor que str2
    -1 (o menor) si str2 es mayor que str1 */
int chequearMayor(char * str1, char * str2)
{
    int len1 = mi_strlen(str1), len2 = mi_strlen(str2);

    if (len1 > len2)
        return 1;
    else if (len2 > len1)
        return -1;
    else
        return mi_strcmp(str1, str2);
}

int mi_strlen(const char *str)
{
    int len = 0;

    while (*str)
    {
        str++;
        len++;
    }

    return len;
}

//In C, the functions strcmp and memcmp perform a three-way comparison between strings and memory buffers, respectively.
//They return a negative number when the first argument is lexicographically smaller than the second, zero when the arguments are equal, and a positive number otherwise.
int mi_strcmp(const char *str1, const char *str2)
{
    do
    {
        if (*str1 != *str2)
            return *str1 > *str2 ? 1 : -1;
        str1++;
        str2++;
    } while (*str1 && *str2);

    return 0;
}

void mostrarCadenas(char * mat[20])
{
    int count = 0;

    while (mat[count] != NULL && count <= 20)
    {
        printf("\nPar:");
        printf("\n%s", mat[count++]);
        printf("\n%s", mat[count++]);
        printf("\n\n");
    }
}

void guardarEnLista(t_lista *pl, char * mat[20])
{
    int count = 0;

    while (mat[count] != NULL && count <= 20)
    {
        insertar(pl, &mat[count++], compararCadenas);
    }
}

int compararCadenas(const void *arg1, const void *arg2)
{
    char ** dato1 = (char **) arg1, ** dato2 = (char **) arg2;

    return chequearMayor(*dato1, *dato2);
}

int mostrarLista(t_lista *pl)
{
    char * str = NULL;

    while (!listaVacia(pl))
    {
        sacarPrimero(pl, &str);
        printf("Cadena: %s\n", str);
    }

    return SUCCESS;
}
