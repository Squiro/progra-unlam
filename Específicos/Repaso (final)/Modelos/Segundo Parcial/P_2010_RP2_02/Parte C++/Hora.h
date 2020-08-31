#ifndef HORA_H_
#define HORA_H_

#include <iostream>
#include <string.h>

using namespace std;

class Hora
{
    private:
        int segRel;

    public:
        Hora(const unsigned h = 0, const unsigned m = 0, const unsigned s = 0);

        //Operadores
        Hora operator -- (int);
        Hora & operator -- ();
        Hora operator + (const int num)const;
        Hora operator - (const Hora &)const;
        friend ostream & operator << (ostream &salida, const Hora &obj);
};

#endif // HORA_H_
