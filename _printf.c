#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list ap;
	char *p, *start;
	params_t params = PARAM_IN;

	va_start(ap, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		in_parm(&params, ap);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (getf(p, &params)) /* while char at p is flag char */
		{
			p++; /* next char */
		}
		p = getwidth(p, &params, ap);
		p = getprec(p, &params, ap);
		if (getmod(p, &params))
			p++;
		if (!getspec(p))
			sum += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += getprint_func(p, ap, &params);
	}
	_putchar(FLUSH_BUF);
	va_end(ap);
	return (sum);
}

