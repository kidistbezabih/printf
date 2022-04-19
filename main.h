#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);
int print_int(va_list arg);
int print_unsigned(va_list arg);
int _printf(const char *format, ...);


typedef struct identifierStruct
{
char *identifier;
int (*printer)(va_list);
} identifierStruct;


#endif