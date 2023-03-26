#include "main.h"

#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing directives
 *
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int printed = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			printed = selector(format, args, printed);
			format++;

		}
		else 
		{
			putchar(*format);
			printed++;
			format++;

		}

	}
	va_end(args);
	return (printed);
}
