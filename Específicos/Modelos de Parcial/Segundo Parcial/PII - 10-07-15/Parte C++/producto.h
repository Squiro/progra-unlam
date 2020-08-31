#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class Bulto;

class Producto
{
    private:
        char desc[30];
        int alto;
        int ancho;
        int largo;

    public:
        Producto (const char * desc, const int alto = 0, const int ancho = 0, const int largo = 0);

        //Metodo Volumen
        int volumen();
        //Get
        char * getDesc();

        //Operador
        Bulto operator + (Producto &);



};

#endif // PRODUCTO_H_
