#include <stdio.h>
#include <stdlib.h>

int main()
{
    //FILE * pf fopen(const char * nombre, const char * modo);
    //Una vez abierto el archivo lo vamos a tratar con el nombre que le asignamos al fopen (pf), no con el nombre real del archivo.
    /*
        Modos de lectura/escritura/append:
            -r: abre un archivo para lectura. Si no existe, retorna error.
            -w: abre un archivo para escritura, sobreescribiendo todos sus datos. Si no existe, lo crea.
            -r+: abre tanto para lectura y escritura, pero no crea un archivo si existe, y no borra su contenido al abrirlo.
            -w+: abre tanto para lectura y escritura, pero borra el contenido del archivo y lo crea si no existe.
            -a: abre un archivo para adjuntarle cosas al final del mismo. Se crea el archivo si no existe.
            -a+: abre un archivo para leerlo y adjuntarle cosas al final del mismo. Se crea el archivo si no existe.
            //Tambien existen los modos rb, rt, que identifican al tipo de archivo (binario o texto).
            //Por defecto, si no tiene nada, los toma como texto.

    No se trabaja con el archivo directamente desde el almacenamiento. Porciones del archivo se cargan a memoria, y se trabaja en
    memoria directamente. Cada instrucción que le damos al archivo es una especie de ilusión, ya que modificamos el contenido
    de la memoria.

    Si el archivo fue modificado, y necesito leer algo nuevo, las modificaciones de memoria se guardan en el archivo real.
    Si no usamos mas el archivo, debemos cerrarlo para guardar las ultimas modificaciones. El fclose se asegura de cumplir con esto.
    Vacía el buffer del archivo de memoria en el almacenamiento.
    /!\ Siempre cerrar lo que se abre.
    fclose(pf);

    /!\ Chequeamos si el archivo se abre realmente. SIEMPRE hay que hacerlo, independientemente del modo de r/w/a usemos.
    if (!pf)
        exit(1);


    Operaciones solo para archivos binarios:
    size_t fwrite(const void * ptro, size_t tam, site_t nmem, FILE * stream);

    Podemos escribir varios registros al mismo tiempo enviando un vector en ptro y su tamaño en nmem.
    fwrite devuelve la cantidad de caracteres (bytes) grabados correctamente.
    Esto debería coincidir con nmem por el el tam de cada cosa que grabamos.

    size_t fread(   void *ptero, size_t tam, size_t nmem, FILE * stream);

    Notar como el registro cambia y no es constante. Eso es porque estamos leyendo algo, y modificando asimismo el registro.

    feof(FILE * stream)

    Recibe el puntero del archivo. feof toma el campo de la estructura FILE que indica si se llegó al fin del archivo.
    */

    FILE* pf;
    pf = fopen("archivoxd.bin", "wb+");

    if(!pf)
        exit(1);

    char lectura[50];

    /*fwrite(texto, sizeof(texto), 1, pf);*/

    fread(lectura, sizeof(lectura), 1, pf);
    /* Para procesar un archivo binario, lo primero tengo que hacer es leer y luego preguntar por feof.

    Esto es porque cuando utilizamos fopen, automaticamente se flaggea al archivo como NO vacio, por mas que este lo esté.
    Si abrimos un archivo y ni bien lo abrimos llegamos al end of file... efectivamente esta vacio.
    */

    printf("Flag que muestra si esta escrito o no: %d \n", pf->_flag);
    if (feof(pf))
        printf("Llego al fin del arch/no hay info");

    fclose(pf);

    /*
        rewind(pf) rebobina el pf
    */

    return 0;
}

