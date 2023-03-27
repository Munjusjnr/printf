#include "main.h"
/**
* print_String - prints non-printable character in hex
* @list: list of functions
* Return: 0
*/

int print_String(va_list list)
{
	const char *hex = "0123456789ABCDEF";
	int i = 0;
	char *string;

	string = va_arg(list, char *);
	if (string == NULL)
	{
		string = "(null)";
	}
	while (string[i] != '\0')
	{
		if (string[i] < 32 || string[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			_putchar(hex[(string[i] >> 4) & 0xF]);
			_putchar(hex[string[i] & 0xF]);
		}
		else
		{
			_putchar(string[i]);
		}
		i++;
	}

	return (0);
}
