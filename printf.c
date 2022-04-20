#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
*printIdentifiers - print special characters
*@next: character after %
*@arg: argument for the identifier
*Return: the number of characters prited
*
*/

int printIdentifiers(char next, va_list arg)
{
	int functsIndex;
	identifierStruct functs[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{NULL, NULL}
	};

	for (functsIndex = 0; functs[functsIndex].indentifier != NULL; functsIndex++)
	{
		if (functs[functsIndex].indentifier[0] == next)
			return (functs[functsIndex].printer(arg));
	}
	return (0);
}

/**
*_printf - print output accorfing to the format
*@format: character String
*Return: number of characters printed or -1 for incomplete identifiers
*/
int _printf(const char *format, ...)
{
	unsigned int i;
	int identifierPrinted = 0, charPrinted = 0;
	va_list arg;

	va_start(arg, format);
	if (format == NULL)
	{
		return (-1);
	}

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			charPrinted++;
			continue;
		}

		if (format[i] == '\0')
			return (-1);

		identifierPrinted = printIdentifiers(format[i + 1], arg);

		if (identifierPrinted == -1 || identifierPrinted != 0)
			i++;

		if (identifierPrinted > 0)
			charPrinted += identifierPrinted;

		if (identifierPrinted == 0)
		{
			_putchar('%');
			charPrinted++;
		}
	}

	va_end(arg);
	return (charPrinted);
}
