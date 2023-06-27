#include "main.h"
/**
 * get_size - Retrieves size modifier from format string
 * @format: string format to search for size modifier.
 * @i: pointer to current index
 * Return: value corresponding to size modifier
 */
int get_size(const char *format, int *i)
{
	int index = *i + 1;
	int size = 0;

	if (format[index] == 'l')
		size = LONG;
	else if (format[index] == 'h')
		size = SHORT;

	if (size == 0)
	{
		*i = index - 1;
	}
	else
	{
		*i = index;
	}

	return (size);
}
