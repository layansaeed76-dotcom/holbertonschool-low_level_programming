#include "main.h"
#include <stdio.h>

/**
 * print_array - print an array of integers
 * @a: an array of integers
 * @n: the number of elements to swap
 *
 * Return: nothing.
 */
void print_array(int *a, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (i != 0)
		{
			printf(", ");
		}
		printf("%d", a[i]);
		i++;
	}
	printf("\n");
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int a[] = {0, 1, 2, 3, 4, 98, 402, 1024, 1337};

	print_array(a, sizeof(a) / sizeof(a[0]));
	reverse_array(a, sizeof(a) / sizeof(a[0]));
	print_array(a, sizeof(a) / sizeof(a[0]));
	return (0);
}
