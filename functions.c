#include "main.h"

/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}

	return (count);
}

/**
 * print_int - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;

	int is_negative = 0;

	unsigned int long num;

	long int n = va_arg(types, long int);

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned int long)n;

	if (n < 0)
	{
		num = (unsigned int long)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));

}

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	UNUSED(buffer);

	return (write(1, "%%", 1));
}

/**
 * print_string - Prints an unsigned string
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *string = va_arg(types, char *);
	int length = 0, c;

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);

	if (string == NULL)
	{
		string = "(null)";
		if (precision >= 6)
			string = "      ";
	}

	while (string[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & MINUS)
		{
			write(1, &string[0], length);
			for (c = width - length; c > 0; c--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (c = width - length; c > 0; c--)
				write(1, " ", 1);
			write(1, &string[0], length);
			return (width);
		}
	}
	return (write(1, string, length));
}

/**
 * print_char - Prints an unsigned char
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char chars = va_arg(types, int);

	return (handle_write_char(chars, buffer, flags, width, precision, size));
}
