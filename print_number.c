#include "main.h"

/**
 * printnum - prints a number with options
 * @str: the base number as a string
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int printnum(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_flag)
		return (printnum_right_shift(str, params));
	else
		return (printnum_left_shift(str, params));
}
