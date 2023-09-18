#include "main.h"

/**
 * null_arg - prints error for wrong command
 * @args: command arguments
 * @cmd: command
 * @av: program command
 * @is: number of arguments
 * Return: exit status
 */
int null_arg(char **args, char *cmd, char *av, int is)
{
	p_error(av);
	p_error(": 1: ");
	p_error(cmd);
	p_error(": not found\n");
	free(cmd);
	free_args(args, is);
	return (127);
}
