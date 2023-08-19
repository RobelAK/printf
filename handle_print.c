#include "main.h"

/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;

	/* Array of format types and their corresponding print functions */
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	/* Loop through the format types array to find a matching format character */
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
		{
			/* Call the corresponding print function for the format type */
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
		}
	}

	/* If the loop doesn't find a matching format character */
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
		{
			/* If the format string ends, return -1 to signal completion */
			return (-1);
		}

		unknow_len += write(1, "%%", 1);

		if (fmt[*ind - 1] == ' ')
		{
			/* Print a space if the previous character was a space */
			unknow_len += write(1, " ", 1);
		}
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
			{
				--(*ind);
			}
			if (fmt[*ind] == ' ')
			{
				--(*ind);
			}
			return (1);
		}

		/* Print the current character */
		unknow_len += write(1, &fmt[*ind], 1);

		/* Return the total characters printed */
		return (unknow_len);
	}

	/* Return the number of characters printed */
	return (printed_chars);
}
