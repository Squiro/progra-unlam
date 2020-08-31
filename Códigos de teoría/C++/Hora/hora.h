#ifndef HORA_H_
#define HORA_H_

#include <iostream>

using namespace std;

class Hora
{
    private:
        unsigned segRel;
        static char formatoHora;

    public:
        //Constructores (o inicializadores)
        Hora(const unsigned h = 0, const unsigned m = 0, const unsigned s = 0);
        Hora(const Hora &);

        //Metodos
        void mostrar();

        //Formato
        static const char formatoAmPm; //AM - PM
        static const char formatoLibre; //cualquier formato random
        static const char formato24; //0 a 24
        static void setFormato(char); //Metodo para setear el formato

        //Operadores
        Hora & operator = (const Hora &);
        Hora & operator += (const unsigned);
        Hora operator + (const Hora &)const;
        Hora operator + (const unsigned)const; //Entre hora y unsigned
        friend Hora operator + (const unsigned, const Hora &);
        bool operator > (const Hora &)const;
        bool operator < (const Hora &)const;
        Hora operator ++ (int); //Pos fix, el INT es decorativo. Es para diferenciar.
        Hora & operator ++ (); //Pre fix

        friend ostream & operator << (ostream &salida, const Hora &);
        friend istream & operator >> (istream &entrada, Hora &);

};

#endif // HORA_H_
