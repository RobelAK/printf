#include "main.h"

/**
  * get_width - Calculates the width for printing
  * @format: Formatted string in which to print the arguments.
  * @i: List of arguments to be printed.
  * @list: List of arguments.
  * Return: Width.
  */

int get_width(const char *format, int *i, va_list list)
{
	int curr_i; /* Index for iterating through the format string. */
	int width = 0; /* Initialize the width to 0. */

	/* Loop through the characters in the format string. */
	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		/* If the current character is a digit (0-9). */
		if (is_digit(format[curr_i]))
		{
			/* Multiply the existing width by 10 (to shift digits left). */
			width *= 10;

			/* Add the numerical value of the digit to the width. */
			width += format[curr_i] - '0';
		}
		/* If the current character is '*'. */
		else if (format[curr_i] == '*')
		{
			curr_i++;
			/* Get the width from the variable arguments list. */
			width = va_arg(list, int);

			break; /* Exit the loop, as width has been determined. */
		}
		else
		{
			/* If neither digit nor '*', exit the loop. */
			break;
		}
	}

	/* Update the index 'i' with the last processed character index. */
	*i = curr_i - 1;

	return (width);
}
