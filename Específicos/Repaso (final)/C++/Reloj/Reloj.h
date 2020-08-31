#ifndef RELOJ_H_
#define RELOJ_H_

#include <iostream>

using namespace std;

class Reloj
{
    private: int h,
                m,
                s;
            char *formato;

    public:
        //Constructores
        Reloj(const int h = 0, const int m = 0, const int s = 0, const char * formato = "AM");

        //Destructor
        ~Reloj();

        //Métodos
        void que_hora_es();
        Reloj & escribe_en_12h();
        void escribe_en_24h();
        Reloj & adelantar_reloj(const int num);
        friend ostream & operator << (ostream &salid, const Reloj &obj);


};

#endif // RELOJ_H_
