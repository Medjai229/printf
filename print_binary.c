#include "main.h"

/**
 * printbin - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int printbin(va_list ap, params_t *params)
{
	unsigned int n = va_arg(ap, unsigned int);
	char *str = conv(n, 2, CONV_UNSIGNED, params);
	int c = 0;

	if (params->hashtag_flag && n)
		*--str = '0';
	params->unsign = 1;
	return (c += printnum(str, params));
}