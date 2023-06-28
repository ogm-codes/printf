#include "main.h"

/**
 * get_flags - gets flags from the format
 * @format: where to search for flags
 * @i: pointer to index in format
 * Return: flag value that matches flag character found
 */
int get_flags(const char *format, int *i)
{
	int flag, c, index = 0;
	const char ASTERISKS[] = {'+', '-', '0', '#', ' ', '\0'};
	const int FLAGS[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (index = *i + 1; format[index] != '\0'; index++)
	{
		for (c = 0; FLAGS[c] != '\0'; c++)
		{
			if (format[index] == ASTERISKS[c])
			{
				flag |= FLAGS[c];
				break;
			}

			if (ASTERISKS[c] == 0)
				break;
		}
	}
		*i = index - 1;
		return (flag);
}
