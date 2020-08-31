#include "bulto.h"
#include "producto.h"

char * Bulto :: concatenar(const char * bultDesc, const char * prodDesc)
{
    if (bultDesc && *bultDesc)
    {
        try
        {
            char * aux = new char[strlen(bultDesc)+strlen(prodDesc)+1];
            strcpy(aux, bultDesc);
            //*(aux+(strlen(bultDesc)+1)) = '|';
            strcat(aux, "|\0");
            strcat(aux, prodDesc);
            return aux;
        }
        catch (bad_alloc &error)
        {
            cerr << "Error: " << error.what();
        }
    }
    return NULL;
}

Bulto :: Bulto(char * desc, const int volumen)
{
    this->desc = desc;
    this->volumen = volumen;
}

Bulto Bulto :: operator + (Producto &prod)const
{
    return Bulto(concatenar(this->desc, prod.getDesc()), prod.volumen() + this->volumen);
}

char * Bulto :: getDesc()
{
    return this->desc;
}

int Bulto :: getVol()
{
    return this->volumen;
}

Bulto :: ~Bulto()
{
    delete []desc;
}
 ostream & operator << (ostream &sal, const Bulto &obj)
 {
     sal << obj.desc << " " << obj.volumen;

     return sal;
 }
