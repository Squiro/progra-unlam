#include "racionales.h"

double obtenerReal()

Racional :: Racional(const int num, const int denom)
{
    this->numerador = num;
    this->denominador = denom;
}

Racional Racional :: operator + (const Racional &obj)const
{
    return Racional (this->numerador*obj.denominador + this->denominador*obj.numerador, this->denominador*obj.denominador);
}

Racional Racional :: operator * (const Racional &obj)const
{
    return Racional(this->numerador*obj.numerador, this->denominador*obj.denominador);
}

Racional Racional :: operator + (const int num)const
{
    return Racional(this->numerador + num*this->denominador, this->denominador);
}

Racional operator + (const int num, const Racional &obj)
{
    return Racional(obj.numerador + num*obj.denominador, obj.denominador);
}

ostream & operator << (ostream &salida, const Racional &obj)
{
    salida << obj.numerador << "/" << obj.denominador << endl;
    return salida;
}

bool Racional :: operator != (const Racional &obj)const
{
    return this->numerador != obj.numerador || this->denominador != obj.denominador;
}
