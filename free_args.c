#include "main.h"
/**
 * free_args - frees an array of strings
 * @args: array to free
 */
void free_args(char **args)
{
	int i = 0;

	if (args == NULL)
		return;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	return;
}
