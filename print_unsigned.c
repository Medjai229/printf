#include "main.h"

/**
 * printuns - prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int printuns(va_list ap, params_t *params)
{
	unsigned long l;

	if (params->l_modifier)
		l = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(ap, unsigned int);
	else
		l = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (printnum(conv(l, 10, CONV_UNSIGNED, params), params));
}
