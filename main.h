#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

struct conv
{
	char *sym;
	int (*f)(va_list);
};
typedef struct conv conv_t;

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(const char *str);
int _printfo(const char* format, ...);
int peep(const char *format, conv_t form_list[], va_list prt);
int print_char(va_list list);
int print_str(va_list list);
int print_per(__attribute__((unused))va_list list);
int print_int(va_list list);
int unsigned_int(va_list list);
int print_number(va_list args);
int print_unsigned_num(unsigned int n);
#endif
