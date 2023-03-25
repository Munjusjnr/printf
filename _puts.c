#include "main.h"

int _puts(const char *str)
{
	int i = 0;
	while (str[i] != '\0')
        {
		_putchar(str[i]);
		i++;
	}
	return (i);
}
