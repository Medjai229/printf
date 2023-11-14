#include "main.h"

/**
 * getprint_func - finds the format func
 * @s: the format string
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: the number of bytes printed
 */
int getprint_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = getspec(s);

	if (f)
		return (f(ap, params));
	return (0);
}