#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int is_digit(char);
int is_print(char);
int append_hexa(char, char[], int);

#define BUFF_SIZE 1024

/* Sizesof int */
#define LONG 2
#define SHORT 1

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

/* Print chars and string */
int print_string(va_list type, char buffer[], int flag,
	int width, int precision, int size);

#endif
