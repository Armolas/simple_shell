#include "main.h"

/**
 * inbuilt - executes inbuilt commmands
 * @args: arguments
 * @cmd: command
 * @av: program command
 * @is: number of arguments
 * @exit: exit status
 * Return: 1 or 0
 */
int inbuilt(char **args, char *cmd, char *av, int is, int *exit)
{
	if (str_cmp(args[0], "env") == 0)
	{
		penv(args, is);
		return (0);
	}
	cmd = args[0];
	if (!cmd)
	{
		free_args(args, is);
		return (0);
	}
	args[0] = get_path(cmd);
	if (!args[0])
	{
		*exit = null_arg(args, cmd, av, is);
		return (0);
	}
	return (1);
}
