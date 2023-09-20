#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 *
 */

typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_fun;

int _printf(const char *format, ...);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_chr(va_list args, char *buf, unsigned int ibuf);
int print_str(va_list args, char *buf, unsigned int ibuf);
int (*sel_print_func(const char *s, int index))(va_list, char *, unsigned int);
int id_print_func(const char *s, int index);
unsigned int handl_buff(char *buf, char c, unsigned int ibuf);
int print_buff(char *buf, unsigned int nbuf);
int print_int(va_list args, char *buf, unsigned int ibuf);
int print_bnr(va_list args, char *buf, unsigned int ibuf);
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit);

#endif /* MAIN_H */
