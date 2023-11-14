#include "main.h"

/**
 * getspec - finds the format func
 * @s: the format string
 *
 * Return: the number of bytes printed
 */
int (*getspec(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", printc},
		{"d", printi},
		{"i", printi},
		{"s", prints},
		{"%", printp},
		{"b", printbin},
		{"o", printoct},
		{"u", printuns},
		{"x", printhex},
		{"X", printHEX},
		{"p", printaddr},
		{"S", printS},
		{"r", printrev},
		{"R", printrot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}