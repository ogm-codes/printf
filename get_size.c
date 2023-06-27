#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int index = *i + 1;
	int size = 0;

	if (format[index] == 'l')
	{
		size = LONG;
	}
	else if (format[index] == 'h')
		size = SHORT;

	if (size == 0)
		*i = index - 1;
	else
		*i = index;

	return (size);
}
