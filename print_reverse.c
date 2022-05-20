#include "main.h"

int print_rev(va_list list)
{
    char *rev;
    char *s;
    int i = 0;

    s = va_arg(list, char *);
    rev = rev_string(s);

    for (i = 0; rev[i] != '\0'; i++)
	{
        _putchar(rev[i]);
    }
    _putchar('\n');
    return (0);
}