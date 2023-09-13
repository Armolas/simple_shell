#include "main.h"
/**
 * get_args - gets arguments from the buffer and stores it into an array
 * @linebuf: the buffer
 * @delim: the delimiter
 * Return: pointer to array of args
 */
char **get_args(char *linebuf, char *delim)
{
	int i = 0, count = 1;
	char **args;
	char *arg;

	while (linebuf[i])
	{
		if (linebuf[i] == ' ')
			count++;
		i++;
	}
	i = 0;
	count++;
	args = malloc(sizeof(char *) * count);
	arg = strtok(linebuf, delim);
	while(arg)
	{
		args[i] = str_dup(arg);
		arg = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;
	return (args);
}
