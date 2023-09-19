#include "main.h"

/**
 * id_print_func - returns the amount of identifiers.
 * @s: argument indentifier
 * @index: index of argument identifier.
 * Return: amount of identifiers.
 */

int id_print_func(const char *s, int index)
{
	print_fun pa[] = {
		{"c", print_chr}, {"s", print_str},
		{"%", print_prg}, {"l", print_prg}, {" %", print_prg},
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
	return (j);
}

