#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int is_digit(char);
int is_print(char);
int append_hexa(char, char[], int);

/* Print numbers */
int print_int(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags,
	int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags,
        int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags,
        int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags,
        int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags,
        int width, int precision, int size);

#endif
