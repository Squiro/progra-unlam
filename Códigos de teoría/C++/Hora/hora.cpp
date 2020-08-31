#include "hora.h"
#include <iomanip> //para usar setfill y setw

/** INICIALIZADOR (menos lineas, el mismo laburo)
Hora :: Hora(const unsigned h, const unsigned m, const unsigned s):this->segRel(h*3600 + m*60 + s)
{}
*/

Hora :: Hora(const unsigned h, const unsigned m, const unsigned s)
{
    //Pasamos todo a segundos
    this->segRel = h*3600 + m*60 + s;
}

Hora :: Hora(const Hora &obj)
{
    this->segRel = obj.segRel;
}

void Hora :: mostrar()
{
    cout << "Hora: " << this->segRel/3600 << " Min: " << (this->segRel%3600)/60 << " Seg: " << (this->segRel%60) << endl;
}

//Asignamos valores a los formatos
const char Hora :: formatoAmPm = 'A';
const char Hora :: formatoLibre = 'L';
const char Hora :: formato24 = 'D';
//Seteamos inicialmente el formato en uno de los tres
char Hora::formatoHora = Hora::formatoLibre;

//No hace falta escribir la palabra static
void Hora :: setFormato(char formato)
{
    if (formato == Hora::formatoAmPm || formato == Hora::formato24 || formato == Hora::formatoLibre)
    {
        Hora::formatoHora = formato;
    }
}

Hora Hora :: operator + (const Hora &obj)const
{
    return Hora(0, 0, this->segRel + obj.segRel);
    /*Hora aux(*this); //Usamos por copia
    aux.segRel += obj.segRel;
    return aux;*/
}

Hora & Hora :: operator += (const unsigned s)
{
    this->segRel += s;
    return *this;
}

Hora & Hora :: operator = (const Hora &obj)
{
    this->segRel = obj.segRel;
    return *this;
}

Hora Hora :: operator + (const unsigned num)const
{
    return Hora(0, 0, this->segRel + num);
}

//Recordar NO adueñarse del operador. No puedo poner Hora Hora :: operator +, porque no es de mi clase.
Hora operator + (const unsigned num, const Hora &obj)
{
    return Hora(0, 0, obj.segRel + num);
}

bool Hora :: operator > (const Hora &obj)const
{
    return this->segRel > obj.segRel;
}

bool Hora :: operator < (const Hora &obj)const
{
    return this->segRel < obj.segRel;
}

//Pos fix, primero asigna, desp incrementa
Hora Hora :: operator ++ (int)
{
    Hora aux(*this);
    this->segRel++;
    return aux;
}

//Pre fix, primero incrementa, desp asigna
Hora & Hora :: operator ++ ()
{
    this->segRel++;
    return *this;
}

ostream & operator << (ostream &salida, const Hora &obj)
{
    //setw cant de caracteres a mostrar
    //setfill rellena los espacios que queden vacios
    salida << setw(2) << setfill('0') << obj.segRel/3600 << ":";
    salida << setw(2) << setfill('0') << (obj.segRel%3600)/60 << ":";
    salida << setw(2) << setfill('0') << (obj.segRel%60) << Hora::formatoHora << endl;
    return salida;
}

istream & operator >> (istream &entrada, Hora &obj)
{
    unsigned h, m, s;

    cout << "Ingrese la hora: " << endl;
    entrada >> h;
    cout << "Ingrese los min: " << endl;
    entrada >> m;
    cout << "Ingrese los seg: " << endl;
    entrada >> s;

    obj.segRel = h*3600+m*60+s;

    return entrada;
}
