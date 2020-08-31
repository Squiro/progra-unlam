#pragma once
#include <iostream>
#include <tgmath.h>

using namespace std;

//Nombre con inicial en Mayuscula. Abro llave y cierro con ;
class Punto
{
    private: //Atributos privados
        int x;
        int y;

    // /!\ Si creo el constructor parametrizado por defecto, no debo crear el constructor parametrizado, ni el por defecto.
    //Esto es para evitar ambiguedades.

    public:
    //Constructores (o tambien inicializadores, no son lo mismo)
        //Punto(); //Constructor por defecto
        //Punto(const int x, const int y); //int, int //Parametrizado "normal"
        Punto(const int x = 0, const int y = 0); //const int = 0, const int = 0 //Parametrizado por defecto
        Punto(const int x);
        Punto(const Punto &); //Constructor por copia

    //Métodos
        void mostrar();
        void mostrarMultiplicado(int);

    //Operadores
        // /!\ El ampersand & lo usamos cuando retornamos una referencia a un objeto que ya existe, por ej
        //cuando modificamos un objeto.
        Punto & operator = (const Punto &); //Operador de asignacion (=)
        Punto & operator += (const Punto &); //Operador +=
        Punto & operator -= (const Punto &); //Operador -=
        Punto operator + (const Punto &)const; //El primer const es del objeto llamado, el segundo es del objeto llamador
        Punto operator - (const Punto &)const;
        Punto operator + (const int)const; //Operador + enteros
        Punto operator - (const int)const; //Operador - enteros
        friend Punto operator + (const int, const Punto &); //ASEGURA la conmutatividad de la suma con enteros :)
        friend Punto operator - (const int, const Punto &);
        Punto operator ++ (int); //Post Fix
        Punto & operator ++ (); //Pre Fix, asigna y aumenta
        bool operator == (const Punto &)const;
        bool operator > (const Punto &)const;

    //Get y Set
        int getX();
        int getY();
        void setX(int);
        void setY(int);

};
