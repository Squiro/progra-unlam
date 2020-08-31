#include "Persona.h"

char * copiarCadena(const char * cad)
{
    if (cad && *cad)
    {
        try
        {
            //cout << "ACA: " << cad << endl;
            char * aux = new char[strlen(cad)+1];
            strcpy(aux, cad);
            return aux;
        }
        catch (bad_alloc &error)
        {
            cerr << "Error: " << error.what();
        }
    }
    return NULL;
}

Persona :: Persona(const unsigned int dni, const char * apyn, const char sex)
{
    this->dni = dni;
    this->apyn = copiarCadena(apyn);
    if (this->apyn == NULL && apyn && *apyn)
        cerr << "SIN MEMORIA" << endl;
    this->sex = sex;
}

Persona :: Persona(const Persona &per)
{
    this->dni = per.dni;
    this->apyn = copiarCadena(per.apyn);
    if (this->apyn == NULL && apyn && *apyn)
        cerr << "SIN MEMORIA" << endl;
    this->sex = per.sex;
}

Persona :: ~Persona()
{
    delete []apyn;
}

Persona & Persona :: operator = (const Persona &obj)
{
    this->dni = obj.dni;
    this->sex = obj.sex;
    this->apyn = copiarCadena(obj.apyn);

    return *this;
}

bool Persona :: operator == (const Persona &per)const
{
    return this->dni == per.dni && strcmp(this->apyn, per.apyn) == 0 && this->sex == per.sex;
}

ostream & operator << (ostream &salida, const Persona &per)
{
    salida << " DNI: " << per.dni << " Nombre: " << (per.apyn ? per.apyn : "Sin nombre") << " Sexo: " << per.sex;

    return salida;
}

istream & operator >> (istream &entrada, Persona &per)
{
    char aux[256];
    cout << "Ingrese el nombre: ";
    entrada >> aux;
    per.apyn = copiarCadena(aux);
    if (per.apyn == NULL && *aux)
        cerr << "SIN MEMORIA" << endl;
    cout << "Ingrese el dni: ";
    entrada >> per.dni;
    cout << "Ingrese el sexo: ";
    entrada >> per.sex;

    return entrada;
}
