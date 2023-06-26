#include "main.h"


int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
}

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
}

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{}

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *string = va_arg(types, char *);
	int length = 0;

	UNUSED(buffer);
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);

	if (string == NULL)
        {
                string = "(null)";
                if (precision >= 6)
                        str = "      ";
        }

        while (string[length] != '\0')
                length++;

        if (precision >= 0 && precision < length)
                length = precision;

        if (width > length)
        {
                if (flags & MINUS)
                {
                        write(1, &str[0], length);
                        for (i = width - length; i > 0; i--)
                                write(1, " ", 1);
                        return (width);
                }
                else
                {
                        for (i = width - length; i > 0; i--)
                                write(1, " ", 1);
                        write(1, &str[0], length);
                        return (width);
                }
        }

        return (write(1, str, length));
}

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char chars = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
