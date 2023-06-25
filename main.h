#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int is_digit(char);
int is_print(char);
int append_hexa(char, char[], int);

int _printf(const cahr *format, ...);
void print_buffer(char buffer[], int *buff_index);

#define BUFF_SIZE 1024

/* Sizesof int */
#define LONG 2
#define SHORT 1

int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_width(const char *format, int *i, va_list list);

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

/* Print chars and string // */
int print_string(va_list type, char buffer[], int flag,
	int width, int precision, int size);
int print_char(va_list type, char buffer[], int flag,
        int width, int precision, int size);
int print_percent(va_list type, char buffer[], int flag,
        int width, int precision, int size);

#endif
