#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n: number to check
 *
 * Return: the last digit of n
 */
int print_last_digit(int n)
{
	int digit;

	digit = n % 10;
	if (digit < 0)
		digit = -digit;

	_putchar('0' + digit);
	return (digit);
}
