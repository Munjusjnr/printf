#include "main.h"

/**
 * pointer - convert and print an unsigned long int in hexadecimal
 * @ptr: the address of the pointer to print
 * @count: the number of bytes printed
 *
 * Description: This function is almost identical to print_lowerHex except
 * it takes an unsigned long int instead of an int.
 *
 * Return: void
 */

void pointer(unsigned long ptr, int *count)
{
	int retVal;

	if (ptr > 15)
		pointer(ptr >> 4, count);

	if (*count == -1)
		return;

	if ((ptr & 15) < 10)
		retVal = _putchar('0' + (ptr & 15));
	else
		retVal = _putchar('a' + (ptr & 15) % 10);

	if (retVal == -1)
		*count = -1;
	else
		*count += retVal;
}

/**
 * print_point - print a pointer address in lowercase hexadecimal format
 * @list: va_list containing the pointer to print as the next element
 *
 * Return: the number of bytes printed
 */

int print_point(va_list list)
{
	int count = 0;
	void *ptr = va_arg(list, void *);

	if (!ptr)
		return (_printf("(nil)"));

	count = _printf("0x");

	if (count == -1)
		return (count);

	pointer((unsigned long) ptr, &count);

	return (count);
}
