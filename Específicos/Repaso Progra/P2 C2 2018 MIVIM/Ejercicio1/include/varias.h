#ifndef VARIAS_H_INCLUDED
#define VARIAS_H_INCLUDED

#define TAM_MENU 32

void fin_anormal(char *);
void pausa(char *);
char menu(const char m[][TAM_MENU], const char *tit);
char pedir_opcion(const char m[][TAM_MENU], const char * tit, const char * msj);


#endif // VARIAS_H_INCLUDED
