#include "main.h"
/**
 * _printf - printing out anything
 * @format: A pointer to character string
 * Return: 0 if success
 */
int _printf(const char *format, ...)
{
	int i;

	va_list prt;

	va_start(prt, format);

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
		i++;
		switch (format[i])
		{
		case 'c':
			_putchar(va_arg(prt, int));
			break;
		case 's':
			_puts(va_arg(prt, char *));
			break;
		case '%':
			_putchar('%');
			break;
		default:
			_putchar(format[i]);
			continue;
		}
		}
		else
		{
			_putchar(format[i]);
		}
	i++;
	}
	va_end(prt);
	return (0);
}
