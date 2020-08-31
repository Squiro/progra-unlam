
#ifndef FUNCIONES_H__
#define FUNCIONES_H__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "main.h"


#define     CONMSJ      1
#define     TAM_PAL     15

#define     CLA_DUP     2
#define     TODO_BIEN   1
#define     SIN_MEM     0

#define     TAM_LINEA   500

#define ES_PAR(X) (X)==2*(X)


typedef struct
{
    char palabra[TAM_PAL + 1];
    int veces;
} tInfo;

typedef struct sNodoD
{
    tInfo   info;
    struct sNodoD *sig;
    struct sNodoD *ant;
} tNodoD, *tListaD;


void crearArchivo(const char *nomArch);
void mostrarArchivo(const char *nomArch);
int abrirArchivo(FILE **fp, const char *arch, const char *modo, int conSin);



/** -------------------------x---o---x------------------------------ */
/** FUNCIONES A DESARROLLAR  -, Sus versiones deberían ser sin   _2  */
/** -------------------------x---o---x------------------------------ */

/** se encarga de leer, decodificar, poner las palabras en la lista y generar
 *      el archivo de salida valiéndose del uso de otras funciones
 */
int leerDecodificarYContabilizar_2(FILE *fpEnt, FILE *fpSal, tListaD *lista);

/** esta función crea la lista como lista vacía
 */
void crearListaD_2(tListaD *p);


/** esta función inserta en orden en la lista, pero si encuentra la misma clave,
 *      acumula incrementando en uno la cantidad de veces que está esa palabra
 *      en el texto.
 *  siempre deja la lista con la dirección del último insertado.
 *  devuelve un indicador de fracaso (SIN_MEM) o éxito (CLA_DUP o TODO_BIEM)
 */
int insertarEnOrdenOAcumular_2(tListaD *p, const tInfo *d,
                               int (*comp)(const tInfo *d1, const tInfo *d2),
                               void (*acum)(tInfo *d1, const tInfo *d2));


/** no obligatorio pero conveniente resolverla para la función que inserta en
 *      forma ordenada o acumula en la lista doblemente enlazada
 */
int compXClave_2(const tInfo *d1, const tInfo *d2);

/** no obligatorio pero conveniente resolverla para la función que inserta en
 *      forma ordenada o acumula en la lista doblemente enlazada
 */
void acumular_2(tInfo *d1, const tInfo *d2);


/** se encarga de recuperar la información del primero de la lista,
 *      devolviendo un indicador de éxito o fracaso
 */
int sacarPrimero_2(tListaD *p, tInfo *d);


/** se recomienda una función que decodifica las palabras de una línea de texto
 *      las inserta en la lista una por una y almacena el archivo decodificado
 */
void decodificarLinea_2(char *linea, tListaD *lista);
/** se recomienda esta función que busca la próxima palabra en una línea de
 *      texto

 */
char *proxPal_2(const char *s);

/** se recomienda esta función que busca la posición siguiente al último
 *      carácter de una palabra
 */
char *finPal_2(const char *s);

/** se recomienda esta función para decodificar una palabra
 */
void decodi_2(char *ini, const char *fin);

/** se recomienda esta función para invertir una palabra
 */
void invert_2(char *ini, char *fin);

/** declare acá las funciones que resuelven el problema planteado sin _2    */

/** Lista doble */

void crearListaD(tListaD *p);
int leerDecodificarYContabilizar(FILE *fpEnt, FILE *fpSal, tListaD *lista);
int insertarEnOrdenOAcumular(tListaD *p, const tInfo *d,
                               int (*comp)(const tInfo *d1, const tInfo *d2),
                               void (*acum)(tInfo *d1, const tInfo *d2));

int compXClave(const tInfo *d1, const tInfo *d2);
void acumular(tInfo *d1, const tInfo *d2);
void recorrerLista(const tListaD *p);
void mostrarRepetidas(const tListaD *p);

/** Decodificacion */

void decodificarLinea(char *linea, tListaD *lista);
char *proxPal(const char *s);
char *finPal(const char *s);
void decodi(char *ini, const char *fin);
void invert(char *ini, char *fin);

/** Funciones de ayuda */

int isalnum(int c);
int isalpha(int c);
int isdigit(int c);
int isextended(int c);
char * toLower(const char *str);

#endif
