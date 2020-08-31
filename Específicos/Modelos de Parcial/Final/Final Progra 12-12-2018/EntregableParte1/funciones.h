
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
/** FUNCIONES A DESARROLLAR  -, Sus versiones deber�an ser sin   _2  */
/** -------------------------x---o---x------------------------------ */

/** se encarga de leer, decodificar, poner las palabras en la lista y generar
 *      el archivo de salida vali�ndose del uso de otras funciones
 */
int leerDecodificarYContabilizar_2(FILE *fpEnt, FILE *fpSal, tListaD *lista);

/** esta funci�n crea la lista como lista vac�a
 */
void crearListaD_2(tListaD *p);


/** esta funci�n inserta en orden en la lista, pero si encuentra la misma clave,
 *      acumula incrementando en uno la cantidad de veces que est� esa palabra
 *      en el texto.
 *  siempre deja la lista con la direcci�n del �ltimo insertado.
 *  devuelve un indicador de fracaso (SIN_MEM) o �xito (CLA_DUP o TODO_BIEM)
 */
int insertarEnOrdenOAcumular_2(tListaD *p, const tInfo *d,
                               int (*comp)(const tInfo *d1, const tInfo *d2),
                               void (*acum)(tInfo *d1, const tInfo *d2));


/** no obligatorio pero conveniente resolverla para la funci�n que inserta en
 *      forma ordenada o acumula en la lista doblemente enlazada
 */
int compXClave_2(const tInfo *d1, const tInfo *d2);

/** no obligatorio pero conveniente resolverla para la funci�n que inserta en
 *      forma ordenada o acumula en la lista doblemente enlazada
 */
void acumular_2(tInfo *d1, const tInfo *d2);


/** se encarga de recuperar la informaci�n del primero de la lista,
 *      devolviendo un indicador de �xito o fracaso
 */
int sacarPrimero_2(tListaD *p, tInfo *d);


/** se recomienda una funci�n que decodifica las palabras de una l�nea de texto
 *      las inserta en la lista una por una y almacena el archivo decodificado
 */
void decodificarLinea_2(char *linea, tListaD *lista);
/** se recomienda esta funci�n que busca la pr�xima palabra en una l�nea de
 *      texto

 */
char *proxPal_2(const char *s);

/** se recomienda esta funci�n que busca la posici�n siguiente al �ltimo
 *      car�cter de una palabra
 */
char *finPal_2(const char *s);

/** se recomienda esta funci�n para decodificar una palabra
 */
void decodi_2(char *ini, const char *fin);

/** se recomienda esta funci�n para invertir una palabra
 */
void invert_2(char *ini, char *fin);

/** declare ac� las funciones que resuelven el problema planteado sin _2    */

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
