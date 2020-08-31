#include "Hora.h"
#include <iomanip>

/*Hora :: Hora(const unsigned h, const unsigned m, const unsigned s):this->segRel(h*3600 + m*60 + s)
{}*/

Hora :: Hora(const unsigned h, const unsigned m, const unsigned s)
{
    this->segRel = h*3600 + m*60 + s;
}

//POST FIX, asigna y luego inrementa
Hora Hora :: operator -- (int)
{
    Hora aux(*this);
    this->segRel--;
    return aux;
}

//PRE FIX, incrementa y asigna
Hora & Hora :: operator -- ()
{
    this->segRel--;
    return *this;
}

Hora Hora :: operator + (const int num)const
{
    return Hora(0, 0, this->segRel + num);
}

Hora Hora :: operator - (const Hora &obj)const
{
    return this->segRel - obj.segRel;
}

ostream & operator << (ostream &salida, const Hora &obj)
{
    int hora = obj.segRel/3600;
    char formato[3] = "AM";

    if (hora >= 12)
    {
        hora -= 12;
        strcpy(formato, "PM");
    }

    salida << setw(2) << setfill('0') << hora << ":";
    salida << setw(2) << setfill('0') << (obj.segRel%3600)/60 << ":";
    salida << setw(2) << setfill('0') << (obj.segRel%60) << formato << endl;
    return salida;
}
