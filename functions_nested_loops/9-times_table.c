cat > 9-times_table.c <<'EOF'
#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int i, j, product;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			product = i * j;

			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');
				if (product < 10)
					_putchar(' ');
			}

			if (product >= 10)
				_putchar('0' + product / 10);
			_putchar('0' + product % 10);
		}
		_putchar('\n');
	}
}

