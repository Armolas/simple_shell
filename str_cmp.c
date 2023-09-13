#include "main.h"
/**
 * str_cmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if equal, else -1
 */
int str_cmp(char *str1, char *str2)
{
	int i = 0;

	if (!str1 && !str2)
		return (0);
	else if (!str1 || !str2)
		return (-1);
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
		{
			i++;
		}
		else
			return (-1);
	}
	if (str1[i] == str2[i])
		return (0);
	return (-1);
}
