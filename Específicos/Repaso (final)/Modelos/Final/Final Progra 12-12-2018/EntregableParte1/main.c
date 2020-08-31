#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"


int main()
{
    FILE       *fpEnt,
               *fpSal;
    tListaD     lista;

    crearArchivo(ARCH_ENT);

    if(!abrirArchivo(&fpEnt, ARCH_ENT, "rt", CONMSJ))
        return 1;
    if(!abrirArchivo(&fpSal, ARCH_SAL, "wt", CONMSJ))
    {
        fclose(fpEnt);
        return 2;
    }

    //crearListaD_2(&lista);
    crearListaD(&lista);

    //leerDecodificarYContabilizar_2(fpEnt, fpSal, &lista);
    leerDecodificarYContabilizar(fpEnt, fpSal, &lista);

    fclose(fpEnt);
    fclose(fpSal);

    mostrarArchivo(ARCH_SAL);

    mostrarRepetidas(&lista);

    return 0;
}

