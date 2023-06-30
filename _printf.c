#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - a printf function
 * @format: format of char
 * Return: c
 */
int _printf(const char *format, ...)
{
	char buff[BUFF_SIZE];
	int width, precision, size, flags, print = 0;
	int i, buffer_count = 0, printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buffer_count++] = format[i];
			if (buffer_count == BUFF_SIZE)
			{
				print_buffer(buff, &buffer_count);
			}
			printed_chars++;
		}
		else
		{
			print_buffer(buff, &buffer_count);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			print = handle_print(format, &i, args, buff, flags, width, precision, size);
			if (print == -1)
				return (-1);

			printed_chars += print;
		}
	}
	print_buffer(buff, &buffer_count);
	va_end(args);

	return (printed_chars);
}
/**
 * print_buffer - prints contents of buffer
 * @buffer: array
 * @buffer_index: index
 * Return: void
 */
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
