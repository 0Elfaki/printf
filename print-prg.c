#include "main.h"
#include <stdio.h>

/**
 * print_prg - writes the character c to stdout
 * @a: input char
 * @buf: buffer pointer
 * @i: index for buffer pointer
 * Return: On success (1)
 */

int print_prg(va_list a, char *buf, unsigned int i)
{
	(void)a;

	handl_buff(buf, '%', i);

	return (1);
}

