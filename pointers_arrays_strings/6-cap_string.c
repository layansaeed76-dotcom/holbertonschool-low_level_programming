#include "main.h"

/**
 * is_separator - checks if a character separates words
 * @c: the character to check
 *
 * Return: 1 if c is a separator, 0 otherwise
 */
int is_separator(char c)
{
	char seps[] = " \t\n,;.!?\"(){}";
	int i = 0;

	while (seps[i] != '\0')
	{
		if (c == seps[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @str: the string to modify
 *
 * Return: a pointer to str
 */
char *cap_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z' &&
		    (i == 0 || is_separator(str[i - 1])))
			str[i] = str[i] - 32;
		i++;
	}

	return (str);
}
