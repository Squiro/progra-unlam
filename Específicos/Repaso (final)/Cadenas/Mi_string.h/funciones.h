#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <stdio.h>

char * strcpy(char *str1, const char *str2);
char * strncpy(char *str1, const char *str2, unsigned int limit);
char * strcat(char *str1, const char *str2);
char * strncat(char *str1, const char *str2, unsigned int limit);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, unsigned int limit);
char * strchar(char * str, int caracter);
char * strrchar(char * str, int caracter);
char * strstr(char *str, char *str2);
int strlen(const char *str);
int coinciden(char *str, char *str2);


#endif // FUNCIONES_H_
