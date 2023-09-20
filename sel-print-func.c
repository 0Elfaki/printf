#include "main.h"

/**
 * sel_print_func - selects function to perform the operation
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function
 *
 */

int (*sel_print_func(const char *s, int index))(va_list, char *, unsigned int)
{
	print_fun pa[] = {
		{"c", print_chr}, {"s", print_str},
		{"%", print_prg}, {" %", print_prg},
		{"i", print_int}, {"d", print_int},
		{NULL, NULL},
	};

	int i = 0, j = 0, first_index;

	first_index = index;
	while (pa[i].type_arg)
	{
		if (s[index] == pa[i].type_arg[j])
		{
			if (pa[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (pa[i].f);
}

