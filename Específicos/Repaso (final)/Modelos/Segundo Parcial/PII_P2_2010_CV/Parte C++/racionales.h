#ifndef RACIONALES_H_
#define RACIONALES_H_

#include <iostream>

using namespace std;

class Racional
{
    private:
        int numerador;
        int denominador;

    public:
        Racional(const int num = 0, const int denom = 1); //Operador parametrizado y por defecto

        //Operadores
        Racional operator * (const Racional &)const;
        Racional operator + (const Racional &)const;
        Racional operator + (const int num)const;
        friend Racional operator + (const int num, const Racional &);
        friend ostream & operator << (ostream &salida, const Racional &obj);
        bool operator != (const Racional &)const;

};

#endif // RACIONALES_H_
