#ifndef CAJA_H
#define CAJA_H

#include <iostream>

using namespace std;

class Caja
{
    private:
        int largo,
            ancho,
            alto;

/// complete la declaración de las funciones miembro de la  class
    public:
        //Constructores
        Caja();
        Caja(const int arista);
        Caja(const int ancho, const int largo);
        Caja(const int acho, const int largo, const int alto); //Param por defec


        //Operadores
        Caja operator ++ (int);
        Caja & operator --();
        friend Caja operator * (const int num, const Caja &obj);
        friend ostream & operator << (ostream &salida, const Caja &obj);
};

#endif //CAJA_H_
