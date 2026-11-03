#include <stdio.h>

/**
 * main - Prints single digit numbers separated by commas
 *
 * Return: Always 0
 */
int main(void)
{
	int number;

	for (number = 0; number <= 9; number++)
	{
		if (number > 0)
		{
			putchar(',');
			putchar(' ');
		}
		putchar(number + '0');
	}
	putchar('\n');

	return (0);
}
