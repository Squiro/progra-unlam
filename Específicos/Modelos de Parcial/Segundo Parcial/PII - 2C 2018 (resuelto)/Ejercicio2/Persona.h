#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

class Persona
{
  private:
    unsigned int dni;
    char *apyn;
    char sex;

  public:
    //En vez de un null, podemos reservar un caracter y poner '\0' (reservar 1 byte)
    //Asi en el cout evitamos deeee e e e  preguntar si es nulo
    Persona(const unsigned int dni = 0, const char * apyn = NULL, const char sex = 'A');
    Persona(const Persona &); //Te falto un const, aca.
    ~Persona();

    //Operadores
    bool operator == (const Persona &)const;
    Persona & operator = (const Persona &);
    friend ostream & operator << (ostream &, const Persona &);
    friend istream & operator >> (istream &, Persona &);
};

#endif // PERSONA_H_INCLUDED
