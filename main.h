#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>

#include <stdarg.h>

int _putchar(char c);
int print_int(va_list arg);
int print_number(va_list);
int print_unsigned(va_list arg);
int _printf(const char *format, ...);
int print_char(va_list arg);
int print_str(va_list arg);
int print_percent(va_list);
int print_binary(va_list);
unsigned int base_len(unsigned int, int);
char *rev_string(char *);
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);

/**
 * struct identifierStruct - structure definition of a printTypeStruct
 * @indentifier: type
 * @printer: function to print
 */
typedef struct identifierStruct
{
	char *indentifier;
	int (*printer)(va_list);
} identifierStruct;

#endif
