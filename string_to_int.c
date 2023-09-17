#include "main.h"
/**
 * string_to_int - converts string to integer
 * @str: string input
 * Return: integer
 */

int string_to_int(char *str)
{
	int c, len, i = 0, sum = 0;

	len = str_len(str);
	while (str[i])
	{
		c = str[i] - '0';
		sum += (c * _pow_recursion(10, len - 1 - i));
		i++;
	}
	return (sum);
}
