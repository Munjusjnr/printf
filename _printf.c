#include "main.h"
/**
 * _printf - printing out anything
 * @format: A pointer to character string
 * Return: print_chars
 */
int _printf(const char *format, ...)
{
	int print_chars;
	conv_t form_list[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_per},
		{"d", print_int},
		{"i", print_int},
		{"b", print_binary},
		{"r", print_rev},
		{"R", rot13},
		{"u", unsigned_int},
		{"o", print_oct},
		{"x", print_hex},
		{"X", print_heX},
		{NULL, NULL}
	};
	va_list prt;

	if (format == NULL)
		return (-1);

	va_start(prt, format);
	/*Calling peep function*/
	print_chars = peep(format, form_list, prt);
	va_end(prt);
	return (print_chars);
}