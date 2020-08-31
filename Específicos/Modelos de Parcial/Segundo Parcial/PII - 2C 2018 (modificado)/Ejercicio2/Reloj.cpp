#include "Reloj.h"
#include <iomanip>

char * duplicaCadena(const char *str)
{
    if (str && *str)
    {
        try
        {
            char * aux = new char[strlen(str)+1];
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

Reloj :: Reloj(const int horas, const int minutos, const int segundos, const char * formato)
{
    this->horas = horas;
    this->minutos = minutos;
    this->segundos = segundos;
    this->formato = duplicaCadena(formato);
    if (!this->formato && formato && *formato)
        cerr << "Sin memoria en el constructor parametrizado";
}

Reloj :: ~Reloj()
{
    delete []formato;
}

void Reloj :: que_hora_es()
{
    cout << "La hora actual es: " << this->horas << ":" << this->minutos << ":" << this->segundos << " " << this->formato << endl;

}

Reloj & Reloj :: escribe_en_12h()
{
    char formato[3];

    this->horas >= 12 ? strcpy(formato, "PM") : strcpy(formato, "AM");

    if (this->horas > 12)
        this->horas -= 12;

    this->formato = duplicaCadena(formato);
    if (!this->formato && *formato)
        cerr << "Sin memoria en el constructor parametrizado";

    return *this;
}

Reloj Reloj :: escribe_en_24h()
{
    char formato[] = "L";

    if (this->horas < 12 && strcmp(this->formato, "PM") == 0)
      this->horas += 12;

    this->formato = duplicaCadena(formato);
    if (!this->formato && *formato)
        cerr << "Sin memoria en el constructor parametrizado";

    return *this;
}

Reloj & Reloj :: adelantar_reloj(const int)
{
    this->segundos+=10;
    return *this;
}

ostream & operator << (ostream &salida, const Reloj &rel)
{
    salida << "La hora actual es: " << rel.horas << ":" << rel.minutos << ":" << rel.segundos << " " << rel.formato << endl;
    return salida;
}

