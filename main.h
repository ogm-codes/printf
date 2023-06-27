#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int is_digit(char);
int is_print(char);
int append_hexa(char, char[], int);
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
long int convert_size_unsigned(unsigned long int num, int size);

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)

/* Flags */
#define MINUS 1
#define PLUS 2
#define HASH 8
#define SPACE 16
#define ZERO 4

/* Sizesof int */
#define LONG 2
#define SHORT 1

/**
 * struct fmt - Struct fmt
 * @fmt: format specifier
 * @fn: function pointer associated with format specififier
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - represents format specifier
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

/* function specifiers */
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
int print_hexa(va_list types, char buffer[], int flags,
	int width, int precision, int size);

/*Function prints string */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsignd(int is_negative, int ind,
char buffer[], int flags, int width, int precision, int size);

#endif
