#include "main.h"

void flush_buffer(char buffer[], int *buffer_index);

/**
 * _printf - a custom printf function
 * @format: char to be printed
 * Return: printed_chars
 */
int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int buffer_index, printed_chars = 0;
	int size, width, precision, flags, print = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (int i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER_SIZE)
			{
				flush_buffer(buffer, &buffer_index);
			}
			printed_chars++;
		}
		else
		{
			flush_buffer(buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			print = handle_print(format, &i, args, buffer,
				flags, width, precision, size);
			if (print == -1)
				return (-1);

			printed_chars += print;
		}
	}
	flush_buffer(buffer, &buffer_index);
	va_end(args);

	return (printed_chars);
}
/**
 * flush_buffer - flushes buffer by writing to standard output
 * @buffer: contains data to be flushed
 * @buffer_index: idicates current position in the buffer
 * Return: void function
 */
void flush_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, &buffer[0], *buffer_index);
	}

	*buffer_index = 0;
}
