#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value, or 0 if there are no numbers
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, result = 0, found = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			if (found)
				break;
			sign = -sign;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			found = 1;
			result = result * 10 - (s[i] - '0');
		}
		else if (found)
			break;
		i++;
	}

	if (sign == 1)
		result = -result;

	return (result);
}
