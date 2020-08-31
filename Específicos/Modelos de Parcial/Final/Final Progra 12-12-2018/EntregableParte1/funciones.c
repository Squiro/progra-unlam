#include "funciones.h"

/** desarrolle acá las funciones que resuelven el problema planteado sin _ 2*/

/** Lista doble */

void crearListaD(tListaD *p)
{
    *p = NULL;
}

int insertarEnOrdenOAcumular(tListaD *p, const tInfo *d, int (*comp)(const tInfo *d1, const tInfo *d2),
                             void (*acum)(tInfo *d1, const tInfo *d2))
{

    tNodoD * actual = *p, * antAux, * sigAux, * nuevo;
    int cmp;

    if (actual)
    {
        while (actual->sig && comp(&actual->info, d) < 0)
            actual = actual->sig;
        while (actual->ant && comp(&actual->info, d) > 0)
            actual = actual->ant;

        cmp = comp(&actual->info, d);

        if (cmp < 0)
        {
            antAux = actual;
            sigAux = actual->sig;
        }
        else if (cmp > 0)
        {
            antAux = actual->ant;
            sigAux = actual;
        }
        else
        {
            acum(&actual->info, d);
            return CLA_DUP;
        }
    }
    else
    {
        sigAux = NULL;
        antAux = NULL;
    }

    nuevo = (tNodoD *) malloc(sizeof(tNodoD));

    if (!nuevo)
        return SIN_MEM;

    nuevo->info = *d;
    nuevo->ant = antAux;
    nuevo->sig = sigAux;

    if (antAux)
        antAux->sig = nuevo;
    if (sigAux)
        sigAux->ant = nuevo;

    *p = nuevo;

    return TODO_BIEN;
}

int compXClave(const tInfo *d1, const tInfo *d2)
{
    char * str1 = toLower(d1->palabra), *str2 = toLower(d2->palabra);
    int cmp = strcmp(str1, str2);
    free(str1);
    free(str2);
    return cmp;
}

void acumular(tInfo *d1, const tInfo *d2)
{
    d1->veces++;
}

void mostrarRepetidas(const tListaD *p)
{
    tNodoD * actual = *p;

    while (actual->ant)
        actual = actual->ant;

    while (actual)
    {
        if (actual->info.veces >= 3)
            printf("Palabra: %s | Veces: %d\n", actual->info.palabra, actual->info.veces);
        actual = actual->sig;
    }
}

/** Decodificacion */

int leerDecodificarYContabilizar(FILE *fpEnt, FILE *fpSal, tListaD *lista)
{
    char linea[TAM_LINEA];

    fgets(linea, TAM_LINEA, fpEnt);

    while (!feof(fpEnt))
    {
        decodificarLinea(linea, lista);
        fprintf(fpSal, linea);
        fgets(linea, TAM_LINEA, fpEnt);
    }

    return TODO_BIEN;
}

/** decodifica las palabras de una línea de texto, las inserta en la lista una por una y almacena el archivo decodificado */

void decodificarLinea(char *linea, tListaD *lista)
{
    tInfo info;
    int fin;
    char *prox = proxPal(linea),  * lineaNueva = malloc(strlen(linea)), *pIni = linea;

    if (!lineaNueva)
    {
        fprintf(stderr, "Sin memoria para cadena");
        exit(1);
    }

    *lineaNueva = '\0';

    while (*prox)
    {
        if ((fin = strlen(prox)) % 2 == 0)
        {
            invert(prox, (prox+fin)-1);
            decodi(prox, (prox+fin)-1);
        }
        else
        {
            decodi(prox, (prox+fin)-1);
            invert(prox, (prox+fin)-1);
        }

        if (isalpha(*prox) || isextended(*prox))
        {
            //Hago un realloc del info.palabra para asegurarme de que tenga espacio para la palabra
            realloc(info.palabra, strlen(prox));
            //Copio la palabra decodificada y todo
            strcpy(info.palabra, prox);
            //Seteo info.veces en 1
            info.veces = 1;
            //La inserto en la lista
            insertarEnOrdenOAcumular(lista, &info, compXClave, acumular);
        }

        //Hago un srtcat de la palabra decodif en nueva linea
        strcat(lineaNueva, prox);
        //Me muevo en la linea original la cantidad de caracteres de prox
        linea += strlen(prox); //strlen()-1?
        //Busco una nueva palabra desde la posicion en que nos deja
        prox = proxPal(linea);
    }

    strcpy(pIni, lineaNueva);
    free(lineaNueva);
}

/** Busca la proxima palabra en una linea de texto...
*/
char *proxPal(const char *s)
{
    //strcpy && malloc
    int size = TAM_PAL + 1, count = 0;
    char *prox = malloc(sizeof(char)*size), * pIni = prox;

    if (!prox)
    {
        fprintf(stderr, "Sin memoria para cadena");
        exit(1);
    }

    if (!isalpha(*s) && !isextended(*s))
    {
        *prox = *s;
        prox++;
    }

    while (*s && (isalpha(*s) || isextended(*s)))
    {
        if (count >= size-1)
        {
            size *= 2;
            prox = realloc(prox, size);
            if (!prox)
            {
                fprintf(stderr, "Sin memoria para cadena");
                exit(1);
            }
        }
        *prox++ = *s++;
        count++;
    }
    *prox = '\0';

    return pIni;
}

/** busca la posición siguiente al último carácter de una palabra   */

char *finPal(const char *s)
{
    while (*s && isalnum(*s))
        s++;

    return (char *) s;
}

/** Las palabras se codificaron reemplazando al primer caracter por el siguiente,
al segundo por el sig del sig, y asi sucesivamente...

Para decodificar tengo que hacer el proceso inverso, al primero lo reemplazo por su ant, al segundo por el ant del ant

Anterior de A -> z
Anterior de a -> Z */
void decodi(char *ini, const char *fin)
{
    int nuevoChar, cont = -1;

    while (ini <= fin)
    {
        //Chequeo si es un caracter del ascii no extendido (o sea, sin tildes ni nada raro)
        if (isalpha(*ini))
        {
            nuevoChar = (*ini)+(cont);

            if (nuevoChar < 'A')
                *ini = ('z' - ('A'-nuevoChar))+1;
            else if (nuevoChar > 'Z' && nuevoChar < 'a')
                *ini = 'Z';
            else
                *ini = nuevoChar;
            cont--;
        }
        ini++;
    }
}

void invert(char *ini, char *fin)
{
    char aux;

    while(ini < fin)
    {
        aux = *ini;
        *ini = *fin;
        *fin = aux;
        ini++;
        fin--;
    }
}

/** Funciones de ayuda */

int isalpha(int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
}

int isdigit(int c)
{
    return (c >= '0' || c <= '9' ? 1 : 0);
}

int isextended(int c)
{
    return ((c >= 'ü' && c <= 'Ü') || (c >= 'á' && c <= 'Ñ') ? 1 : 0);
}

//no es necesaria
int isalnum(int c)
{
    return (isalpha(c) || isdigit(c) || isextended(c));
}

char * toLower(const char *str)
{
    char *cad = malloc(strlen(str)), *pIni = cad;

    while (*str)
    {
        if (*str < 'A' || *str > 'Z')
            *cad = *str;
        else
            *cad = (*str)+32;
        cad++;
        str++;
    }

    *cad = '\0';

    return pIni;
}
