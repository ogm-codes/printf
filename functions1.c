#include "main.h"

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{}

int print_hexa(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{}

int print_hexa_upper(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{}

int print_octal(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{}

int print_unsigned(va_list types, char buffer[],
        int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
}
