#ifndef RELOJ_H_INCLUDED
#define RELOJ_H_INCLUDED
#include <iostream>
#include "string.h"

using namespace std;

class Reloj
{
    private:
        int horas;
        int minutos;
        int segundos;
        char * formato;

    public:
      //Constructores
      Reloj(const int horas = 0, const int minutos = 0, const int segundos = 0, const char * formato = "AM");
      ~Reloj();

      //Metodos
      void que_hora_es();
      Reloj escribe_en_24h(); //No es necesario que devuelva una referencia a objeto, porque no lo pide el main
      Reloj & escribe_en_12h(); //En cambio este si es necesario que devuelva la referencia, porque lo usamos en un cout al final
      Reloj & adelantar_reloj(const int);

      friend ostream & operator << (ostream &salida, const Reloj &);

};



#endif // RELOJ_H_INCLUDED
