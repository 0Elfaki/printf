#include "main.h"

/**
 * _printf - entry point
 * @format: string formate
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i, len, count = 0;
	char c, *str;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{	i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}

			if (format[i] == 's')
			{
				str = va_arg(args, char*);
				if (str == NULL);
				for (len = 0; str[len] != '\0'; len++)
					;
				write(1, str, len);
				count++;
			}
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				count++;
			}
		}
	}
		va_end(args);
		return (count);
}
