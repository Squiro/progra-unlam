#include "Reloj.h"


int main()
{
    Reloj r1;
    cout << ">>RELOJ R1<<"<<endl;
    r1.que_hora_es();
    Reloj r2(23,10,5,"L");
    r2.escribe_en_12h();
    cout << ">>RELOJ R2<<"<<endl;
    r2.que_hora_es();
    r2.escribe_en_24h(); //debe modificar el Reloj de 0 a 24hs con formato L
    r2.que_hora_es();
    cout << ">>RELOJ R3<<"<<endl;
    Reloj r3(12,35,5,"PM");
    r3.escribe_en_12h(); //debe modificar el Reloj de 0 a 12hs con formato AM/PM Segun Corresponda
    r3.que_hora_es();
    r3.adelantar_reloj(10); // solo se pide adelantar 10 segundos a este reloj, no validar.
    r3.escribe_en_24h();
    r3.que_hora_es();
    Reloj r4(r3);
    cout << ">>RELOJ R4<<"<<endl;
    cout << r4;
    cout << r4.escribe_en_12h();
    return 0;
}
