
#include "caja.h"


/// desarrolle acá las funciones miembro de la  class

Caja :: Caja()
{
    this->largo = this->ancho = this->alto = 1;
}

Caja :: Caja(const int arista):largo(arista),ancho(arista),alto(arista)
{
}

Caja :: Caja(const int ancho, const int largo)
{
    this->ancho = ancho;
    this->largo = largo;
    this->alto = largo;
}

Caja :: Caja(const int ancho, const int largo, const int alto)
{
    this->ancho = ancho;
    this->largo = largo;
    this->alto = alto;
}

Caja operator * (const int num, const Caja &obj)
{
    return Caja(num*obj.ancho, num*obj.largo, num*obj.alto);
}

Caja Caja :: operator ++ (int)
{
    Caja aux(*this);
    this->largo++;
    this->ancho++;
    return aux;
}

Caja & Caja :: operator --()
{
    this->largo--;
    this->ancho--;
    this->alto--;
    return *this;
}

ostream & operator << (ostream &salida, const Caja &obj)
{
    salida << obj.ancho << "x" << obj.largo << "x" << obj.alto;
    return salida;
}

