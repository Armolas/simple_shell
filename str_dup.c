#include "main.h"
/**
 * str_dup - dulicates a string in memory
 * @str: string to duplicate
 * Return: pointer to new string
 */
char *str_dup(char *str)
{
	char *dup;
	int i;

	if (!str)
		return (NULL);
	for (i = 0 ; str[i] ; i++)
		;
	dup = malloc(sizeof(char) * (i + 1));
	if (!dup)
		return (NULL);
	for (i = 0 ; str[i] ; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';
	return (dup);
}
