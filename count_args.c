#include "main.h"
/**
 * count_args - counts the number of strings in an array
 * @args: array of strings
 * Return: number of strings
 */
int count_args(char **args)
{
	int count = 0;

	while(args[count])
	{
		count++;
	}
	return (count);
}
