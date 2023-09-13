#include "main.h"
/**
 * str_len - returns the length of a string
 * @str: the string
 * Return: the length of str
 */
int str_len(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
