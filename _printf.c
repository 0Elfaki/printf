#include "main.h"

/**
 * _printf - formatted output.
 * @format: input string.
 *
 * Return: number of chars printed.
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list args;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(args, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buff(buffer, ibuf), free(buffer), va_end(args);
				return (-1);
			}
			else
			{	function = sel_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buff(buffer, format[i], ibuf), len++, i--;
				}
				else
				{
					len += function(args, buffer, ibuf);
					i += id_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buff(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buff(buffer, ibuf), free(buffer), va_end(args);
	return (len);
}

