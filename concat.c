#include "main.h"
/**
 * concat - concatenates two strings
 * @str1: first string
 * @str2: second string
 * Return: pointer to new string
 */
char *concat(char *str1, char *str2)
{
	int i = 0 , j = 0;
	char *new;

	if (!str1 && str2)
		return (str2);
	else if (str1 && !str2)
		return (str1);
	else if (!str1 && !str2)
		return (NULL);
	new = malloc(str_len(str1) + str_len(str2) + 1);
	if (!new)
		return (NULL);
	while (str1 && str1[i])
	{
		new[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
	{
		new[i] = str2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
