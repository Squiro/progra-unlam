#ifndef BULTO_H_
#define BULTO_H_

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Producto;

class Bulto
{
    private:
        char *desc;
        int volumen;

    public:
        Bulto(char *desc, const int volumen = 0);
        ~Bulto();

        //Operadores
        Bulto operator + (Producto &)const;

        //Get
        char * getDesc();
        int getVol();

        static char * concatenar(const char * bultDesc, const char * prodDesc);
        friend ostream & operator << (ostream &, const Bulto &);
};


#endif // BULTO_H_
