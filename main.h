#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define SIZE_BUF 1024
#define FLUSH_BUF -1


#define NULL_STR "(null)"

#define PARAM_IN {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONV_LOWCASE	1
#define CONV_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c module */
int printc(va_list ap, params_t *params);
int printi(va_list ap, params_t *params);
int prints(va_list ap, params_t *params);
int printp(va_list ap, params_t *params);
int printS(va_list ap, params_t *params);

/* number.c module */
char *conv(long int num, int base, int flags, params_t *params);
int printuns(va_list ap, params_t *params);
int printaddr(va_list ap, params_t *params);

/* specifier.c module */
int (*getspec(char *s))(va_list ap, params_t *params);
int getprint_func(char *s, va_list ap, params_t *params);
int getf(char *s, params_t *params);
int getmod(char *s, params_t *params);
char *getwidth(char *s, params_t *params, va_list ap);

/* conv_number.c module */
int printhex(va_list ap, params_t *params);
int printHEX(va_list ap, params_t *params);
int printbin(va_list ap, params_t *params);
int printoct(va_list ap, params_t *params);

/* simple_printers.c module */
int print_from_to(char *start, char *stop, char *except);
int printrev(va_list ap, params_t *params);
int printrot13(va_list ap, params_t *params);

/* printnum.c module */
int _isdigit(int c);
int _strlen(char *s);
int printnum(char *str, params_t *params);
int printnum_right_shift(char *str, params_t *params);
int printnum_left_shift(char *str, params_t *params);

/* params.c module */
void in_parm(params_t *params, va_list ap);

/* string_fields.c modoule */
char *getprec(char *p, params_t *params, va_list ap);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif /*MAIN_H*/
