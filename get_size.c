#include "main.h"

/**
  * get_size - Calculates the size to cast the argument
  * @format: Formatted string in which to print the arguments
  * @i: List of arguments to be printed.
  * Return: Precision.
  */

int get_size(const char *format, int *i)
{
	/* Increment the index of the format string to check the next character */
	int curr_i = *i + 1;
	int size = 0;

	/* Check if the character after the current index is 'l' */
	if (format[curr_i] == 'l')
		size = S_LONG;
	/* Check if the character after the current index is 'h' */
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	/* If size is still 0, no special size modifier was found */
	if (size == 0)
		/* Adjust the index to the previous character */
		*i = curr_i - 1;
	else
		/* Update the index to the current character */
		*i = curr_i;

	return (size);
}
