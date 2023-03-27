#include "main.h"

int hexa_check(int, char);

/**
 * print_binary - Converts a number from base 10 to binary
 * @list: List of arguments passed to this function
 * Return: The length of the number printed
 */
int print_binary(va_list list)
{
	unsigned int n;
	int i, length;
	char *str;
	char *rev_str;

	n = va_arg(list, unsigned int);
	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	length = base_length(n, 2);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (-1);

	for (i = 0; n > 0; i++)
	{
		if (n % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		n = n / 2;
	}
	str[i] = '\0';
	rev_str = rev_string(str);
	if (rev_str == NULL)
		return (-1);
	write_base(rev_str);
	free(str);
	free(rev_str);
	return (length);
}

/**
 * print_oct - Prints the numeric representation of a number in octal base
 * @list: List of all the arguments passed to the program
 * Return: Number of symbols printed to stdout
 */
int print_oct(va_list list)
{
	unsigned int v;
	int length;
	char *oct_rep;
	char *rev_str;

	v = va_arg(list, unsigned int);

	if (v == 0)
		return (_putchar('0'));
	if (v < 1)
		return (-1);
	length = base_length(v, 8);

	oct_rep = malloc(sizeof(char) * (length + 1));
	if (oct_rep == NULL)
		return (-1);
	for (length = 0; v > 0; length++)
	{
		oct_rep[length] = (v % 8) + 48;
		v = v / 8;

	}
	oct_rep[length] = '\0';
	rev_str = rev_string(oct_rep);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(oct_rep);
	free(rev_str);
	return (length);
}

/**
 * print_hex - Prints a representation of a decimal number on base16 lowercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_hex(va_list list)
{
	unsigned int n;
	int length;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	n = va_arg(list, unsigned int);

	if (n == 0)
		return (_putchar('0'));
	if (n < 1)
		return (-1);
	length = base_length(n, 16);
	hex_rep = malloc(sizeof(char) * (length + 1));
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; n > 0; length++)
	{
		rem_num = n % 16;
		if (rem_num > 9)
		{
			rem_num = hexa_check(rem_num, 'x');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;
		n = n / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}


/**
 * print_heX - Prints a representation of a decimal number on base16 Uppercase
 * @list: List of the arguments passed to the function
 * Return: Number of characters printed
 */
int print_heX(va_list list)
{
	unsigned int b;
	int length;
	int rem_num;
	char *hex_rep;
	char *rev_hex;

	b = va_arg(list, unsigned int);

	if (b == 0)
		return (_putchar('0'));
	if (b < 1)
		return (-1);
	length = base_length(b, 16);
	hex_rep = malloc(sizeof(char) * (length + 1));
	if (hex_rep == NULL)
		return (-1);
	for (length = 0; b > 0; length++)
	{
		rem_num = b % 16;
		if (rem_num > 9)
		{
			rem_num = hexa_check(rem_num, 'X');
			hex_rep[length] = rem_num;
		}
		else
			hex_rep[length] = rem_num + 48;
		b = b / 16;
	}
	hex_rep[length] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
		return (-1);
	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);
	return (length);
}

/**
 * hexa_check - Checks which hex function is calling it
 * @num: Number to convert into letter
 * @x: Tells which hex function is calling it
 * Return: Ascii value for a letter
 */
int hexa_check(int num, char x)
{
	char *hexa = "abcdef";
	char *Hexa = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hexa[num]);
	else
		return (Hexa[num]);
	return (0);
}
