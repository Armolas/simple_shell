#include "main.h"

/**
 * child_fail - handles fork fail and frees memory
 * @args: arguments to free
 * @cmd: command argument
 * @is: number of arguments
 * Return: -1
 */
int child_fail(char **args, char *cmd, int is)
{
	perror("fork failed");
	free(cmd);
	free_args(args, is);
	return (-1);
}
