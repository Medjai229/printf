#include "main.h"

/**
 * printaddr - prints address
 * @ap: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int printaddr(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = conv(n, 16, CONV_UNSIGNED | CONV_LOWCASE, params);
	*--str = 'x';
	*--str = '0';
	return (printnum(str, params));
}