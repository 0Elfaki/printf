#include "main.h"

/**
 * print_buff - prints buffer
 * @buf: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buff(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}
