#include "Reloj.h"
#include <iomanip>
#include <string.h>

char * duplicaCadena(const char *str)
{
    if (str && *str)
    {
        try
        {
            char *aux = new char[strlen(str)+1];
            strcpy(aux, str);
            return aux;
        }
        catch (bad_alloc &error)
        {
            cerr << "Error: " << error.what();
        }
    }
    return NULL;
}

Reloj :: Reloj(const int h, const int m, const int s, const char * formato)
{
    this->h = h;
    this->m = m;
    this->s = s;
    this->formato = duplicaCadena(formato);
    if (!this->formato && formato && *formato)
        cerr << "Sin memoria en el constructor";
}

Reloj :: ~Reloj()
{
    delete []formato;
}

void Reloj :: que_hora_es()
{
    cout << *this;
}

Reloj & Reloj :: escribe_en_12h()
{
    char formato[3];

    this->h >= 12 ? strcpy(formato, "PM") : strcpy(formato, "AM");

    if (this->h > 12)
        this->h -= 12;

    this->formato = duplicaCadena(formato);
    if (!this->formato && *formato)
        cerr << "Sin memoria en el metodo escribe en 12";

    return *this;
}

void Reloj :: escribe_en_24h()
{
    char formato[] = "L";

    if (this->h < 12 && !strcmp(this->formato, "PM"))
        this->h += 12;
    this->formato = duplicaCadena(formato);
    if (!this->formato && *formato)
        cerr << "Sin memoria en el metodo escribe en 12";
}

Reloj & Reloj :: adelantar_reloj(const int num)
{
    this->s += num;
    return *this;
}

ostream & operator << (ostream &salida, const Reloj &obj)
{
    salida << setw(2) << setfill('0') << obj.h << ":";
    salida << setw(2) << setfill('0') << obj.m << ":";
    salida << setw(2) << setfill('0') << obj.s << " " << obj.formato << endl;

    return salida;
}

