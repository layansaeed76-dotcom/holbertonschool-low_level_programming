#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times the character \ should be printed
 *
 * Return: Nothing.
 */
void print_diagonal(int n)
{
	int line, space;

	for (line = 0; line < n; line++)
	{
		for (space = 0; space < line; space++)
			_putchar(' ');
		_putchar('\\');
		if (line < n - 1)
			_putchar('\n');
	}
	_putchar('\n');
}
