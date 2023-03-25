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
	int count = 0;
	va_list args;
	int i;

	va_start(args, format);
	
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
	{
		_putchar(format[i]);
			count++;
			continue;
	}

		i++;

	if (format[i] == '%')
	{
			_putchar('%');
			count++;
				continue;
	}
	if (format[i] == 'c')
	{
		char c = (char)va_arg(args, int);
			_putchar(c);
			count++;
			continue;
	}

	if (format[i] == 's')
		{
			char *str = va_arg(args, char*);
			while (str && *str != '\0')
		{
			_putchar(*str);
			str++;
			count++;
		}
			continue;
		}	
	}
	va_end(args);


	return (count);
}
