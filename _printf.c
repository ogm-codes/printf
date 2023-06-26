#include "main.h"

int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int buffer_index, printed_chars = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
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
		}
	}
	flush_buffer(buffer, &buffer_index);
	va_end(args);

	return (printed_chars);
}

void flush_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
	{
		write(1, &buffer[0], *buffer_index);
	}

	*buffer_index = 0;
}
